PORTREVISION=	0
CATEGORIES?=	multimedia audio

COMMENT=	GStreamer-plugins set of good-quality plug-ins that might have distribution problems

GST_PLUGIN=	ugly
GST_PLUGIN_SUFFIX=	-ugly

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

DIST=	ugly
NO_GSTREAMER_COMMON=	yes
PLIST=	${.CURDIR}/pkg-plist
UGLY_GST_ENABLED_PLUGINS=	asfdemux \
				nls \
				dvdlpcmdec \
				dvdsub \
				realmedia \
				xingmux

.include "${MASTERDIR}/Makefile"
