# New ports collection makefile for:   qmail-scanner
# Date created:	       2003-08-24
# Whom:                moeti
#
# $FreeBSD$
#

PORTNAME=	qmail-scanner
PORTVERSION=	1.20
CATEGORIES=	mail security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	freebsd@simplerezo.com
COMMENT=	Content/Anti-virus Scanner for qmail

# A normal qmail installation puts everything into /var/qmail/.
# Must match your qmail installation
QMAIL_DIR?=	/var/qmail

BUILD_DEPENDS=	${QMAIL_DIR}/bin/qmail-queue:${PORTSDIR}/mail/qmail \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		reformime:${PORTSDIR}/mail/maildrop

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
		--qmaildir ${QMAIL_DIR} --spooldir ${SPOOLDIR} --bindir ${PREFIX}/bin \
		--admin "${QMAILSCAN_ADMIN}" --notify "${QMAILSCAN_NOTIFY}" \
		--silent-viruses auto \
		--redundant yes --unzip yes \
		--add-dscr-hdrs yes \
		--fix-mime yes \
		--log-details syslog --debug no \
		--batch

pre-configure:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} PRE-INSTALL

do-install:
	-${TEST} -f ${PREFIX}/bin/qmail-scanner-queue.pl && \
		${MV} ${PREFIX}/bin/qmail-scanner-queue.pl \
			${PREFIX}/bin/qmail-scanner-queue.pl.old
	${INSTALL_SCRIPT} ${WRKSRC}/qmail-scanner-queue.pl ${PREFIX}/bin
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
