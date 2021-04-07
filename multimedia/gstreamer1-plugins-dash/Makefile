PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer Dynamic Adaptive Streaming over HTTP demuxer plugin

GST_PLUGIN=	dash
DIST=		bad

DASH_GST_DIRS=	gst-libs/gst/isoff

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

pre-build:
.for dir in ${DASH_GST_DIRS}
	@(cd ${BUILD_WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

.include "${MASTERDIR}/Makefile"
