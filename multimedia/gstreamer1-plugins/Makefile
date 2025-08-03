PORTNAME=	gstreamer
PORTVERSION?=	${BASE_PORTVERSION}
# plug-in port instead, like ${category}/gstreamer1-plugin-${PLUGIN}.
PORTREVISION?=	0
CATEGORIES?=	multimedia audio
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-plugins-base/:base \
		https://gstreamer.freedesktop.org/src/gst-plugins-bad/:bad \
		https://gstreamer.freedesktop.org/src/gst-plugins-good/:good \
		https://gstreamer.freedesktop.org/src/gst-plugins-ugly/:ugly
PKGNAMESUFFIX?=	1-plugins${GST_PLUGIN_SUFFIX}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT?=	GStreamer written collection of plugins handling several media types
WWW=		https://gstreamer.freedesktop.org/

LICENSE=	LGPL20

BUILD_DEPENDS+=	iso-codes>=0:misc/iso-codes \
		orc>=0.4.16:devel/orc
LIB_DEPENDS+=	libfreetype.so:print/freetype2 \
		liborc-0.4.so:devel/orc
RUN_DEPENDS+=	iso-codes>=0:misc/iso-codes

USES+=		meson cpe gettext gnome gstreamer libtool pathfix pkgconfig python:build tar:xz
CPE_VENDOR=	gstreamer_project
CPE_PRODUCT=	gstreamer
USE_GNOME+=	glib20 introspection:build libxml2
USE_LDCONFIG=	yes

MESON_ARGS+=	--auto-features=auto # XXX bug 270361 workaround

CFLAGS+=	-Wno-format
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib ${EXTRA_LIBS}

PORTSCOUT=	limitw:1,even

PLIST_SUB+=	SOVERSION="${_GST_SOVERSION}" \
		VERSION="${_GST_LIB_VER}"

BASE_PORTVERSION=	${_GST_VERSION}
BASE_DISTNAME=		gst-plugins-base-${BASE_PORTVERSION}
BASE_DISTFILE=		${BASE_DISTNAME}${EXTRACT_SUFX}
BAD_PORTVERSION=	${_GST_VERSION}
BAD_DISTNAME=		gst-plugins-bad-${BAD_PORTVERSION}
BAD_DISTFILE=		${BAD_DISTNAME}${EXTRACT_SUFX}
GOOD_PORTVERSION=	${_GST_VERSION}
GOOD_DISTNAME=		gst-plugins-good-${GOOD_PORTVERSION}
GOOD_DISTFILE=		${GOOD_DISTNAME}${EXTRACT_SUFX}
UGLY_PORTVERSION=	${_GST_VERSION}
UGLY_DISTNAME=		gst-plugins-ugly-${UGLY_PORTVERSION}
UGLY_DISTFILE=		${UGLY_DISTNAME}${EXTRACT_SUFX}
DEFAULT_AUDIOSINK?=	osssink
DEFAULT_AUDIOSRC?=	osssrc
DIST?=			base
GST_PLUGIN?=		base

# Include bsd.port.options.mk and not bsd.port.pre.mk to be able to use USES
.include <bsd.port.options.mk>

.if ${GST_PLUGIN} == "base"
NO_GSTREAMER_COMMON=	yes

BASE_GST_ENABLED_PLUGINS=	adder \
				allocators \
				app \
				audio \
				audioconvert \
				audiomixer \
				audiorate \
				audioresample \
				audiotestsrc \
				compositor \
				debugutils \
				dsd \
				encoding \
				fft \
				gio \
				nls \
				overlaycomposition \
				pbtypes \
				pkgconfig \
				pbutils \
				playback \
				rawparse \
				riff \
				rtp \
				rtsp \
				sdp \
				subparse \
				tag \
				tcp \
				tools \
				typefind \
				video \
				videoconvertscale \
				videorate \
				videotestsrc \
				volume
.endif

.if ${DIST} == "base" || ${DIST} == "ugly"
MESON_ARGS+=	-Ddefaultaudiosink="${DEFAULT_AUDIOSINK}" \
		-Ddefaultaudiosrc="${DEFAULT_AUDIOSRC}"
.endif

.include "${MASTERDIR}/Makefile.common"

.if ${DIST} == "base"
EXTRACT_ONLY=	${BASE_DISTFILE}
WRKSRC=		${WRKDIR}/${BASE_DISTNAME}
PORTVERSION=	${BASE_PORTVERSION}
DISTFILES+=	${BASE_DISTFILE}:base
PATCHDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins/files
LIB_DEPENDS+=	libdrm.so:graphics/libdrm
.elif ${DIST} == "bad"
EXTRACT_ONLY=	${BAD_DISTFILE}
WRKSRC=		${WRKDIR}/${BAD_DISTNAME}
PORTVERSION=	${BAD_PORTVERSION}
DISTFILES+=	${BAD_DISTFILE}:bad
PATCHDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins-bad/files
.elif ${DIST} == "ugly"
EXTRACT_ONLY=	${UGLY_DISTFILE}
WRKSRC=		${WRKDIR}/${UGLY_DISTNAME}
PORTVERSION=	${UGLY_PORTVERSION}
DISTFILES+=	${UGLY_DISTFILE}:ugly
PATCHDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins-ugly/files
.elif ${DIST} == "good"
EXTRACT_ONLY=	${GOOD_DISTFILE}
WRKSRC=		${WRKDIR}/${GOOD_DISTNAME}
PORTVERSION=	${GOOD_PORTVERSION}
DISTFILES+=	${GOOD_DISTFILE}:good
PATCHDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins-good/files
.elif ${DIST} == "makesum"
DISTFILES+=	${BASE_DISTFILE}:base ${BAD_DISTFILE}:bad \
		${UGLY_DISTFILE}:ugly ${GOOD_DISTFILE}:good
.else
BROKEN=		unknown DIST setting
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gstreamer-${_GST1_LIB_VER}

makesum-all:
	@${MAKE} DIST=makesum makesum

.include <bsd.port.mk>
