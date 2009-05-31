# New ports collection makefile for:   qmail-scanner
# Date created:	       2003-08-24
# Whom:                moeti
#
# $FreeBSD$
#

PORTNAME=	qmail-scanner
PORTVERSION=	1.25
PORTREVISION=	2
CATEGORIES=	mail security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Content/Anti-virus Scanner for qmail

BUILD_DEPENDS=	reformime:${PORTSDIR}/mail/maildrop \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

MANUAL_PACKAGE_BUILD=	Requires qmail built with non-standard setting

NO_LATEST_LINK=	yes
CONFLICTS=	qmail-scanner-2.*

QMAIL_QUEUE=	${QMAIL_PREFIX}/bin/qmail-queue

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
.if defined(QMAILSCAN_ARCHIVE)
CONFIGURE_ARGS+=	--archive yes
.endif
QMAILSCAN_NOTIFY?=	psender,precips
.if defined(QMAILSCAN_LANG)
CONFIGURE_ARGS+=	--lang "${QMAILSCAN_LANG}"
.endif
.if defined(QMAILSCAN_LOCALDOMAINS) && !empty(QMAILSCAN_LOCALDOMAINS)
CONFIGURE_ARGS+=	--local-domains "${QMAILSCAN_LOCALDOMAINS}"
.endif
.if defined(QMAILSCAN_LOGCRYPTO)
CONFIGURE_ARGS+=	--log-crypto yes
.endif
.if defined(QMAILSCAN_NOTUNZIP)
CONFIGURE_ARGS+=	--unzip no
.else
CONFIGURE_ARGS+=	--unzip yes
.if defined(QMAILSCAN_MAXZIPSIZE)
CONFIGURE_ARGS+=	--max-zip-size "${QMAILSCAN_MAXZIPSIZE}"
.endif
.if !defined(QMAILSCAN_NOTBLKZIPPW)
BUILD_DEPENDS+=		unzip:${PORTSDIR}/archivers/unzip
CONFIGURE_ARGS+=	--block-password-protected yes
.endif
.endif
.if defined(QMAILSCAN_SCANNERS)
CONFIGURE_ARGS+=	--scanners "${QMAILSCAN_SCANNERS}"
.else
CONFIGURE_ARGS+=	--scanners auto
.endif
QMAILSCAN_SILENTVIRUSES?=	auto
.if defined(QMAILSCAN_SPAMSREDIRECT)
CONFIGURE_ARGS+=	--spams-redirect "${QMAILSCAN_SPAMSREDIRECT}"
.endif
.if defined(QMAILSCAN_SPAMSTOSUFFIX)
CONFIGURE_ARGS+=	--spams-tosuffix "${QMAILSCAN_SPAMSTOSUFFIX}"
.endif

RUN_DEPENDS=	${BUILD_DEPENDS}

USE_QMAIL=	yes

SPOOLDIR=	${PREFIX}/qmailscan
PLIST_SUB=	SPOOLDIR="${SPOOLDIR:S,${PREFIX}/,,}"

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	\
		--qmaildir "${QMAIL_PREFIX}" --spooldir "${SPOOLDIR}" \
		--bindir "${PREFIX}/bin" --qmail-queue-binary "${QMAIL_QUEUE}" \
		--admin "${QMAILSCAN_ADMIN}" --notify "${QMAILSCAN_NOTIFY}" \
		--silent-viruses "${QMAILSCAN_SILENTVIRUSES}" \
		--redundant yes \
		--add-dscr-hdrs yes \
		--log-details syslog --debug no \
		--batch

pre-configure:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "----------------------------------------"
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "QMAILSCAN_ADMIN          email adress of qmail-scanner admin for alerts"
	@${ECHO_MSG} "QMAILSCAN_ADMINREALNAME* name to use when sending alerts"
	@${ECHO_MSG} "QMAILSCAN_LANG           specify languages for QS mails (notify, etc..)"
	@${ECHO_MSG} "                         supported languages are: af_ZA, cs_CZ, da_DK, de_DE,"
	@${ECHO_MSG} "                         en_GB, en_PL, enlt_LT, enlt_LT_short, es_ES, fr_FR,"
	@${ECHO_MSG} "                         it_IT, ja_JP.EUC, nl_NL, no_NO, pl_PL, pt_BR, pt_PT,"
	@${ECHO_MSG} "                         sk_SK, sv_SE, tr_TR, tr_TR_ascii and tw_BIG5"
	@${ECHO_MSG} "                         default depends on your LANG variable"
	@${ECHO_MSG} "                         (en_GB if LANG is not set)"
	@${ECHO_MSG} "QMAILSCAN_LOCALDOMAINS   domains classified as local domains preventing alerts"
	@${ECHO_MSG} "                         of externals users (and mailing-lists...)"
	@${ECHO_MSG} "QMAILSCAN_LOGCRYPTO      simply notes in the log record if the message"
	@${ECHO_MSG} "                         contained any form of digital signing or encryption"
	@${ECHO_MSG} "                         (S/MIME, PGP and password protected files)"
	@${ECHO_MSG} "                         default is disabled"
	@${ECHO_MSG} "QMAILSCAN_MAXZIPSIZE     zip that would have unpacked into more diskspace"
	@${ECHO_MSG} "                         than this value will be blocked (prevent DoS)"
	@${ECHO_MSG} "                         default is 1000000000"
	@${ECHO_MSG} "QMAILSCAN_NOTBLKZIPPW    zip password protected are blocked by default"
	@${ECHO_MSG} "                         setting this variable to disable this function"
	@${ECHO_MSG} "QMAILSCAN_NOTIFY         who has to be notify of viruses/spams"
	@${ECHO_MSG} "                         defaults to 'psender,precips'"
	@${ECHO_MSG} "QMAILSCAN_SCANNERS       list of installed content scanner"
	@${ECHO_MSG} "                         default is automatic, so you do not need to set this"
	@${ECHO_MSG} "QMAILSCAN_SILENTVIRUSES  viruses that qs shoud not notify about"
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
		${ECHO_MSG} "Unable to found qmail-queue binary trying '${QMAIL_QUEUE}'.";  \
		${ECHO_MSG} "Please set QMAIL_PREFIX to your qmail installation directory !"; \
		exit 1; \
	fi

post-configure:
	${TEST} -f ${WRKSRC}/qmail-scanner-queue.pl

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
	${INSTALL_DATA} ${WRKSRC}/contrib/mrtg-qmail-scanner.cfg \
		${PREFIX}/share/examples/qs2mrtg
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

post-deinstall:
	@${ECHO_MSG}
	@${ECHO_MSG} "If you're not updating this port, you can delete directory '${SPOOLDIR}'."
	@${ECHO_MSG} ""

test:
	@${WRKSRC}/contrib/test_installation.sh -doit

.include <bsd.port.mk>
