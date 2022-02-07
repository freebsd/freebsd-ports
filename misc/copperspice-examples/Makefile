PORTNAME=	copperspice-examples
DISTVERSIONPREFIX=	ks-
DISTVERSION=	1.7.3
CATEGORIES=	misc

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Example programs for Copperspice

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libpulse.so:audio/pulseaudio \
		libgstreamer-1.0.so:multimedia/gstreamer1 \
		libcups.so:print/cups \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-render-util.so:x11/xcb-util-renderutil \
		libxcb.so:x11/libxcb \
		libxkbcommon.so:x11/libxkbcommon \
		libfontconfig.so:x11-fonts/fontconfig
BUILD_DEPENDS=	copperspice>=1.7:x11-toolkits/copperspice
RUN_DEPENDS=	copperspice>=1.7:x11-toolkits/copperspice

USES=		compiler:c++17-lang cmake gl gnome iconv jpeg pkgconfig ssl xorg
USE_GL=		gl
USE_GNOME=	cairo glib20 libxml2
USE_GSTREAMER1=	yes
USE_XORG=	ice sm x11 xau xcb xcursor xext xfixes xi xinerama xrandr xrender

USE_GITHUB=	yes
GH_ACCOUNT=	copperspice
GH_PROJECT=	kitchensink

PLIST_FILES=	bin/kitchensink

.include <bsd.port.mk>
