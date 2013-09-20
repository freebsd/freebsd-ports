# Created by: Ozkan KIRIK <ozkan@enderunix.org>
# $FreeBSD$

PORTNAME=	qsheff-II
PORTVERSION=	2.1.r3
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://www.enderunix.org/qsheff/ \
		SF/qsheff/qsheff/II-2.1-r3

DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-r/}

MAINTAINER=	ozkan@enderunix.org
COMMENT=	A qmail-queue replacement to filter mail traffic

BUILD_DEPENDS=	${LOCALBASE}/bin/ripmime:${PORTSDIR}/mail/ripmime
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	YES

USES=		qmail

DOCS=		README COPYING AUTHORS ChangeLog INSTALL THANKS TODO
EXAMPLES=	sample-OK.msg sample-SPAM.msg sample-VIRUS.msg
CONTRIB=	README qq-custom-error-patch.diff qq-patch.diff \
		qsheff-patch.diff
FILES=		handbook.en.txt handbook.tr.txt spamass-qsheff.en.html
ETCFILES=	install-wrapper.sh uninstall-wrapper.sh qsheff.attach-default \
		qsheff.conf-default qsheff.ignore-default qsheff.rules-default

CONFIGURE_ARGS+=	--with-qmaildir=${QMAIL_PREFIX}

OPTIONS_DEFINE=	CLAMAV SPAMTAG VIRUSTAG DISABLELOCAL SYSLOG BACKUP CUSTOMERROR DEBUG
OPTIONS_DEFAULT=	CLAMAV
CLAMAV_DESC=		Integrate with Clam AntiVirus
SPAMTAG_DESC=		Spam Tagging
VIRUSTAGSC=		Virus Tagging
DISABLELOCAL_DESC=	Disable Filters For Local Users
BACKUP_DESC=		Logging Incoming/Outgoing Mail
CUSTOMERROR_DESC=	Custom Error Patch

NO_STAGE=	yes
.include <bsd.port.pre.mk>

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
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|\(install-data-am: \)install-qsheffdocDATA|\1|g' \
			  -e 's| contribute$$||g' \
		${WRKSRC}/Makefile.in
.endif

post-build:
.if ! ${PORT_OPTIONS:MCLAMAV}
	@${REINPLACE_CMD} -e 's|enable_virus_prog = 1|enable_virus_prog = 0|g' \
		${WRKSRC}/etc/qsheff.conf-default
.endif

do-install:
.if ${PORT_OPTIONS:MDOCS}
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
