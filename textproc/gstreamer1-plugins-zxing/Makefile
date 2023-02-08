PORTREVISION=	0
CATEGORIES=	textproc multimedia

COMMENT=	GStreamer plugin for QR recognition

LIB_DEPENDS=	libZXing.so:textproc/zxing-cpp

USES+=		compiler:c++17-lang

GST_PLUGIN=	zxing
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
