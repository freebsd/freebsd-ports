PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer ASS/SSA text renderer plugin

LIB_DEPENDS=	libass.so:multimedia/libass

USES=		compiler:c11

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	assrender

.include "${MASTERDIR}/Makefile"
