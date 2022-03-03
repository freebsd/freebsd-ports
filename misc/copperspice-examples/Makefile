PORTNAME=	copperspice-examples
DISTVERSIONPREFIX=	ks-
DISTVERSION=	1.7.3
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://download.copperspice.com/kitchensink/source/
DISTNAME=	KitchenSink-${DISTVERSION}

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Example programs for Copperspice

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386

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

USES=		compiler:c++17-lang cmake dos2unix gl gnome iconv jpeg pkgconfig ssl tar:bz2 xorg
USE_GL=		gl
USE_GNOME=	cairo glib20 libxml2
USE_GSTREAMER1=	yes
USE_XORG=	ice sm x11 xau xcb xcursor xext xfixes xi xinerama xrandr xrender

PLIST_FILES=	bin/kitchensink

NO_WRKSUBDIR=	yes
DOS2UNIX_FILES=	src/CMakeLists.txt

.include <bsd.port.mk>
