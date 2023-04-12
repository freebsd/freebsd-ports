PORTNAME=	gedkeeper
PORTVERSION=	2.25.1
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Personal genealogical database editor
WWW=		http://gedkeeper.net/

LICENSE=	GPLv3+

BUILD_DEPENDS=	msbuild:devel/msbuild
LIB_DEPENDS=	libgdiplus.so:x11-toolkits/libgdiplus
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		desktop-file-utils mono shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	Serg-Norseman
GH_PROJECT=	GEDKeeper GKCommunicator:gkc GKGenetix:gkg
GH_TAGNAME=	ea5c467:gkc 5d51cfd:gkg
GH_SUBDIR=	projects/GKCommunicator:gkc projects/GKGenetix:gkg

.if defined(WITH_DEBUG)
_BUILD_TYPE=	Debug
.else
_BUILD_TYPE=	Release
.endif

DATADIR=	${PREFIX}/lib/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -E '/^(Path|Icon)=/s,/usr,${PREFIX}, ; \
	    /^Exec=/s,gk_run\.sh,${PORTNAME},' \
		${WRKSRC}/deploy/gedkeeper.desktop

do-build:
	cd ${BUILD_WRKSRC} && msbuild projects/GKv2/GEDKeeper2.sln \
		/p:Configuration=${_BUILD_TYPE} /p:MonoCS=true

do-install:
	${PRINTF} '#!/bin/sh\n\nexec mono ${DATADIR}/GEDKeeper2.exe\
		"$$@"\n' > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${INSTALL_WRKSRC} && ${CP} -a backgrounds bin/ externals \
		locales plugins samples scripts themes ${STAGEDIR}${DATADIR}
	@${RM} ${STAGEDIR}${DATADIR}/scripts/readme.txt
	${INSTALL_DATA} ${INSTALL_WRKSRC}/deploy/gedkeeper.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${INSTALL_WRKSRC}/deploy/gedkeeper.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${INSTALL_WRKSRC}/deploy/application-x-gedkeeper.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${INSTALL_WRKSRC}/deploy/gedkeeper.appdata.xml \
		${STAGEDIR}${PREFIX}/share/metainfo

do-test:
	cd ${TEST_WRKSRC} && TEMP=/tmp nunit-console \
		projects/GKTests/bin/${_BUILD_TYPE}/GKTests.dll

.include <bsd.port.mk>

PATCH_ARGS=	-l
