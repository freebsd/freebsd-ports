# New ports collection makefile for:    xbmc
# Date created:				2010-09-16
# Whom: 				Mickael Maillot <mickael.maillot@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xbmc
PORTVERSION=	65
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/nox
PKGNAMESUFFIX=	-pvr-ppa-odk
DISTNAME=	opdenkamp-${PORTNAME}-Eden-pvr_beta2-0-g${GITHASH}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	XBMC is an award winning media center application - PVR branch

LICENSE=	GPLv2

BUILD_DEPENDS=	enca:${PORTSDIR}/converters/enca \
		gawk:${PORTSDIR}/lang/gawk \
		gperf:${PORTSDIR}/devel/gperf \
		cmake:${PORTSDIR}/devel/cmake \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		nasm:${PORTSDIR}/devel/nasm \
		dvdread-config:${PORTSDIR}/multimedia/libdvdread

LIB_DEPENDS=	asound.2:${PORTSDIR}/audio/alsa-lib	\
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		cdio.13:${PORTSDIR}/sysutils/libcdio	\
		curl.6:${PORTSDIR}/ftp/curl \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		enca.5:${PORTSDIR}/converters/enca \
		GLEW.1:${PORTSDIR}/graphics/glew \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg	\
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fribidi.3:${PORTSDIR}/converters/fribidi \
		lzo2.2:${PORTSDIR}/archivers/lzo2 \
		jasper.4:${PORTSDIR}/graphics/jasper \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		faad.2:${PORTSDIR}/audio/faad \
		mad:${PORTSDIR}/audio/libmad \
		modplug:${PORTSDIR}/audio/libmodplug \
		mpeg2:${PORTSDIR}/multimedia/libmpeg2 \
		ogg.7:${PORTSDIR}/audio/libogg \
		pcre.1:${PORTSDIR}/devel/pcre \
		png.6:${PORTSDIR}/graphics/png \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		smbclient.0:${PORTSDIR}/net/samba-libsmbclient	\
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		ass.5:${PORTSDIR}/multimedia/libass \
		wavpack.2:${PORTSDIR}/audio/wavpack \
		yajl:${PORTSDIR}/devel/yajl \
		plist:${PORTSDIR}/devel/libplist

RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3 \
		glxinfo:${PORTSDIR}/graphics/mesa-demos \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		xdpyinfo:${PORTSDIR}/x11/xdpyinfo

GITHASH=	cbe2cf3
WRKSRC=		${WRKDIR}/opdenkamp-${PORTNAME}-${GITHASH}
FETCH_ARGS=	-Fpr
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	autoconf libtool automake libltdl
GNU_CONFIGURE=	yes
USE_XORG=	xinerama xt xmu xrandr xtst
USE_GL=		glu
USE_SDL=	image mixer sdl
USE_MYSQL=	yes
USE_PYTHON=	2.5-2.7
MAKE_JOBS_SAFE=	yes
NOPRECIOUSMAKEVARS=	yes
INSTALLS_ICONS=	yes
ONLY_FOR_ARCHS=	i386 amd64
USE_LDCONFIG=	${PREFIX}/lib/xbmc/system \
		${PREFIX}/lib/xbmc/system/players/dvdplayer \
		${PREFIX}/lib/xbmc/system/players/paplayer
CONFLICTS_INSTALL=	xbmc-[0-9]*

PLIST_SUB+=	PYVER="${PYTHON_VERSION:S/python//:S/.//g}"

OPTIONS=	AVAHI		"Enable Avahi support"			on \
		LIBBLURAY	"Enable libbluray support"		on \
		FAAC		"Enable FAAC support"			off \
		HAL		"Enable HAL support"			on \
		LIRC		"Enable lirc support"			off \
		MMS		"Enable mms:// & mmsh:// support"	on \
		NONFREE		"Enable non-free components (rar, ccx, ffmpeg)"	off \
		PULSE		"Enable PulseAudio support"		off \
		RTMP		"RTMP support via librtmp"		off \
		VAAPI		"Enable VAAPI support"			off \
		VDPAU		"Enable VDPAU support"			off \
		WEBSERVER	"Build Internal Webserver"		off

DESKTOP_ENTRIES="XBMC" \
		"${COMMENT}" \
		"${DATADIR}/media/icon.png" \
		"xbmc" \
		"AudioVideo;Video;" \
		true

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=	--enable-external-libraries

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if ${ARCH} == i386
PLIST_SUB+=	ARCH="x86"
.else
PLIST_SUB+=	ARCH="x86_64"
.endif

.if !defined(WITHOUT_AVAHI)
CONFIGURE_ARGS+=	--enable-avahi
LIB_DEPENDS+=	avahi-common.3:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if !defined(WITHOUT_LIBBLURAY)
CONFIGURE_ARGS+=	--enable-libbluray
LIB_DEPENDS+=	bluray.0:${PORTSDIR}/multimedia/libbluray
.else
CONFIGURE_ARGS+=	--disable-libbluray
.endif

.if defined(WITH_FAAC)
CONFIGURE_ARGS+=	--enable-faac
LIB_DEPENDS+=	faac.0:${PORTSDIR}/audio/faac
.else
CONFIGURE_ARGS+=	--disable-faac
.endif

