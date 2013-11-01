# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer1-plugins-good/Makefile,v 1.4 2013/01/15 21:43:45 kwm Exp $

PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	Good gstreamer-plugins

GST_PLUGIN=	good
GST_PLUGIN_SUFFIX=	-good

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

CONFIGURE_ARGS+=--enable-monoscope

BUILD_DEPENDS+=	gstreamer1-plugins>=${GST1_VERSION}${GST1_MINIMAL_VERSION}:${PORTSDIR}/multimedia/gstreamer1-plugins
RUN_DEPENDS+=	gstreamer1-plugins>=${GST1_VERSION}${GST1_MINIMAL_VERSION}:${PORTSDIR}/multimedia/gstreamer1-plugins

DIST=	good
GOOD_GST_DIRS=	gst sys po

PLIST=		${.CURDIR}/pkg-plist
FILESDIR=	${.CURDIR}/files
PATCHDIR=	${.CURDIR}/files
NO_GSTREAMER_COMMON=	yes

do-build:
.for dir in ${GOOD_GST_DIRS}
	@(cd ${BUILD_WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

do-install:
.for dir in ${GOOD_GST_DIRS}
	@(cd ${INSTALL_WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.endfor

.include "${MASTERDIR}/Makefile"
