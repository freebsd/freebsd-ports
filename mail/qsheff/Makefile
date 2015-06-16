# Created by: Ozkan KIRIK <ozkan@enderunix.org>
# $FreeBSD$

PORTNAME=	qsheff-II
DISTVERSION=	2.1-r3
PORTREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	http://www.enderunix.org/qsheff/ \
		SF/qsheff/qsheff/II-2.1-r3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qmail-queue replacement to filter mail traffic

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/ripmime:${PORTSDIR}/mail/ripmime
RUN_DEPENDS:=	${BUILD_DEPENDS}

BROKEN_FreeBSD_8=	does not build on FreeBSD < 10.x
BROKEN_FreeBSD_9=	does not build on FreeBSD < 10.x

GNU_CONFIGURE=	yes

USES=		qmail

DOCS=		README COPYING AUTHORS ChangeLog INSTALL THANKS TODO
EXAMPLES=	sample-OK.msg sample-SPAM.msg sample-VIRUS.msg
CONTRIB=	README qq-custom-error-patch.diff qq-patch.diff \
		qsheff-patch.diff
FILES=		handbook.en.txt handbook.tr.txt spamass-qsheff.en.html
ETCFILES=	install-wrapper.sh uninstall-wrapper.sh qsheff.attach-default \
		qsheff.conf-default qsheff.ignore-default qsheff.rules-default

CONFIGURE_ARGS+=	--with-qmaildir=${QMAIL_PREFIX}

OPTIONS_DEFINE=	CLAMAV SPAMTAG VIRUSTAG DISABLELOCAL SYSLOG BACKUP CUSTOMERROR DEBUG DOCS EXAMPLES
OPTIONS_DEFAULT=	CLAMAV
CLAMAV_DESC=		Integrate with Clam AntiVirus
SPAMTAG_DESC=		Spam Tagging
VIRUSTAGSC=		Virus Tagging
DISABLELOCAL_DESC=	Disable Filters For Local Users
BACKUP_DESC=		Logging Incoming/Outgoing Mail
CUSTOMERROR_DESC=	Custom Error Patch

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLAMAV}
RUN_DEPENDS+=	${LOCALBASE}/bin/clamdscan:${PORTSDIR}/security/clamav
BUILD_DEPENDS+=	${LOCALBASE}/bin/clamdscan:${PORTSDIR}/security/clamav
CONFIGURE_ARGS+=	--with-clamav
CONFIGURE_ARGS+=	--with-clamd-socket=/var/run/clamav/clamd
.endif

.if ${PORT_OPTIONS:MSPAMTAG}
CONFIGURE_ARGS+=	--enable-spam-tag
.endif

.if ${PORT_OPTIONS:MVIRUSTAG}
CONFIGURE_ARGS+=	--enable-virus-tag
.endif

.if ${PORT_OPTIONS:MSYSLOG}
CONFIGURE_ARGS+=	--enable-syslog
.endif

.if ${PORT_OPTIONS:MDISABLELOCAL}
CONFIGURE_ARGS+=	--disable-local-users
.endif

.if ${PORT_OPTIONS:MBACKUP}
CONFIGURE_ARGS+=	--enable-backup
.endif

.if ${PORT_OPTIONS:MCUSTOMERROR}
CONFIGURE_ARGS+=	--enable-custom-error
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|^CFLAGS =|CFLAGS +=|" ${WRKSRC}/Makefile.in

post-build:
.if ! ${PORT_OPTIONS:MCLAMAV}
	@${REINPLACE_CMD} -e 's|enable_virus_prog = 1|enable_virus_prog = 0|g' \
		${WRKSRC}/etc/qsheff.conf-default
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/doc
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${FILES:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}/doc/
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/contrib
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/samples/,} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${CONTRIB:S,^,${WRKSRC}/contrib/,} ${STAGEDIR}${EXAMPLESDIR}/contrib
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${ETCFILES:S,^,${WRKSRC}/etc/,} ${STAGEDIR}${ETCDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/src/qsheff ${STAGEDIR}${PREFIX}/bin/qsheff

.include <bsd.port.mk>
