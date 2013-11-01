# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$
#    $MCom: kwm/multimedia/gstreamer1-plugins/Makefile 11404 2013-04-26 19:05:50Z kwm $

PORTNAME=	gstreamer
PORTVERSION?=	${BASE_PORTVERSION}
# When chasing a shared library for a plug-in bump the PORTREVISION in the
# plug-in port instead, like ${category}/gstreamer1-plugin-${PLUGIN}.
PORTREVISION?=	0
CATEGORIES?=	multimedia audio
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-plugins-base/:base \
		http://gstreamer.freedesktop.org/src/gst-plugins-bad/:bad \
		http://gstreamer.freedesktop.org/src/gst-plugins-good/:good \
		http://gstreamer.freedesktop.org/src/gst-plugins-ugly/:ugly
PKGNAMESUFFIX?=	1-plugins${GST_PLUGIN_SUFFIX}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT?=	GStreamer written collection of plugins handling several media types

BUILD_DEPENDS+=	gstreamer1>=${GST1_VERSION}${GST1_MINIMAL_VERSION}:${PORTSDIR}/multimedia/gstreamer1 \
		iso-codes>=0:${PORTSDIR}/misc/iso-codes \
		orc>=0.4.16:${PORTSDIR}/devel/orc
LIB_DEPENDS+=	libgstreamer-1.0.so:${PORTSDIR}/multimedia/gstreamer1 \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		liborc-0.4.so:${PORTSDIR}/devel/orc
RUN_DEPENDS+=	iso-codes>=0:${PORTSDIR}/misc/iso-codes

PORTSCOUT=	limitw:1,even

BASE_PORTVERSION=	1.0.10
BASE_DISTNAME=		gst-plugins-base-${BASE_PORTVERSION}
BASE_DISTFILE=		${BASE_DISTNAME}${EXTRACT_SUFX}
BAD_PORTVERSION=	1.0.10
BAD_DISTNAME=		gst-plugins-bad-${BAD_PORTVERSION}
BAD_DISTFILE=		${BAD_DISTNAME}${EXTRACT_SUFX}
GOOD_PORTVERSION=	1.0.10
GOOD_DISTNAME=		gst-plugins-good-${GOOD_PORTVERSION}
GOOD_DISTFILE=		${GOOD_DISTNAME}${EXTRACT_SUFX}
UGLY_PORTVERSION=	1.0.10
UGLY_DISTNAME=		gst-plugins-ugly-${UGLY_PORTVERSION}
UGLY_DISTFILE=		${UGLY_DISTNAME}${EXTRACT_SUFX}
DIST?=		base

SHLIB_VERSION=	0
VERSION=	${GST1_VERSION}

USES=		gettext gmake pathfix pkgconfig
WANT_GSTREAMER=	yes
USE_XZ=		yes
USE_GNOME+=	glib20 gnomehier introspection:build libxml2 ltverhack:0 \
		ltasneededhack
USE_AUTOTOOLS=	libtool
GST_PLUGIN?=	base
USE_LDCONFIG=	yes

CFLAGS:=	${CFLAGS} -O2 -Wno-format
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${EXTRA_LIBS} ${PTHREAD_LIBS}

DEFAULT_AUDIOSINK?=	osssink
DEFAULT_AUDIOSRC?=	osssrc

.if ${DIST}==""
IGNORE=		DIST not specified
.endif

.include <bsd.port.pre.mk>

.if ${ARCH}=="i386"
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif

.if ${GST_PLUGIN} == "base"
DIST=	base
NO_GSTREAMER_COMMON=	yes
.else
BUILD_DEPENDS+=	gstreamer1-plugins>=${GST1_VERSION}${GST1_MINIMAL_VERSION}:${PORTSDIR}/multimedia/gstreamer1-plugins
RUN_DEPEDNS+=	gstreamer1-plugins>=${GST1_VERSION}${GST1_MINIMAL_VERSION}:${PORTSDIR}/multimedia/gstreamer1-plugins
.endif

.if ${DIST} == base || ${DIST} == ugly
#  --with-default-audiosink specify default audio sink
#  --with-default-audiosrc specify default audio source
#  --with-default-videosink specify default video sink
#  --with-default-videosrc specify default video source
#  --with-default-visualizer specify default visualizer
CONFIGURE_ARGS+=--with-default-audiosink="${DEFAULT_AUDIOSINK}" \
		--with-default-audiosrc="${DEFAULT_AUDIOSRC}"
.endif

PLIST_SUB+=	VERSION="${VERSION}" \
		SHLIB_VERSION="${SHLIB_VERSION}"

.include "${MASTERDIR}/Makefile.common"

