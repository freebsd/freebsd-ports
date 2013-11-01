# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer1-plugins-bad/Makefile,v 1.4 2013/01/15 21:43:45 kwm Exp $

PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	Bad gstreamer-plugins

GST_PLUGIN=	bad
GST_PLUGIN_SUFFIX=	-bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

BUILD_DEPENDS+=	gstreamer1-plugins>=${GST1_VERSION}${GST1_MINIMAL_VERSION}:${PORTSDIR}/multimedia/gstreamer1-plugins \
		v4l_compat>=1.0.20100321:${PORTSDIR}/multimedia/v4l_compat
RUN_DEPENDS+=	gstreamer1-plugins>=${GST1_VERSION}${GST1_MININAL_VERSION}:${PORTSDIR}/multimedia/gstreamer1-plugins

DIST=		bad
BAD_GST_DIRS=	gst-libs sys gst po pkgconfig
NO_GSTREAMER_COMMON=	yes
PLIST=		${.CURDIR}/pkg-plist

do-build:
.for dir in ${BAD_GST_DIRS}
	@(cd ${BUILD_WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

do-install:
.for dir in ${BAD_GST_DIRS}
	@(cd ${INSTALL_WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor

.include "${MASTERDIR}/Makefile"
