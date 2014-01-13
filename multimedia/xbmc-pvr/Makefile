# Created by: Mickael Maillot <mickael.maillot@gmail.com>
# $FreeBSD$

PORTNAME=	xbmc
PORTVERSION=	70
PORTREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/nox
PKGNAMESUFFIX=	-pvr-ppa-odk
DISTNAME=	opdenkamp-${PORTNAME}${PKGNAMESUFFIX}${PORTVERSION}-0-g${GITHASH}

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

LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib	\
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libcdio.so:${PORTSDIR}/sysutils/libcdio	\
		libcurl.so:${PORTSDIR}/ftp/curl \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libenca.so:${PORTSDIR}/converters/enca \
		libGLEW.so:${PORTSDIR}/graphics/glew \
		libavcodec0.so:${PORTSDIR}/multimedia/ffmpeg0	\
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfribidi.so:${PORTSDIR}/converters/fribidi \
		liblzo2.so:${PORTSDIR}/archivers/lzo2 \
		libjasper.so:${PORTSDIR}/graphics/jasper \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libfaad.so:${PORTSDIR}/audio/faad \
		libmad.so:${PORTSDIR}/audio/libmad \
		libmodplug.so:${PORTSDIR}/audio/libmodplug \
		libmpeg2.so:${PORTSDIR}/multimedia/libmpeg2 \
		libogg.so:${PORTSDIR}/audio/libogg \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libpng15.so:${PORTSDIR}/graphics/png \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient	\
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libass.so:${PORTSDIR}/multimedia/libass \
		libwavpack.so:${PORTSDIR}/audio/wavpack \
		libyajl.so:${PORTSDIR}/devel/yajl \
		libplist.so:${PORTSDIR}/devel/libplist

RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		glxinfo:${PORTSDIR}/graphics/mesa-demos \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		xdpyinfo:${PORTSDIR}/x11/xdpyinfo

BROKEN=		no longer builds, use multimedia/xbmc and multimedia/xbmc-addon-pvr
DEPRECATED=	multimedia/xbmc and multimedia/xbmc-addon-pvr are newer
EXPIRATION_DATE=	2013-12-31
GITHASH=	9023e39
WRKSRC=		${WRKDIR}/opdenkamp-${PORTNAME}-${GITHASH}
USES=		iconv pkgconfig
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf libtool automake libltdl
GNU_CONFIGURE=	yes
USE_XORG=	xinerama xt xmu xtst
USE_GL=		glu
USE_SDL=	image mixer sdl
USE_MYSQL=	yes
USE_PYTHON=	2
NOPRECIOUSMAKEVARS=	yes
INSTALLS_ICONS=	yes
ONLY_FOR_ARCHS=	i386 amd64
USE_LDCONFIG=	${PREFIX}/lib/xbmc/system \
		${PREFIX}/lib/xbmc/system/players/dvdplayer \
		${PREFIX}/lib/xbmc/system/players/paplayer
CONFLICTS_INSTALL=	xbmc-[0-9]*

PLIST_SUB+=	PYVER="${PYTHON_VERSION:S/python//:S/.//g}"

OPTIONS_DEFINE=	AVAHI LIBBLURAY FAAC HAL LIRC MMS NONFREE PULSEAUDIO RTMP \
		VAAPI VDPAU XRANDR WEBSERVER
MMS_DESC=	Enable mms:// & mmsh:// support
NONFREE_DESC=	Enable non-free components (rar, ccx, ffmpeg)
OPTIONS_DEFAULT=	AVAHI LIBBLURAY HAL MMS XRANDR

DESKTOP_ENTRIES="XBMC" \
		"${COMMENT}" \
		"${DATADIR}/media/icon.png" \
		"xbmc" \
		"AudioVideo;Video;" \
		true

CPPFLAGS+=	-I${LOCALBASE}/include/ffmpeg0
CXXFLAGS+=	-I${LOCALBASE}/include/ffmpeg0
CFLAGS+=	-I${LOCALBASE}/include/ffmpeg0
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=	--enable-external-libraries

