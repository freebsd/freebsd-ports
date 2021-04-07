PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer parse and demuliplex a Smooth Streaming manifest into audio/video streams plugin

GST_PLUGIN=	smoothstreaming
DIST=		bad

SMOOTH_GST_DIRS=	gst-libs/gst/isoff

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

pre-build:
.for dir in ${SMOOTH_GST_DIRS}
	@(cd ${BUILD_WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

.include "${MASTERDIR}/Makefile"
