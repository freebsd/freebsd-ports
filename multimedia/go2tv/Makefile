PORTNAME=	go2tv
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Cast media files to Smart TVs and Chromecast devices
WWW=		https://go2tv.app/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>=5.8:devel/evdev-proto
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libwayland-client.so:graphics/wayland \
		libwayland-cursor.so:graphics/wayland \
		libwayland-egl.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		gl go:modules pkgconfig xorg

USE_GL=		gl
USE_XORG=	x11 xau xcb xdmcp

GO_MODULE=	go2tv.app/go2tv/v2
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-tags "migrated_fynedo,wayland" \
		-ldflags "-s -w -X main.version=${PORTVERSION}"

PLIST_FILES=	bin/go2tv \
		share/applications/app.go2tv.go2tv.desktop \
		share/icons/hicolor/512x512/apps/app.go2tv.go2tv.png \
		share/icons/hicolor/scalable/apps/app.go2tv.go2tv.svg

post-patch:
	${REINPLACE_CMD} \
		-e 's|^\(Exec=\)\(go2tv\)|\1${SETENV} LANG=en_US.UTF-8 ${PREFIX}/bin/\2|1' \
		${WRKSRC}/assets/linux/app.go2tv.go2tv.desktop

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/assets/linux/app.go2tv.go2tv.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	${INSTALL_DATA} ${WRKSRC}/assets/go2tv-icon-desktop-512.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/app.go2tv.go2tv.png
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/assets/go2tv-icon-color.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/app.go2tv.go2tv.svg

.include <bsd.port.mk>