NO_STAGE=	yes
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

.if ${PORT_OPTIONS:MAVAHI}
CONFIGURE_ARGS+=	--enable-avahi
LIB_DEPENDS+=	libavahi-common.so:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if ${PORT_OPTIONS:MLIBBLURAY}
CONFIGURE_ARGS+=	--enable-libbluray
LIB_DEPENDS+=	libbluray.so:${PORTSDIR}/multimedia/libbluray
.else
CONFIGURE_ARGS+=	--disable-libbluray
.endif

.if ${PORT_OPTIONS:MFAAC}
CONFIGURE_ARGS+=	--enable-faac
LIB_DEPENDS+=	libfaac.so:${PORTSDIR}/audio/faac
.else
CONFIGURE_ARGS+=	--disable-faac
.endif

.if ${PORT_OPTIONS:MHAL}
CONFIGURE_ARGS+=	--enable-hal
LIB_DEPENDS+=	libhal.so:${PORTSDIR}/sysutils/hal
.else
CONFIGURE_ARGS+=	--disable-hal
.endif

.if ${PORT_OPTIONS:MLIRC}
RUN_DEPENDS+=	lircd:${PORTSDIR}/comms/lirc
.endif

.if ${PORT_OPTIONS:MMMS}
CONFIGURE_ARGS+=	--enable-libmms
LIB_DEPENDS+=	libmms.so:${PORTSDIR}/net/libmms
.else
CONFIGURE_ARGS+=	--disable-libmms
.endif

.if ${PORT_OPTIONS:MNONFREE}
CONFIGURE_ARGS+=	--enable-non-free
NO_CDROM=	Restricted binary distribution
NO_PACKAGE=	${NO_CDROM}
.else
CONFIGURE_ARGS+=	--disable-non-free
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
CONFIGURE_ARGS+=	--enable-pulse
LIB_DEPENDS+=	libpulse.so:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

.if ${PORT_OPTIONS:MRTMP}
CONFIGURE_ARGS+=	--enable-rtmp
LIB_DEPENDS+=	librtmp.so:${PORTSDIR}/multimedia/librtmp
.else
CONFIGURE_ARGS+=	--disable-rtmp
.endif

.if ${PORT_OPTIONS:MVAAPI}
LIB_DEPENDS+=	libva.so:${PORTSDIR}/multimedia/libva
CONFIGURE_ARGS+=	--enable-vaapi
.else
CONFIGURE_ARGS+=	--disable-vaapi
.endif

.if ${PORT_OPTIONS:MVDPAU}
LIB_DEPENDS+=	libvdpau.so:${PORTSDIR}/multimedia/libvdpau
CONFIGURE_ARGS+=	--enable-vdpau
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

.if ${PORT_OPTIONS:MWEBSERVER}
CONFIGURE_ARGS+=	--enable-webserver
LIB_DEPENDS+=	libmicrohttpd.so:${PORTSDIR}/www/libmicrohttpd
PLIST_SUB+=	HTTPD=""
.else
CONFIGURE_ARGS+=	--disable-webserver
PLIST_SUB+=	HTTPD="@comment "
.endif

.if ${PORT_OPTIONS:MXRANDR}
CONFIGURE_ARGS+=	--enable-xrandr
USE_XORG+=	xrandr
PLIST_SUB+=	XRANDR=""
.else
CONFIGURE_ARGS+=	--disable-xrandr
PLIST_SUB+=	XRANDR="@comment "
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
	@${REINPLACE_CMD} \
		-e 's|libavcodec |libavcodec0 |g' \
		-e 's|libavfilter |libavfilter0 |g' \
		-e 's|libavformat |libavformat0 |g' \
		-e 's|libavutil |libavutil0 |g' \
		-e 's|libpostproc |libpostproc0 |g' \
		-e 's|libswscale"|libswscale0"|g' \
		-e 's|avcodec\]|avcodec0\]|g' \
		${WRKSRC}/configure.in
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