.if ${DIST}=="base"
EXTRACT_ONLY=${BASE_DISTFILE}
WRKSRC=${WRKDIR}/${BASE_DISTNAME}
PORTVERSION=	${BASE_PORTVERSION}
DISTFILES+=	${BASE_DISTFILE}:base
PATCHDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins/files
.elif ${DIST}=="bad"
EXTRACT_ONLY=${BAD_DISTFILE}
WRKSRC=${WRKDIR}/${BAD_DISTNAME}
PORTVERSION=	${BAD_PORTVERSION}
DISTFILES+=	${BAD_DISTFILE}:bad
PATCHDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins-bad/files
.elif ${DIST}=="ugly"
EXTRACT_ONLY=${UGLY_DISTFILE}
WRKSRC=${WRKDIR}/${UGLY_DISTNAME}
PORTVERSION=	${UGLY_PORTVERSION}
DISTFILES+=	${UGLY_DISTFILE}:ugly
PATCHDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins-ugly/files
.elif ${DIST}=="good"
EXTRACT_ONLY=${GOOD_DISTFILE}
WRKSRC=${WRKDIR}/${GOOD_DISTNAME}
PORTVERSION=	${GOOD_PORTVERSION}
DISTFILES+=	${GOOD_DISTFILE}:good
PATCHDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins-good/files
.elif ${DIST}=="makesum"
DISTFILES+=	${BASE_DISTFILE}:base ${BAD_DISTFILE}:bad \
		${UGLY_DISTFILE}:ugly ${GOOD_DISTFILE}:good
.else
BROKEN=		Unknown dist setting
.endif

# cdrom/dvd default device
.ifdef(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/cd0
.endif

post-patch:
.if ${DIST}=="bad"
	@${REINPLACE_CMD} -e 's|opencv <= 2.3.1|opencv <= 2.3.99|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|g' \
		${WRKSRC}/ext/resindvd/resindvdbin.c \
		${WRKSRC}/ext/resindvd/resindvdsrc.c
.endif
.if ${DIST}!="ugly"
	@${FIND} ${WRKSRC}/ext ${WRKSRC}/sys -name Makefile.in | \
	${XARGS} -n 10 ${REINPLACE_CMD} -e \
	's|$$(top_builddir)/gst-libs/gst/tag/libgsttag-@GST_API_VERSION@.la|${LOCALBASE}/lib/libgsttag-$$(GST_API_VERSION).la|; \
	s|$$(top_builddir)/gst-libs/gst/audio/libgstaudio-@GST_API_VERSION@.la|${LOCALBASE}/lib/libgstaudio-$$(GST_API_VERSION).la|; \
	s|$$(top_builddir)/gst-libs/gst/riff/libgstriff-@GST_API_VERSION@.la|${LOCALBASE}/lib/libgstriff-$$(GST_API_VERSION).la|; \
	s|$$(top_builddir)/gst-libs/gst/signalprocessor/libgstsignalprocessor-@GST_API_VERSION@.la|${LOCALBASE}/lib/libgstsignalprocessor-$$(GST_API_VERSION).la|; \
	s|$$(top_builddir)/gst-libs/gst/video/libgstbasevideo-@GST_API_VERSION@.la|${LOCALBASE}/lib/libgstbasevideo-$$(GST_API_VERSION).la|; \
	s|$$(top_builddir)/gst-libs/gst/video/libgstvideo-@GST_API_VERSION@.la|${LOCALBASE}/lib/libgstvideo-$$(GST_API_VERSION).la|'

	 @${FIND} ${WRKSRC}/ext ${WRKSRC}/sys -name Makefile.in | \
	 ${XARGS} -n 10 ${REINPLACE_CMD} -e \
	 's|$$(top_builddir)/gst-libs/gst/tag/libgsttag-$$(GST_API_VERSION).la|${LOCALBASE}/lib/libgsttag-$$(GST_API_VERSION).la|; \
	  s|$$(top_builddir)/gst-libs/gst/audio/libgstaudio-$$(GST_API_VERSION).la|${LOCALBASE}/lib/libgstaudio-$$(GST_API_VERSION).la|; \
	  s|$$(top_builddir)/gst-libs/gst/riff/libgstriff-$$(GST_API_VERSION).la|${LOCALBASE}/lib/libgstriff-$$(GST_API_VERSION).la|; \
	  s|$$(top_builddir)/gst-libs/gst/signalprocessor/libgstsignalprocessor-$$(GST_API_VERSION).la|${LOCALBASE}/lib/libgstsignalprocessor-$$(GST_API_VERSION).la|; \
	  s|$$(top_builddir)/gst-libs/gst/video/libgstbasevideo-$$(GST_API_VERSION).la|${LOCALBASE}/lib/libgstbasevideo-$$(GST_API_VERSION).la|; \
	  s|$$(top_builddir)/gst-libs/gst/video/libgstvideo-$$(GST_API_VERSION).la|${LOCALBASE}/lib/libgstvideo-$$(GST_API_VERSION).la|'
.endif
.if ${GST_PLUGIN} == "flite"
# Hack to get all the libraries linked to the flite plugin so it is useable.
	-@${REINPLACE_CMD} -e 's|-Wl,--as-needed||g' \
		${WRKSRC}/../gnome-libtool
.endif

# workaround a crash in clang 3.3 crash llvm bug # 15840
.if ((${OSVERSION} >= 901504 && ${OSVERSION} < 902502) || \
     (${OSVERSION} >= 1000037 && ${OSVERSION} < 1000056))
USE_GCC=	any
.endif

post-install:
.if ${GST_PLUGIN}==base
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgst*.so.0
.endif
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gstreamer-1.0/libgst*.so

.include <bsd.port.post.mk>
