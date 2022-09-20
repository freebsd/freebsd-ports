PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer (Intel MediaSDK) plugin

GST_PLUGIN=	msdk
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

LIB_DEPENDS= libgudev-1.0.so:devel/libgudev \
	libmfx.so:multimedia/intel-media-sdk \
	libva-drm.so:multimedia/libva \
	libdrm.so:graphics/libdrm

.include "${MASTERDIR}/Makefile"
