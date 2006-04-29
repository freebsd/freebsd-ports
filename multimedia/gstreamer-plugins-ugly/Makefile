# New ports collection makefile for:	gstreamer-plugins-ugly
# Date created:			20 Jan 2006
# Whom:				Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-plugins-ugly/Makefile,v 1.3 2006/04/16 08:42:06 marcus Exp $
#

PORTREVISION=	2
CATEGORIES=	multimedia

COMMENT=	Ugly gstreamer-plugins

GST_PLUGIN=	ugly
GST_PLUGIN_SUFFIX=	-ugly

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer-plugins

BUILD_DEPENDS+=	gstreamer-plugins>=${GST_VERSION}${GST_MINOR_VERSION}:${PORTSDIR}/multimedia/gstreamer-plugins
RUN_DEPENDS+=	gstreamer-plugins>=${GST_VERSION}${GST_MINOR_VERSION}:${PORTSDIR}/multimedia/gstreamer-plugins

EXTRACT_ONLY=	${UGLY_DISTFILE}
WRKSRC=	${WRKDIR}/${UGLY_DISTNAME}

UGLY_GST_DIRS=	gst
PLIST_SUB=	VERSION="${GST_VERSION}"
NO_GSTREAMER_COMMON=	yes
PLIST=	${.CURDIR}/pkg-plist

do-build:
.for dir in ${UGLY_GST_DIRS}
	@(cd ${BUILD_WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

do-install:
.for dir in ${UGLY_GST_DIRS}
	@(cd ${INSTALL_WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.endfor

.include "${MASTERDIR}/Makefile"
