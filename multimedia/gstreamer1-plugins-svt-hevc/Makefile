PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer (svt-hevc) plugin

DEPRECATED=	SVT-HEVC project discontinued by Intel on 2024-07-29
EXPIRATION_DATE=	2026-03-31

LIB_DEPENDS=	libSvtHevcEnc.so:multimedia/svt-hevc

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	svthevcenc

.include "${MASTERDIR}/Makefile"
