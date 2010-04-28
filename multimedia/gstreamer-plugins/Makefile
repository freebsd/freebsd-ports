# New ports collection makefile for:	gstreamer plugins
# Date created:		Wed Jul 10 23:38:01 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/multimedia/gstreamer-plugins/Makefile,v 1.125 2010/03/16 19:33:10 mezz Exp $
#

PORTNAME=	gstreamer
PORTVERSION?=	${BASE_PORTVERSION}
PORTREVISION?=	0
PORTEPOCH=	3
CATEGORIES?=	multimedia audio
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-plugins-base/:base \
		http://gstreamer.freedesktop.org/src/gst-plugins-bad/:bad \
		http://gstreamer.freedesktop.org/src/gst-plugins-good/:good \
		http://gstreamer.freedesktop.org/src/gst-plugins-ugly/:ugly \
		${MASTER_SITE_LOCAL:S|$|ahze/:base|} \
		${MASTER_SITE_LOCAL:S|$|ahze/:good|} \
		${MASTER_SITE_LOCAL:S|$|ahze/:bad|} \
		${MASTER_SITE_LOCAL:S|$|ahze/:ugly|}
PKGNAMESUFFIX?=	-plugins${GST_PLUGIN_SUFFIX}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT?=	GStreamer written collection of plugins handling several media types

BUILD_DEPENDS+=	v4l_compat>=1.0.20100321:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS+=	gstreamer-0.10.0:${PORTSDIR}/multimedia/gstreamer \
		popt.0:${PORTSDIR}/devel/popt \
		oil-0.3.0:${PORTSDIR}/devel/liboil

CFLAGS:=	${CFLAGS} -O2 -Wno-format

BASE_PORTVERSION=	0.10.29
BASE_DISTNAME=		gst-plugins-base-${BASE_PORTVERSION}
BASE_DISTFILE=		${BASE_DISTNAME}${EXTRACT_SUFX}
BAD_PORTVERSION=	0.10.18
BAD_DISTNAME=		gst-plugins-bad-${BAD_PORTVERSION}
BAD_DISTFILE=		${BAD_DISTNAME}${EXTRACT_SUFX}
GOOD_PORTVERSION=	0.10.21
GOOD_DISTNAME=		gst-plugins-good-${GOOD_PORTVERSION}
GOOD_DISTFILE=		${GOOD_DISTNAME}${EXTRACT_SUFX}
UGLY_PORTVERSION=	0.10.14
UGLY_DISTNAME=		gst-plugins-ugly-${UGLY_PORTVERSION}
UGLY_DISTFILE=		${UGLY_DISTNAME}${EXTRACT_SUFX}
DIST?=		good

SHLIB_VERSION=	1
USE_GETTEXT=	yes
VERSION=	${GST_VERSION}
WANT_GSTREAMER=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME+=	gnomehack gnometarget pkgconfig ltverhack ltasneededhack
USE_AUTOTOOLS=	libtool:22
GST_PLUGIN?=	base

CONFIGURE_ARGS=	--disable-option-checking
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${EXTRA_LIBS} ${PTHREAD_LIBS}"

DEFAULT_AUDIOSINK?=	osssink
DEFAULT_AUDIOSRC?=	osssrc

.include <bsd.port.pre.mk>

.if ${ARCH}=="i386"
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif

.if ${GST_PLUGIN} == "base"
gst_base_DIST=	base
NO_GSTREAMER_COMMON=	yes
USE_LDCONFIG=	yes
MAN1=		gst-visualise-0.10.1
PLIST_SUB+=	VERSION="${VERSION}" \
		SHLIB_VERSION="${SHLIB_VERSION}"
.else
USE_GSTREAMER=	yes
.endif

.include "${MASTERDIR}/Makefile.common"

.if ${DIST}=="base"
EXTRACT_ONLY=${BASE_DISTFILE}
WRKSRC=${WRKDIR}/${BASE_DISTNAME}
PORTVERSION=	${BASE_PORTVERSION}
DISTFILES+=	${BASE_DISTFILE}:base
PATCHDIR=	${.CURDIR}/../../multimedia/gstreamer-plugins/files
.elif ${DIST}=="bad"
EXTRACT_ONLY=${BAD_DISTFILE}
WRKSRC=${WRKDIR}/${BAD_DISTNAME}
PORTVERSION=	${BAD_PORTVERSION}
DISTFILES+=	${BAD_DISTFILE}:bad
PATCHDIR=	${.CURDIR}/../../multimedia/gstreamer-plugins-bad/files
.elif ${DIST}=="ugly"
EXTRACT_ONLY=${UGLY_DISTFILE}
WRKSRC=${WRKDIR}/${UGLY_DISTNAME}
PORTVERSION=	${UGLY_PORTVERSION}
DISTFILES+=	${UGLY_DISTFILE}:ugly
PATCHDIR=	${.CURDIR}/../../multimedia/gstreamer-plugins-ugly/files
.elif ${DIST}=="makesum"
DISTFILES+=	${BASE_DISTFILE}:base ${BAD_DISTFILE}:bad \
		${UGLY_DISTFILE}:ugly ${GOOD_DISTFILE}:good
