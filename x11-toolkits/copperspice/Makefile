PORTNAME=	copperspice
DISTVERSIONPREFIX=	cs-
DISTVERSION=	1.7.3
CATEGORIES=	x11-toolkits

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	First class GUI library to unite the C++ community

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/license/LICENSE.LGPL

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

USES=		compiler:c++17-lang cmake gl gnome iconv jpeg pkgconfig ssl xorg
USE_GL=		gl
USE_GNOME=	cairo glib20 libxml2
USE_GSTREAMER1=	yes
USE_XORG=	ice sm x11 xau xcb xcursor xext xfixes xi xinerama xrandr xrender

USE_GITHUB=	yes

CMAKE_ARGS+=	-DCMAKE_INSTALL_BINDIR:PATH='$(LOCALBASE)/lib/copperspice/bin' \
		-DCMAKE_INSTALL_INCLUDEDIR:PATH='$(LOCALBASE)/include/copperspice' \
		-DCMAKE_INSTALL_PREFIX:PATH='$(LOCALBASE)' \
		-DTOOLS_SUFFIX:STRING=-cs

# There is a notional conflict with the Qt ports: those have **versioned**
# tool names, like designer-qt5, lupdate-qt5, to allow co-installation
# of Qt[456] (when we had / have more than one current-version in ports).
#
# Since CopperSpice doesn't version the binaries, it doesn't conflict
# with the Qt ports, but does "rudely" occupy the unversioned name.
#
# CONFLICTS=	qt5-core

.include <bsd.port.mk>
