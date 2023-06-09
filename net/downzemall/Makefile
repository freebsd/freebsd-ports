PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	3.0.6
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Multi-protocol standalone download manager
WWW=		https://setvisible.github.io/DownZemAll/

LICENSE=	LGPL21+

LIB_DEPENDS=	libtorrent-rasterbar.so:net-p2p/libtorrent-rasterbar2

USES=		cmake qt:6 ssl
USE_QT=		base
USE_GITHUB=	yes
GH_ACCOUNT=	setvisible
GH_PROJECT=	DownZemAll

CMAKE_OFF=	BUILD_LAUNCHER BUILD_TESTS

PLIST_FILES=	bin/DownZemAll \
		share/applications/DownZemAll.desktop \
		share/pixmaps/DownZemAll.png

post-extract:
	@${RM} -r ${WRKSRC}/3rd/libtorrent-rasterbar
	@${RM} ${WRKSRC}/cmake/Modules/FindLibtorrentRasterbar.cmake

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/src/DownZemAll \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} \
		${WRKSRC}/installer/unix/appimage/DownZemAll.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} \
		${WRKSRC}/installer/unix/portable/DownZemAll_64x64.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/DownZemAll.png

.include <bsd.port.mk>
