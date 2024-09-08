PORTNAME=	gstreamer
PORTVERSION?=	${BASE_PORTVERSION}
# plug-in port instead, like ${category}/gstreamer1-plugin-${PLUGIN}.
PORTREVISION?=	2
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

PORTSCOUT=	limitw:1,even

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
DIST?=		base

USES+=		meson cpe gettext gnome gstreamer libtool pathfix pkgconfig python:build tar:xz
USE_GNOME+=	glib20 introspection:build libxml2
GST_PLUGIN?=	base
USE_LDCONFIG=	yes
MESON_ARGS+=	--auto-features=auto # XXX bug 270361 workaround

CPE_VENDOR=	gstreamer_project
CPE_PRODUCT=	gstreamer

CFLAGS+=	-Wno-format
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib ${EXTRA_LIBS}

DEFAULT_AUDIOSINK?=	osssink
DEFAULT_AUDIOSRC?=	osssrc

.if ${DIST}==""
IGNORE=		DIST not specified
.endif

VERSION=	1.0
SOVERSION=	0.2210.0
PLIST_SUB+=	VERSION="${VERSION}" \
		SOVERSION="${SOVERSION}"

# Include bsd.port.options.mk and not bsd.port.pre.mk to be able to use USES
.include <bsd.port.options.mk>

.if ${GST_PLUGIN} == "base"
DIST=	base
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

.if ${DIST} == base || ${DIST} == ugly
CONFIGURE_ARGS+= -Ddefaultaudiosink="${DEFAULT_AUDIOSINK}" \
		-Ddefaultaudiosrc="${DEFAULT_AUDIOSRC}"
.endif

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

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gstreamer-${VERSION}

.include <bsd.port.mk>
