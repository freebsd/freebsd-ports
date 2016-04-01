# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	GStreamer-plugins good-quality plug-ins

GST_PLUGIN=	good
GST_PLUGIN_SUFFIX=	-good

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

BUILD_DEPENDS+=	gstreamer1-plugins>=${GST1_VERSION}${GST1_MINIMAL_VERSION}:multimedia/gstreamer1-plugins
RUN_DEPENDS+=	gstreamer1-plugins>=${GST1_VERSION}${GST1_MINIMAL_VERSION}:multimedia/gstreamer1-plugins

DIST=	good
GOOD_GST_DIRS=	gst sys po

PLIST=		${.CURDIR}/pkg-plist
FILESDIR=	${.CURDIR}/files
PATCHDIR=	${.CURDIR}/files
NO_GSTREAMER_COMMON=	yes

do-build:
.for dir in ${GOOD_GST_DIRS}
	@(cd ${BUILD_WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

do-install:
.for dir in ${GOOD_GST_DIRS}
	@(cd ${INSTALL_WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.endfor

.include "${MASTERDIR}/Makefile"