.else
EXTRACT_ONLY=${GOOD_DISTFILE}
WRKSRC=${WRKDIR}/${GOOD_DISTNAME}
PORTVERSION=	${GOOD_PORTVERSION}
DISTFILES+=	${GOOD_DISTFILE}:good
PATCHDIR=	${.CURDIR}/../../multimedia/gstreamer-plugins-good/files
.endif

# cdrom default device
.ifdef(WITH_CDROM_DEVICE)
DEFAULT_CDROM_DEVICE=${WITH_CDROM_DEVICE}
.else
DEFAULT_CDROM_DEVICE=/dev/acd0
.endif

# dvd default device
.ifdef(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif

post-patch:
	@${FIND} ${WRKSRC}/ext -name Makefile.in | \
	${XARGS} -n 10 ${REINPLACE_CMD} -e \
	's|$$(top_builddir)/gst-libs/gst/tag/libgsttag-$$(GST_MAJORMINOR).la|${LOCALBASE}/lib/libgsttag-@GST_MAJORMINOR@.la|; \
	s|$$(top_builddir)/gst-libs/gst/audio/libgstaudio-$$(GST_MAJORMINOR).la|${LOCALBASE}/lib/libgstaudio-@GST_MAJORMINOR@.la|; \
	s|$$(top_builddir)/gst-libs/gst/riff/libgstriff-$$(GST_MAJORMINOR).la|${LOCALBASE}/lib/libgstriff-@GST_MAJORMINOR@.la|; \
	s|$$(top_builddir)/gst-libs/gst/signalprocessor/libgstsignalprocessor-$$(GST_MAJORMINOR).la|${LOCALBASE}/lib/libgstsignalprocessor-@GST_MAJORMINOR@.la|; \
	s|$$(top_builddir)/gst-libs/gst/video/libgstvideo-$$(GST_MAJORMINOR).la|${LOCALBASE}/lib/libgstvideo-@GST_MAJORMINOR@.la|; \
	s|$$(top_builddir)/gst-libs/gst/cdda/libgstcdda-$$(GST_MAJORMINOR).la|${LOCALBASE}/lib/libgstcdda-@GST_MAJORMINOR@.la|'
	@${FIND} ${WRKSRC} -type f | \
	${XARGS} -n 10 ${REINPLACE_CMD} -e \
	's|malloc\.h|stdlib.h|; \
	 s|<stdint\.h|<inttypes.h|; \
	 s|%%VERSION%%|${VERSION}|'
	 @${FIND} ${WRKSRC}/ext -name Makefile.in | \
	 ${XARGS} -n 10 ${REINPLACE_CMD} -e \
	 's|$$(top_builddir)/gst-libs/gst/tag/libgsttag-@GST_MAJORMINOR@.la|${LOCALBASE}/lib/libgsttag-@GST_MAJORMINOR@.la|; \
	  s|$$(top_builddir)/gst-libs/gst/audio/libgstaudio-@GST_MAJORMINOR@.la|${LOCALBASE}/lib/libgstaudio-@GST_MAJORMINOR@.la|; \
	  s|$$(top_builddir)/gst-libs/gst/riff/libgstriff-@GST_MAJORMINOR@.la|${LOCALBASE}/lib/libgstriff-@GST_MAJORMINOR@.la|; \
	  s|$$(top_builddir)/gst-libs/gst/signalprocessor/libgstsignalprocessor-@GST_MAJORMINOR@.la|${LOCALBASE}/lib/libgstsignalprocessor-@GST_MAJORMINOR@.la|; \
	  s|$$(top_builddir)/gst-libs/gst/video/libgstvideo-@GST_MAJORMINOR@.la|${LOCALBASE}/lib/libgstvideo-@GST_MAJORMINOR@.la|; \
	  s|$$(top_builddir)/gst-libs/gst/cdda/libgstcdda-@GST_MAJORMINOR@.la|${LOCALBASE}/lib/libgstcdda-@GST_MAJORMINOR@.la|'
	@${REINPLACE_CMD} -e 's|DEFAULT_AUDIOSINK="alsasink"|DEFAULT_AUDIOSINK="${DEFAULT_AUDIOSINK}"|; \
		s|DEFAULT_AUDIOSRC="alsasrc"|DEFAULT_AUDIOSRC="${DEFAULT_AUDIOSRC}"|' \
		-e 's|libpng12.pc|libpng14.pc|g' \
        	-e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
