# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	conkeror
PORTVERSION=	20131117
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Keyboard-oriented, customizable web browser based on Mozilla XULRunner

LICENSE=	GPLv1 GPLv2 MPL
LICENSE_COMB=	multi

USE_XZ=		yes

OPTIONS_SINGLE+=	XULRUNNER
OPTIONS_SINGLE_XULRUNNER=	FIREFOX LIBXUL
FIREFOX_DESC?=	Use XULRunner from Firefox port
LIBXUL_DESC?=	Use XULRunner from LibXUL port
OPTIONS_DEFAULT+=	LIBXUL

WRKSRC=		${WRKDIR}/conkeror

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBXUL}
USE_GECKO=libxul
.else
USE_FIREFOX=25+
.endif

USES=		desktop-file-utils

BUILD_ID=	${ECHO_CMD} -n `whoami`@`hostname`_`date +%s`

post-patch:
		cd ${WRKSRC} && \
			${MV} debian/conkeror.desktop . && \
			${MV} contrib/man/conkeror.1 . && \
			${RM} -rf contrib/debian contrib/man debian tests && \
			${RM} -f contrib/build.sh contrib/install.sh contrib/mketags.sh \
			contrib/testrun.sh contrib/run-conkeror && \
			${MKDIR} share  && \
			${MV} branding chrome components content \
			contrib defaults locale modules search-engines help \
			style share && \
			${MV} COPYING CREDITS Info.plist chrome.manifest \
			content-policy.manifest share
.if ${PORT_OPTIONS:MFIREFOX}
		${REINPLACE_CMD} -e "s/xulrunner/firefox/g" ${WRKSRC}/conkeror
		${REINPLACE_CMD} -e "s/XULRUNNER/FIREFOX/g" ${WRKSRC}/conkeror
		${REINPLACE_CMD} -e 's/exec $${FIREFOX}/exec $${FIREFOX} -app/' ${WRKSRC}/conkeror
.endif

do-build:
		${MAKE} -C ${WRKSRC}

do-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/libexec/conkeror
		${MKDIR} ${STAGEDIR}${DATADIR}
		${MKDIR} ${STAGEDIR}${DESKTOPDIR}
		cd ${WRKSRC}/share && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
		${SED} -e "s/BuildID=git/BuildID=$$(${BUILD_ID})/g" \
			-e "s/^Version=\(.*\)$$/Version=\1 (FreeBSD-${OSREL})/g" \
			<${WRKSRC}/application.ini >${STAGEDIR}${DATADIR}/application.ini
		${INSTALL_SCRIPT} ${WRKSRC}/conkeror ${STAGEDIR}${PREFIX}/bin/
		${INSTALL_DATA} ${WRKSRC}/conkeror.desktop ${STAGEDIR}${DESKTOPDIR}
		${INSTALL_PROGRAM} ${WRKSRC}/conkeror-spawn-helper ${STAGEDIR}${PREFIX}/libexec/conkeror/
		${LN} -sf ${PREFIX}/libexec/conkeror/conkeror-spawn-helper ${STAGEDIR}${DATADIR}/
		${INSTALL_MAN} ${WRKSRC}/conkeror.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install:
		@-update-desktop-database

.include <bsd.port.mk>
