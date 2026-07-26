PORTNAME=	elio
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.2
CATEGORIES=	sysutils

MAINTAINER=	miguelpr4242@gmail.com
COMMENT=	Snappy terminal file manager with rich previews and trash support
WWW=		https://elio-fm.github.io/ \
		https://github.com/elio-fm/elio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo desktop-file-utils
USE_GITHUB=	yes
GH_ACCOUNT=	elio-fm

PLIST_FILES=	bin/elio \
		share/applications/elio.desktop \
		share/icons/hicolor/48x48/apps/elio.png \
		share/icons/hicolor/128x128/apps/elio.png \
		share/icons/hicolor/256x256/apps/elio.png \
		share/icons/hicolor/512x512/apps/elio.png

post-install:
	${INSTALL_DATA} ${WRKSRC}/packaging/linux/elio.desktop \
		${STAGEDIR}${DESKTOPDIR}/

.for s in 48 128 256 512
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} \
		${WRKSRC}/packaging/linux/icons/hicolor/${s}x${s}/apps/elio.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/
.endfor

.include <bsd.port.mk>
