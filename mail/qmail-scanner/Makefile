# New ports collection makefile for:   qmail-scanner
# Date created:	       2003-08-24
# Whom:                moeti
#
# $FreeBSD$
#

PORTNAME=	qmail-scanner
PORTVERSION=	1.20
PORTREVISION=	1
CATEGORIES=	mail security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	freebsd@simplerezo.com
COMMENT=	Content/Anti-virus Scanner for qmail

BUILD_DEPENDS=	${QMAIL_QUEUE}:${PORTSDIR}/mail/qmail \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		reformime:${PORTSDIR}/mail/maildrop

# A normal qmail installation puts everything into /var/qmail/.
# Must match your qmail installation
QMAIL_DIR?=	/var/qmail
QMAIL_QUEUE=	${QMAIL_DIR}/bin/qmail-queue

USE_PERL5=	yes
NO_BUILD=	yes

# Barely optionnal
.if !defined(WITHOUT_TNEF)
BUILD_DEPENDS+=	${LOCALBASE}/bin/tnef:${PORTSDIR}/converters/tnef
.endif

# Options
QMAILSCAN_ADMIN?=	root
.if defined(QMAILSCAN_ADMINREALNAME)
CONFIGURE_ARGS+=	--admin-realname "${QMAILSCAN_ADMINREALNAME}"
.endif
QMAILSCAN_NOTIFY?=	sender,recips
.if defined(QMAILSCAN_LOCALDOMAINS)
CONFIGURE_ARGS+=	--local-domains "${QMAILSCAN_LOCALDOMAINS}"
.endif
.if defined(QMAILSCAN_SCANNERS)
CONFIGURE_ARGS+=	--scanners "${QMAILSCAN_SCANNERS}"
.else
CONFIGURE_ARGS+=	--scanners auto
.endif
.if defined(QMAILSCAN_SPAMSREDIRECT)
CONFIGURE_ARGS+=	--spams-redirect "${QMAILSCAN_SPAMSREDIRECT}"
.endif
.if defined(QMAILSCAN_SPAMSTOSUFFIX)
CONFIGURE_ARGS+=	--spams-tosuffix "${QMAILSCAN_SPAMSTOSUFFIX}"
.endif

SPOOLDIR=	${PREFIX}/qmailscan
PLIST_SUB=	SPOOLDIR="${SPOOLDIR:S,${PREFIX}/,,}"

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	\
		--qmaildir ${QMAIL_DIR} --spooldir ${SPOOLDIR} \
		--bindir ${PREFIX}/bin --qmail-queue-binary ${QMAIL_QUEUE} \
		--admin "${QMAILSCAN_ADMIN}" --notify "${QMAILSCAN_NOTIFY}" \
		--silent-viruses auto \
		--redundant yes --unzip yes \
		--add-dscr-hdrs yes \
		--fix-mime yes \
		--log-details syslog --debug no \
		--batch

pre-configure:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "----------------------------------------"
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "QMAILSCAN_ADMIN          email adress of qmail-scanner admin for alerts"
	@${ECHO_MSG} "QMAILSCAN_ADMINREALNAME* name to use when sending alerts"
	@${ECHO_MSG} "                         (do not use spaces but underscores here)"
	@${ECHO_MSG} "QMAILSCAN_LOCALDOMAINS   domains classified as local domains preventing alerts"
	@${ECHO_MSG} "                         of externals users (and mailing-lists...)"
	@${ECHO_MSG} "QMAILSCAN_SCANNERS       list of installed content scanner"
	@${ECHO_MSG} "                         default is automatic, so you do not need to set this"
	@${ECHO_MSG} "QMAILSCAN_SPAMSREDIRECT* set this if you want to redirect all spams to a"
	@${ECHO_MSG} "                         specific email address"
	@${ECHO_MSG} "QMAILSCAN_SPAMSTOSUFFIX* suffix to alter spams recipients with"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "When you set the last option to 'spam', a detected spam will be delivered to"
	@${ECHO_MSG} "'user-spam@domain' instead of 'user@domain'."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "* Please note these options are only available with FreeBSD ports "
	@${ECHO_MSG} "So please, do not report relatives bugs to qmail-scanner team, but maintainer."
	@${ECHO_MSG} "----------------------------------------"
	@${ECHO_MSG} ""
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} PRE-INSTALL
	@if ! ${TEST} -f ${QMAIL_QUEUE}; then \
		@${ECHO_MSG} "Unable to found qmail-queue binary trying '${QMAIL_QUEUE}'.";  \
		@${ECHO_MSG} "Please set QMAIL_DIR to your qmail installation directory !"; \
		exit 1; \
	fi

do-install:
	-${TEST} -f ${PREFIX}/bin/qmail-scanner-queue.pl && \
		${MV} ${PREFIX}/bin/qmail-scanner-queue.pl \
			${PREFIX}/bin/qmail-scanner-queue.pl.old
	${INSTALL_SCRIPT} ${WRKSRC}/qmail-scanner-queue.pl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/qs2mrtg.pl ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/quarantine-attachments.txt \
		${SPOOLDIR}/quarantine-attachments.sample
	${TEST} -f ${SPOOLDIR}/quarantine-attachments.txt || \
		${INSTALL_DATA} ${WRKSRC}/quarantine-attachments.txt ${SPOOLDIR}
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

post-deinstall:
	@${ECHO_MSG}
	@${ECHO_MSG} "If you're not updating this port, you can delete directory '${SPOOLDIR}'."
	@${ECHO_MSG} ""

test:
	@${WRKSRC}/contrib/test_installation.sh -doit

.include <bsd.port.mk>
