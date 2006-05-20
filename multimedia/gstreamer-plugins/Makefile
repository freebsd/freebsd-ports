# New ports collection makefile for:	gstreamer plugins
# Date created:		Wed Jul 10 23:38:01 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/multimedia/gstreamer-plugins/Makefile,v 1.80 2006/04/28 12:00:14 ahze Exp $
#

PORTNAME=	gstreamer
PORTVERSION?=	0.10.7
## SET BACK TO PORTREVISION?= when we reset PORTREVISION in all the gst plugin ports
CATEGORIES?=	multimedia audio
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-plugins-base/:base \
		${MASTER_SITE_GNOME:S|$|sources/gst-plugins-base/0.10/:base|} \
		${MASTER_SITE_LOCAL:S|$|ahze/:base|} \
		${MASTER_SITE_LOCAL:S|$|ahze/:good|} \
		${MASTER_SITE_LOCAL:S|$|ahze/:bad|} \
		${MASTER_SITE_LOCAL:S|$|ahze/:ugly|} \
		http://gstreamer.freedesktop.org/src/gst-plugins-bad/:bad \
		${MASTER_SITE_GNOME:S|$|sources/gst-plugins-good/0.10/:good|} \
		http://gstreamer.freedesktop.org/src/gst-plugins-good/:good \
		http://gstreamer.freedesktop.org/src/gst-plugins-ugly/:ugly \
		http://people.freebsd.org/~ahze/distfiles/:good \
		http://people.freebsd.org/~ahze/distfiles/:bad \
		http://people.freebsd.org/~ahze/distfiles/:ugly \
		http://people.freebsd.org/~ahze/distfiles/:base
PKGNAMESUFFIX=	-plugins${GST_PLUGIN_SUFFIX}
DISTFILES=	${BASE_DISTFILE}:base \
		${BAD_DISTFILE}:bad \
		${GOOD_DISTFILE}:good \
		${UGLY_DISTFILE}:ugly
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	GStreamer written collection of plugins handling several media types

LIB_DEPENDS+=	gstreamer-0.10.0:${PORTSDIR}/multimedia/gstreamer \
		popt.0:${PORTSDIR}/devel/popt \
		oil-0.3.1:${PORTSDIR}/devel/liboil

BASE_PORTVERSION=	${PORTVERSION}
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

SHLIB_VERSION=	1
USE_GETTEXT=	yes
VERSION=	${GST_VERSION}
WANT_GSTREAMER=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME+=	gnomehack gnomeprefix gnometarget pkgconfig ltverhack
USE_AUTOTOOLS=	libtool:15
GST_PLUGIN?=	base

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${X11BASE}/lib -L${LOCALBASE}/lib ${EXTRA_LIBS} ${PTHREAD_LIBS}"

DEFAULT_AUDIOSINK?=	osssink
DEFAULT_AUDIOSRC?=	osssrc

.include <bsd.port.pre.mk>
.include "${MASTERDIR}/Makefile.common"

.if !defined(WITH_CPUFLAGS)
#WITHOUT_CPU_CFLAGS=	yes
.endif

.if ${GST_PLUGIN} == "base"
INSTALLS_SHLIB=	yes
MAN1=		gst-visualise-0.10.1
WRKSRC=${WRKDIR}/${BASE_DISTNAME}
EXTRACT_ONLY=${BASE_DISTFILE}
PLIST_SUB+=	VERSION="${VERSION}" \
		SHLIB_VERSION="${SHLIB_VERSION}"
.endif

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

pre-everything::
.if !defined(WITH_CPUFLAGS)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you want to compile with CPUFLAGS"
	@${ECHO_MSG} "hit Ctrl+C now and use make \"WITH_CPUFLAGS=yes\""
	@${ECHO_MSG} "NOTE: This option may cause build, install, and/or"
	@${ECHO_MSG} "runtime failures. If this option does not work for you"
	@${ECHO_MSG} "please do not use it."
	@${ECHO_MSG} ""
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f | \
	${XARGS} -n 10 ${REINPLACE_CMD} -e \
	's|malloc\.h|stdlib.h|; \
	 s|stdint\.h|inttypes.h|; \
	 s|%%VERSION%%|${VERSION}|'
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
