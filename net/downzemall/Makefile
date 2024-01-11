PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	4.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Multi-protocol standalone download manager
WWW=		https://www.arrow-dl.com/ArrowDL/

LICENSE=	LGPL21+

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
	@${RM} -r ${WRKSRC}/3rd/libtorrent-rasterbar
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
