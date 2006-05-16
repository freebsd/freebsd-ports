# New ports collection makefile for:	gstreamer plugins
# Date created:		Wed Jul 10 23:38:01 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-plugins80/Makefile,v 1.60 2006/04/23 22:55:30 mezz Exp $
#

PORTNAME=	gstreamer
PORTVERSION=	0.8.12
PORTREVISION?=	2
CATEGORIES?=	multimedia audio
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://gstreamer.freedesktop.org/src/gst-plugins/
MASTER_SITE_SUBDIR=	ahze
PKGNAMESUFFIX=	-plugins${GST_PLUGIN_SUFFIX}80
DISTNAME=	gst-plugins-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	GStreamer written collection of plugins handling several media types

LIB_DEPENDS+=	gstreamer-0.8.5:${PORTSDIR}/multimedia/gstreamer80 \
		popt.0:${PORTSDIR}/devel/popt

SHLIB_VERSION=	1
VERSION=	0.8

WANT_GSTREAMER=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME+=	gnomehack \
		gnomeprefix \
		gnometarget \
		pkgconfig
GNU_CONFIGURE=	yes
GST_PLUGIN?=	base

CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG} \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${X11BASE}/lib -L${LOCALBASE}/lib ${EXTRA_LIBS} ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>
.include "${MASTERDIR}/Makefile.common"

.if !defined(WITH_CPUFLAGS)
WITHOUT_CPU_CFLAGS=	yes
.endif

.if ${GST_PLUGIN} == "base"

INSTALLS_SHLIB=	yes

PLIST_SUB+=	VERSION="${VERSION}" \
		SHLIB_VERSION="${SHLIB_VERSION}"

MAN1=		gst-launch-ext-0.8.1 gst-visualise-0.8.1

## Additional directories which should be both built and installed
## but configure neglected to correctly identify them
# cdrom/vcd support
EXTRA_BUILD_DIR+=	sys/vcd
# modplug
EXTRA_BUILD_DIR+=	gst/modplug
.else
.for f in ${GST_PLUGIN_DIR}
GST_PLUGIN_MAKEFILES+=	${f}/Makefile
.endfor
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
.if ${GST_PLUGIN}!="base"
	@${REINPLACE_CMD} -E -e 's|ac_config_files=\"*\"|ac_config_files="$$ac_config_files Makefile ${GST_PLUGIN_MAKEFILES}" #|' \
		${WRKSRC}/configure
.else
.for f in ${GST_ALL_PLUGINS}
	@${REINPLACE_CMD} -e 's|ext/${f}/Makefile||g' \
		${WRKSRC}/configure
.endfor
.endif

post-build:
.ifdef(EXTRA_BUILD_DIR)
. for dir in ${EXTRA_BUILD_DIR}
	@cd ${WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
. endfor
.endif

post-install:
.ifdef(EXTRA_BUILD_DIR)
. for dir in ${EXTRA_BUILD_DIR}
	@cd ${WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
. endfor
.endif
# register plugins
	-@${X11BASE}/bin/gst-register-${VERSION} \
		--gst-registry=${PREFIX}/share/gnome/cache/gstreamer-${VERSION}/registry.xml 2>/dev/null

.include <bsd.port.post.mk>
