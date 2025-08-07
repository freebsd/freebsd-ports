PORTNAME=	supersonic
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Lightweight cross-platform desktop client for Subsonic music servers
WWW=		https://github.com/dweymouth/${PORTNAME}/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		desktop-file-utils gl go:modules localbase:ldflags pkgconfig \
		xorg
USE_GL=		gl
USE_XORG=	x11 xau xcb xcursor xdmcp xi
GO_MODULE=	github.com/dweymouth/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/supersonic-desktop.desktop \
		share/icons/hicolor/128x128/apps/supersonic-desktop.png \
		share/icons/hicolor/256x256/apps/supersonic-desktop.png \
		share/icons/hicolor/512x512/apps/supersonic-desktop.png \
		share/pixmaps/supersonic-desktop.png

post-patch:
	@${REINPLACE_CMD} -e 's|Exec=supersonic-desktop|Exec=supersonic|' \
		${WRKSRC}/res/supersonic-desktop.desktop

post-install:
	${INSTALL_DATA} ${WRKSRC}/res/supersonic-desktop.desktop \
		${STAGEDIR}${DESKTOPDIR}
.for s in 128 256 512
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/res/appicon-${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/supersonic-desktop.png
.endfor
	${INSTALL_DATA} ${WRKSRC}/res/appicon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/supersonic-desktop.png

.include <bsd.port.mk>
