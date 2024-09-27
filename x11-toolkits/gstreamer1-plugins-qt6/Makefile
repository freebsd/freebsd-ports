PORTREVISION=	0
CATEGORIES=	x11-toolkits

COMMENT=	GStreamer Qt6 QML videosink plugin

USES=		compiler:c++17-lang qt:6
USE_GSTREAMER=	gl
USE_QT=		base declarative \
		shadertools:build tools:build

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

OPTIONS_DEFINE=		WAYLAND X11
OPTIONS_DEFAULT=	WAYLAND X11

WAYLAND_USE=		QT=wayland
WAYLAND_MESON_ENABLED=	qt-wayland

X11_MESON_ENABLED=	qt-x11

DIST=			good
GST_PLUGIN=		qt6

.include "${MASTERDIR}/Makefile"
