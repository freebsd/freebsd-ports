# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-plugins-good/Makefile,v 1.14 2008/03/19 14:05:36 ahze Exp $

PORTREVISION=	2
CATEGORIES=	multimedia

COMMENT=	Good gstreamer-plugins

GST_PLUGIN=	good
GST_PLUGIN_SUFFIX=	-good

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer-plugins

BUILD_DEPENDS+=	gstreamer-plugins>=${GST_VERSION}${GST_MINOR_VERSION}:multimedia/gstreamer-plugins
RUN_DEPENDS+=	gstreamer-plugins>=${GST_VERSION}${GST_MINOR_VERSION}:multimedia/gstreamer-plugins

USE_XORG+=	xdamage

gst_good_DIST=	good
GOOD_GST_DIRS=	gst sys po
PLIST_SUB=	VERSION="${GST_VERSION}"

PLIST=	${.CURDIR}/pkg-plist
FILESDIR=${.CURDIR}/files
PATCHDIR=${.CURDIR}/files
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
