# New ports collection makefile for:	gstreamer plugins
# Date created:		Wed Jul 10 23:38:01 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/multimedia/gstreamer-plugins/Makefile,v 1.86 2006/06/09 18:13:48 ahze Exp $
#

PORTNAME=	gstreamer
PORTVERSION?=	${BASE_PORTVERSION}
PORTREVISION?=	0
PORTEPOCH=	1
CATEGORIES?=	multimedia audio
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-plugins-base/:base \
		http://gstreamer.freedesktop.org/src/gst-plugins-bad/:bad \
		http://gstreamer.freedesktop.org/src/gst-plugins-good/:good \
		http://gstreamer.freedesktop.org/src/gst-plugins-ugly/:ugly \
		${MASTER_SITE_LOCAL:S|$|ahze/:base|} \
		${MASTER_SITE_LOCAL:S|$|ahze/:good|} \
		${MASTER_SITE_LOCAL:S|$|ahze/:bad|} \
		${MASTER_SITE_LOCAL:S|$|ahze/:ugly|}
PKGNAMESUFFIX=	-plugins${GST_PLUGIN_SUFFIX}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT?=	GStreamer written collection of plugins handling several media types

LIB_DEPENDS+=	gstreamer-0.10.0:${PORTSDIR}/multimedia/gstreamer \
		popt.0:${PORTSDIR}/devel/popt \
		oil-0.3.1:${PORTSDIR}/devel/liboil

BASE_PORTVERSION=	0.10.9
BASE_DISTNAME=		gst-plugins-base-${BASE_PORTVERSION}
BASE_DISTFILE=		${BASE_DISTNAME}${EXTRACT_SUFX}
BAD_PORTVERSION=	0.10.3
BAD_DISTNAME=		gst-plugins-bad-${BAD_PORTVERSION}
BAD_DISTFILE=		${BAD_DISTNAME}${EXTRACT_SUFX}
GOOD_PORTVERSION=	0.10.3
GOOD_DISTNAME=		gst-plugins-good-${GOOD_PORTVERSION}
GOOD_DISTFILE=		${GOOD_DISTNAME}${EXTRACT_SUFX}
UGLY_PORTVERSION=	0.10.3
UGLY_DISTNAME=		gst-plugins-ugly-${UGLY_PORTVERSION}
UGLY_DISTFILE=		${UGLY_DISTNAME}${EXTRACT_SUFX}
DIST?=		good

SHLIB_VERSION=	1
USE_GETTEXT=	yes
VERSION=	${GST_VERSION}
WANT_GSTREAMER=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME+=	gnomehack gnometarget pkgconfig ltverhack
USE_AUTOTOOLS=	libtool:15
GST_PLUGIN?=	base

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${X11BASE}/lib -L${LOCALBASE}/lib ${EXTRA_LIBS} ${PTHREAD_LIBS}"

DEFAULT_AUDIOSINK?=	osssink
DEFAULT_AUDIOSRC?=	osssrc

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	many plugins don't build or even work on 4.x
.endif

.if ${GST_PLUGIN} == "base"
DIST=	base
NO_GSTREAMER_COMMON=	yes
INSTALLS_SHLIB=	yes
MAN1=		gst-visualise-0.10.1
PLIST_SUB+=	VERSION="${VERSION}" \
		SHLIB_VERSION="${SHLIB_VERSION}"
.else
USE_GSTREAMER=	yes
.endif

.include "${MASTERDIR}/Makefile.common"

# cdrom default device
.ifdef(WITH_CDROM_DEVICE)
DEFAULT_CDROM_DEVICE=${WITH_CDROM_DEVICE}
.else
. if ${OSVERSION} < 500000
DEFAULT_CDROM_DEVICE=/dev/acd0c
. else
DEFAULT_CDROM_DEVICE=/dev/acd0
. endif
.endif

# dvd default device
.ifdef(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
. if ${OSVERSION} < 500000
DEFAULT_DVD_DEVICE=/dev/acd0c
. else
DEFAULT_DVD_DEVICE=/dev/acd0
. endif
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f | \
	${XARGS} -n 10 ${REINPLACE_CMD} -e \
	's|malloc\.h|stdlib.h|; \
	 s|stdint\.h|inttypes.h|; \
	 s|%%VERSION%%|${VERSION}|'
	@${FIND} ${WRKSRC}/ext -name Makefile.in | \
	${XARGS} -n 10 ${REINPLACE_CMD} -e \
	's|$$(top_builddir)/gst-libs/gst/tag/libgsttag-$$(GST_MAJORMINOR).la|${X11BASE}/lib/libgsttag-@GST_MAJORMINOR@.la|; \
	s|$$(top_builddir)/gst-libs/gst/audio/libgstaudio-$$(GST_MAJORMINOR).la|${X11BASE}/lib/libgstaudio-@GST_MAJORMINOR@.la|; \
	s|$$(top_builddir)/gst-libs/gst/riff/libgstriff-$$(GST_MAJORMINOR).la|${X11BASE}/lib/libgstriff-@GST_MAJORMINOR@.la|; \
	s|$$(top_builddir)/gst-libs/gst/cdda/libgstcdda-$$(GST_MAJORMINOR).la|${X11BASE}/lib/libgstcdda-@GST_MAJORMINOR@.la|'
	 @${FIND} ${WRKSRC}/ext -name Makefile.in | \
	 ${XARGS} -n 10 ${REINPLACE_CMD} -e \
	 's|$$(top_builddir)/gst-libs/gst/tag/libgsttag-@GST_MAJORMINOR@.la|${X11BASE}/lib/libgsttag-@GST_MAJORMINOR@.la|; \
	  s|$$(top_builddir)/gst-libs/gst/audio/libgstaudio-@GST_MAJORMINOR@.la|${X11BASE}/lib/libgstaudio-@GST_MAJORMINOR@.la|; \
	  s|$$(top_builddir)/gst-libs/gst/riff/libgstriff-@GST_MAJORMINOR@.la|${X11BASE}/lib/libgstriff-@GST_MAJORMINOR@.la|; \
	  s|$$(top_builddir)/gst-libs/gst/cdda/libgstcdda-@GST_MAJORMINOR@.la|${X11BASE}/lib/libgstcdda-@GST_MAJORMINOR@.la|'
	@${REINPLACE_CMD} -e 's|DEFAULT_AUDIOSINK="alsasink"|DEFAULT_AUDIOSINK="${DEFAULT_AUDIOSINK}"|; \
		s|DEFAULT_AUDIOSRC="alsasrc"|DEFAULT_AUDIOSRC="${DEFAULT_AUDIOSRC}"|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
