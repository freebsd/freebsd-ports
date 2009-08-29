# New ports collection makefile for:	schroedinger
# Date created:		2008-06-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

.if !defined(_BUILDING_GSTREAMER_PLUGIN)
PORTNAME=	schroedinger
.else
PORTNAME=	gstreamer
.endif
PORTVERSION=	1.0.7
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://diracvideo.org/download/schroedinger/
MASTER_SITE_SUBDIR=	${PORTNAME}
.if defined(_BUILDING_GSTREAMER_PLUGIN)
PKGNAMESUFFIX=	-schroedinger
DISTNAME=	schroedinger-${PORTVERSION}
.endif

MAINTAINER=	mm@FreeBSD.org
.if !defined(_BUILDING_GSTREAMER_PLUGIN)
COMMENT=	High-speed Dirac codec
.else
COMMENT=	GStreamer dirac plugin using Schroedinger library
.endif

LIB_DEPENDS=	oil:${PORTSDIR}/devel/liboil
.if defined(_BUILDING_GSTREAMER_PLUGIN)
LIB_DEPENDS+=	schroedinger-1.0.2:${PORTSDIR}/multimedia/schroedinger
.endif

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.if defined(_BUILDING_GSTREAMER_PLUGIN)
WANT_GSTREAMER=	yes
USE_GSTREAMER=	yes
BUILD_WRKSRC=		${WRKDIR}/${DISTNAME}/gst
INSTALL_WRKSRC=		${BUILD_WRKSRC}
PLIST=		${WRKSRC}/PLIST
DESCR=		${MASTERDIR}/pkg-descr.gstreamer
.else
CONFIGURE_ARGS+=	--disable-gstreamer
.endif

.include <bsd.port.pre.mk>

.if defined(_BUILDING_GSTREAMER_PLUGIN)
PLIST_FILES+=	lib/gstreamer-${GST_VERSION}/libgstschro.a \
		lib/gstreamer-${GST_VERSION}/libgstschro.la \
		lib/gstreamer-${GST_VERSION}/libgstschro.so
.endif

post-patch:
	${REINPLACE_CMD} -e 's|^pkgconfigdir=.*|pkgconfigdir="\\$$(prefix)/libdata/pkgconfig"|' ${WRKSRC}/configure

.if defined(_BUILDING_GSTREAMER_PLUGIN)
post-configure:
	${REINPLACE_CMD} -e "s|\$$(top_builddir)/schroedinger/libschroedinger-1.0.la|${LOCALBASE}/lib/libschroedinger-1.0.la|g" \
		${WRKSRC}/gst/Makefile

pre-build:
	@cd ${WRKSRC}/gst-libs/gst/video && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}

.endif

.include <bsd.port.post.mk>
