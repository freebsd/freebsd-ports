# New ports collection makefile for:	gstreamer-plugins-bad
# Date created:			20 Jan 2006
# Whom:				Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-plugins-bad/Makefile,v 1.2 2006/02/26 19:23:20 marcus Exp $
#

PORTREVISION=	0
CATEGORIES=	multimedia

COMMENT=	Bad gstreamer-plugins

GST_PLUGIN=	bad
GST_PLUGIN_SUFFIX=	-bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer-plugins

BUILD_DEPENDS+=	gstreamer-plugins>=${GST_VERSION}${GST_MINOR_VERSION}:${PORTSDIR}/multimedia/gstreamer-plugins
RUN_DEPENDS+=	gstreamer-plugins>=${GST_VERSION}${GST_MINOR_VERSION}:${PORTSDIR}/multimedia/gstreamer-plugins

EXTRACT_ONLY=	${BAD_DISTFILE}
WRKSRC=	${WRKDIR}/${BAD_DISTNAME}

BAD_GST_DIRS=	gst sys
PLIST_SUB=	VERSION="${GST_VERSION}"
NO_GSTREAMER_COMMON=	yes
PLIST=	${.CURDIR}/pkg-plist

do-build:
.for dir in ${BAD_GST_DIRS}
	@(cd ${BUILD_WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

do-install:
.for dir in ${BAD_GST_DIRS}
	@(cd ${INSTALL_WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.endfor

.include "${MASTERDIR}/Makefile"
