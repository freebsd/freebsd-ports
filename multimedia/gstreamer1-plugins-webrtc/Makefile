PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer WebRTC plugin

LIB_DEPENDS=	libnice.so:net-im/libnice

USE_GSTREAMER=	dtls sctp srtp

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		bad
GST_PLUGIN=	webrtc

.include "${MASTERDIR}/Makefile"
