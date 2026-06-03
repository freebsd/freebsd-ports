PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	4.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Multi-protocol standalone download manager
WWW=		https://www.arrow-dl.com/

LICENSE=	LGPL21+ # https://github.com/setvisible/ArrowDL/issues/246

LIB_DEPENDS=	libtorrent-rasterbar.so:net-p2p/libtorrent-rasterbar2

USES=		cmake qt:6 ssl
USE_QT=		base
USE_GITHUB=	yes
GH_ACCOUNT=	setvisible
GH_PROJECT=	ArrowDL

CMAKE_OFF=	BUILD_LAUNCHER BUILD_TESTS

PLIST_FILES=	bin/${GH_PROJECT} \
		share/applications/${GH_PROJECT}.desktop \
		share/pixmaps/${GH_PROJECT}.png

post-extract:
	@cd ${WRKSRC}/3rd && ${RM} -r libtorrent-rasterbar qtwebengine yt-dlp
	@${RM} ${WRKSRC}/cmake/Modules/FindLibtorrentRasterbar.cmake

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/src/${GH_PROJECT} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} \
		${WRKSRC}/installer/unix/appimage/${GH_PROJECT}.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} \
		${WRKSRC}/installer/unix/portable/${GH_PROJECT}_64x64.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${GH_PROJECT}.png

.include <bsd.port.mk>
