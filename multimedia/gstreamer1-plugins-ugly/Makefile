PORTREVISION=	0
CATEGORIES?=	multimedia audio

COMMENT=	GStreamer-plugins set of good-quality plug-ins that might have distribution problems

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=			ugly
GST_PLUGIN=		${DIST}
GST_PLUGIN_SUFFIX=	-${DIST}
NO_GSTREAMER_COMMON=	yes

UGLY_GST_ENABLED_PLUGINS=	asfdemux \
				nls \
				dvdlpcmdec \
				dvdsub \
				realmedia

.include "${MASTERDIR}/Makefile"
