# New ports collection makefile for:	gstreamer plugins
# Date created:		Wed Jul 10 23:38:01 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.8.8
PORTREVISION?=	2
CATEGORIES?=	multimedia audio
MASTER_SITES=	${MASTER_SITE_GNOME} \
		http://gstreamer.freedesktop.org/src/gst-plugins/
MASTER_SITE_SUBDIR=	sources/gst-plugins/0.8
PKGNAMESUFFIX=	-plugins${GST_PLUGIN_SUFFIX}
DISTNAME=	gst-plugins-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	lioux@FreeBSD.org
COMMENT?=	GStreamer written collection of plugins handling several media types

LIB_DEPENDS+=	gstreamer-0.8.5:${PORTSDIR}/multimedia/gstreamer \
		popt.0:${PORTSDIR}/devel/popt

SHLIB_VERSION=	1
VERSION=	0.8

WANT_GSTREAMER=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME+=	gnomehack \
		gnomeprefix \
		pkgconfig \
		gconf2
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
GST_PLUGIN?=	base

CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG} \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${X11BASE}/lib -L${LOCALBASE}/lib ${EXTRA_LIBS} ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${GST_PLUGIN} == "base"
GCONF_SCHEMAS=	gstreamer-0.8.schemas

INSTALLS_SHLIB=	yes

PLIST_SUB=	VERSION="${VERSION}" \
		SHLIB_VERSION="${SHLIB_VERSION}"

MAN1=		gst-launch-ext-0.8.1 gst-visualise-0.8.1

## Additional directories which should be both built and installed
## but configure neglected to correctly identify them
# cdrom/vcd support
EXTRA_BUILD_DIR+=	sys/vcd
# modplug
EXTRA_BUILD_DIR+=	gst/modplug
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

post-extract:
# for cdrom/vcd support
# taken from mplayer distfile
# MD5 (MPlayer-1.0pre4.tar.bz2) = 83ebac0f05b192516a41fca2350ca01a
	@${CP} ${FILESDIR}/bsdi_dvd.h ${WRKSRC}/sys/vcd/

post-patch:
	@${FIND} ${WRKSRC} -type f | \
	${XARGS} -n 10 ${REINPLACE_CMD} -e \
	's|malloc\.h|stdlib.h|; \
	 s|stdint\.h|inttypes.h|; \
	 s|%%VERSION%%|${VERSION}|'
# cdrom default device
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|' \
		${WRKSRC}/ext/cdparanoia/gstcdparanoia.c \
		${WRKSRC}/sys/cdrom/gstcdplayer.c \
		${WRKSRC}/sys/vcd/vcdsrc.c
# dvd default device
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/ext/dvdnav/dvdnavsrc.c \
		${WRKSRC}/ext/dvdread/dvdreadsrc.c
# cdrom/vcd support
	@${REINPLACE_CMD} -e 's|<linux/cdrom.h>|"bsdi_dvd.h"|' \
		${WRKSRC}/sys/cdrom/gstcdplayer_ioctl.c \
		${WRKSRC}/sys/vcd/vcdsrc.c \
		${WRKSRC}/sys/vcd/vcdsrc.h
# mplex fix -- gst configure does not use mjpegtool's config to find include.
	@${REINPLACE_CMD} -E \
		-e 's|PFLAGS@|PFLAGS@ -I${LOCALBASE}/include/mjpegtools -I${LOCALBASE}/include/mjpegtools/mplex|' \
		${WRKSRC}/ext/mplex/Makefile.in
.if ${CXXFLAGS:M*=athlon-4} || ${CXXFLAGS:M*=athlon-mp} || ${CXXFLAGS:M*=athlon-xp}
# Fix gst-register when using -O -march=athlon-xp
	@${REINPLACE_CMD} -e 's|@CXXF|-fgcse @CXXF|g' \
		${WRKSRC}/gst/modplug/Makefile.in \
		${WRKSRC}/gst/modplug/libmodplug/Makefile.in
.endif

pre-build:
# This port cannot be CFLAGS safe, when using p4 optimizations
# because it breaks the mod plugin
	@${REINPLACE_CMD} -E \
		-e 's|(-march=pentiu)m4|\1m3|g' \
		-e 's|(-mcpu=pentiu)m4|\1m3|g' \
		-e 's|(-mtune=pentiu)m)4|\1m3|g' \
		${WRKSRC}/gst/modplug/Makefile \
		${WRKSRC}/gst/modplug/libmodplug/Makefile

post-build:
.ifdef(EXTRA_BUILD_DIR)
. for dir in ${EXTRA_BUILD_DIR}
	@cd ${WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
. endfor
.endif
#	@${ECHO_CMD} "@unexec ${PREFIX}/bin/gst-register-${GST_VERSION} \
#		--gst-registry=${PREFIX}/share/gnome/cache/gstreamer-${GST_VERSION}/registry.xml \
#		>> ${TMPPLIST}"

post-install:
.ifdef(EXTRA_BUILD_DIR)
. for dir in ${EXTRA_BUILD_DIR}
	@cd ${WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
. endfor
.endif
# register plugins
	-@${X11BASE}/bin/gst-register-${GST_VERSION} \
		--gst-registry=${PREFIX}/share/gnome/cache/gstreamer-${GST_VERSION}/registry.xml 2>/dev/null

.include "${MASTERDIR}/Makefile.common"
.include <bsd.port.post.mk>
