# New ports collection makefile for:	gstreamer-plugins-good
# Date created:			20 Jan 2006
# Whom:				Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-plugins-good/Makefile,v 1.5 2006/04/02 07:33:41 marcus Exp $
#

PORTREVISION=	3
CATEGORIES=	multimedia

COMMENT=	Good gstreamer-plugins

GST_PLUGIN=	good
GST_PLUGIN_SUFFIX=	-good

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer-plugins

BUILD_DEPENDS+=	gstreamer-plugins>=${GST_VERSION}${GST_MINOR_VERSION}:${PORTSDIR}/multimedia/gstreamer-plugins
RUN_DEPENDS+=	gstreamer-plugins>=${GST_VERSION}${GST_MINOR_VERSION}:${PORTSDIR}/multimedia/gstreamer-plugins

EXTRACT_ONLY=	${GOOD_DISTFILE}
WRKSRC=	${WRKDIR}/${GOOD_DISTNAME}

GOOD_GST_DIRS=	gst sys
PLIST_SUB=	VERSION="${GST_VERSION}"
NO_GSTREAMER_COMMON=	yes
PLIST=	${.CURDIR}/pkg-plist
FILESDIR=${.CURDIR}/files
PATCHDIR=${.CURDIR}/files

do-build:
.for dir in ${GOOD_GST_DIRS}
	@(cd ${BUILD_WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

do-install:
.for dir in ${GOOD_GST_DIRS}
	@(cd ${INSTALL_WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.endfor

.include "${MASTERDIR}/Makefile"
