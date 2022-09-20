PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer ASS/SSA text renderer plugin

GST_PLUGIN=	assrender
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS=  libass.so:multimedia/libass

.include "${MASTERDIR}/Makefile"

USES+= compiler:c11
