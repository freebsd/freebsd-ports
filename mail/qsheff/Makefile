# New ports collection makefile for:   qsheff
# Date created:                 14 Jul 2005
# Whom:                         Ozkan KIRIK <ozkan@enderunix.org>
#
# $FreeBSD$
#

PORTNAME=	qsheff-II
PORTVERSION=	2.1.r3
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	http://www.enderunix.org/qsheff/ \
		SF/qsheff/qsheff/II-2.1-r3

DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-r/}

MAINTAINER=	ozkan@enderunix.org
COMMENT=	A qmail-queue replacement to filter mail traffic

BUILD_DEPENDS=	${LOCALBASE}/bin/ripmime:${PORTSDIR}/mail/ripmime
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	YES

USE_QMAIL=	yes

DOCS=		README COPYING AUTHORS ChangeLog INSTALL THANKS TODO
EXAMPLES=	sample-OK.msg sample-SPAM.msg sample-VIRUS.msg
CONTRIB=	README qq-custom-error-patch.diff qq-patch.diff \
		qsheff-patch.diff
FILES=		handbook.en.txt handbook.tr.txt spamass-qsheff.en.html
ETCFILES=	install-wrapper.sh uninstall-wrapper.sh qsheff.attach-default \
		qsheff.conf-default qsheff.ignore-default qsheff.rules-default

CONFIGURE_ARGS+=	--with-qmaildir=${QMAIL_PREFIX}

OPTIONS=	CLAMAV "Integrate with Clam AntiVirus" on \
		SPAMTAG "Enable Spam Tagging" off \
		VIRUSTAG "Enable Virus Tagging" off \
		DISABLELOCAL "Disable Filters For Local Users" off \
		SYSLOG "Enable Syslog Logging" off \
		BACKUP "Enable Logging Incoming/Outgoing Mail" off \
		CUSTOMERROR "Enable Custom Error Patch" off \
		DEBUG "Enable Debug Messages" off

.include <bsd.port.pre.mk>

.if defined(WITH_CLAMAV)
RUN_DEPENDS+=	${LOCALBASE}/bin/clamdscan:${PORTSDIR}/security/clamav
BUILD_DEPENDS+=	${LOCALBASE}/bin/clamdscan:${PORTSDIR}/security/clamav
CONFIGURE_ARGS+=	--with-clamav
CONFIGURE_ARGS+=	--with-clamd-socket=/var/run/clamav/clamd
.endif

.if defined(WITH_SPAMTAG)
CONFIGURE_ARGS+=	--enable-spam-tag
.endif

.if defined(WITH_VIRUSTAG)
CONFIGURE_ARGS+=	--enable-virus-tag
.endif

.if defined(WITH_SYSLOG)
CONFIGURE_ARGS+=	--enable-syslog
.endif

.if defined(WITH_DISABLELOCAL)
CONFIGURE_ARGS+=	--disable-local-users
.endif

.if defined(WITH_BACKUP)
CONFIGURE_ARGS+=	--enable-backup
.endif

.if defined(WITH_CUSTOMERROR)
CONFIGURE_ARGS+=	--enable-custom-error
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|^CFLAGS =|CFLAGS +=|" ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|\(install-data-am: \)install-qsheffdocDATA|\1|g' \
			  -e 's| contribute$$||g' \
		${WRKSRC}/Makefile.in
.endif

post-build:
.if defined(WITHOUT_CLAMAV)
	@${REINPLACE_CMD} -e 's|enable_virus_prog = 1|enable_virus_prog = 0|g' \
		${WRKSRC}/etc/qsheff.conf-default
.endif

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/doc
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${INSTALL_DATA} ${FILES:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/doc/
	@${MKDIR} ${EXAMPLESDIR}/contrib
	@${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/samples/,} ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${CONTRIB:S,^,${WRKSRC}/contrib/,} ${EXAMPLESDIR}/contrib
.endif
	@${MKDIR} ${ETCDIR}
	@${INSTALL_DATA} ${ETCFILES:S,^,${WRKSRC}/etc/,} ${ETCDIR}/
	@${INSTALL_SCRIPT} ${WRKSRC}/src/qsheff ${PREFIX}/bin/qsheff

.include <bsd.port.post.mk>