.if !defined(WITHOUT_HAL)
CONFIGURE_ARGS+=	--enable-hal
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.else
CONFIGURE_ARGS+=	--disable-hal
.endif

.if defined(WITH_LIRC)
RUN_DEPENDS+=	lircd:${PORTSDIR}/comms/lirc
.endif

.if !defined(WITHOUT_MMS)
CONFIGURE_ARGS+=	--enable-libmms
LIB_DEPENDS+=	mms.0:${PORTSDIR}/net/libmms
.else
CONFIGURE_ARGS+=	--disable-libmms
.endif

.if defined(WITH_NONFREE)
CONFIGURE_ARGS+=	--enable-non-free
NO_CDROM=	Restricted binary distribution
NO_PACKAGE=	${NO_CDROM}
.else
CONFIGURE_ARGS+=	--disable-non-free
.endif

.if defined(WITH_PULSE)
CONFIGURE_ARGS+=	--enable-pulse
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

.if defined(WITH_RTMP)
CONFIGURE_ARGS+=	--enable-rtmp
LIB_DEPENDS+=	rtmp.0:${PORTSDIR}/multimedia/rtmpdump
.else
CONFIGURE_ARGS+=	--disable-rtmp
.endif

.if defined(WITH_VAAPI)
LIB_DEPENDS+=	va.1:${PORTSDIR}/multimedia/libva
CONFIGURE_ARGS+=	--enable-vaapi
.else
CONFIGURE_ARGS+=	--disable-vaapi
.endif

.if defined(WITH_VDPAU)
LIB_DEPENDS+=	vdpau.1:${PORTSDIR}/multimedia/libvdpau
CONFIGURE_ARGS+=	--enable-vdpau
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

.if defined(WITH_WEBSERVER)
CONFIGURE_ARGS+=	--enable-webserver
LIB_DEPENDS+=	microhttpd.23:${PORTSDIR}/www/libmicrohttpd
PLIST_SUB+=	HTTPD=""
.else
CONFIGURE_ARGS+=	--disable-webserver
PLIST_SUB+=	HTTPD="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure.in \
		${WRKSRC}/lib/asap/Makefile.in \
		${WRKSRC}/lib/libdvd/libdvdnav/configure.ac \
		${WRKSRC}/lib/libdvd/libdvdnav/configure2 \
		${WRKSRC}/lib/libdvd/libdvdread/configure.ac \
		${WRKSRC}/lib/libdvd/libdvdread/configure2 \
		${WRKSRC}/lib/libsidplay2/libsidplay/unix/my_macros.m4 \
		${WRKSRC}/lib/timidity/configure.in \
		${WRKSRC}/xbmc/screensavers/rsxs-0.9/acinclude.m4
	${RM} ${WRKSRC}/addons/library.xbmc.addon/libXBMC_addon.h.orig
# XXX somehow there are still references to linux libraries, if you find
# where they come from please tell us!
.if ${ARCH} == "amd64"
	${LN} -s libXBMC_addon-x86_64-freebsd.so ${WRKSRC}/addons/library.xbmc.addon/libXBMC_addon-x86_64-linux.so
	${LN} -s libXBMC_gui-x86_64-freebsd.so ${WRKSRC}/addons/library.xbmc.gui/libXBMC_gui-x86_64-linux.so
	${LN} -s libXBMC_pvr-x86_64-freebsd.so ${WRKSRC}/addons/library.xbmc.pvr/libXBMC_pvr-x86_64-linux.so
.else
	${LN} -s libXBMC_addon-x86-freebsd.so ${WRKSRC}/addons/library.xbmc.addon/libXBMC_addon-x86-linux.so
	${LN} -s libXBMC_gui-x86-freebsd.so ${WRKSRC}/addons/library.xbmc.gui/libXBMC_gui-x86-linux.so
	${LN} -s libXBMC_pvr-x86-freebsd.so ${WRKSRC}/addons/library.xbmc.pvr/libXBMC_pvr-x86-linux.so
.endif

pre-configure:
	cd ${WRKSRC} && ./bootstrap

post-install:
# XXX somehow there are still references to linux libraries, if you find
# where they come from please tell us!
.if ${ARCH} == "amd64"
	${LN} -s libXBMC_addon-x86_64-freebsd.so ${PREFIX}/lib/xbmc/addons/library.xbmc.addon/libXBMC_addon-x86_64-linux.so
	${LN} -s libXBMC_gui-x86_64-freebsd.so ${PREFIX}/lib/xbmc/addons/library.xbmc.gui/libXBMC_gui-x86_64-linux.so
	${LN} -s libXBMC_pvr-x86_64-freebsd.so ${PREFIX}/lib/xbmc/addons/library.xbmc.pvr/libXBMC_pvr-x86_64-linux.so
.else
	${LN} -s libXBMC_addon-x86-freebsd.so ${PREFIX}/lib/xbmc/addons/library.xbmc.addon/libXBMC_addon-x86-linux.so
	${LN} -s libXBMC_gui-x86-freebsd.so ${PREFIX}/lib/xbmc/addons/library.xbmc.gui/libXBMC_gui-x86-linux.so
	${LN} -s libXBMC_pvr-x86-freebsd.so ${PREFIX}/lib/xbmc/addons/library.xbmc.pvr/libXBMC_pvr-x86-linux.so
.endif

.include <bsd.port.post.mk>
