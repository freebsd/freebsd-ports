PORTREVISION=	0
CATEGORIES=	x11-toolkits

COMMENT=	GStreamer Qt5 QML videosink plugin

USES=		compiler:c++11-lang qt:5
USE_GSTREAMER=	gl
USE_QT=		core gui declarative \
		buildtools:build linguisttools:build qmake:build

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

OPTIONS_DEFINE=		WAYLAND X11
OPTIONS_DEFAULT=	WAYLAND X11

WAYLAND_USE=		QT=wayland
WAYLAND_MESON_ENABLED=	qt-wayland

X11_USE=		QT=x11extras
X11_MESON_ENABLED=	qt-x11

DIST=			good
GST_PLUGIN=		qt5

.include "${MASTERDIR}/Makefile"
