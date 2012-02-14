# New ports collection makefile for:    xbmc
# Date created:				2010-09-16
# Whom: 				Mickael Maillot <mickael.maillot@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xbmc
PORTVERSION=	11.0.b2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://mirrors.xbmc.org/releases/source/
DISTNAME=	${PORTNAME}-11.0-Eden_beta2

MAINTAINER=	mickael.maillot@gmail.com
COMMENT=	XBMC is an award winning media center application

LICENSE=	GPLv2

BUILD_DEPENDS=	enca:${PORTSDIR}/converters/enca \
		gawk:${PORTSDIR}/lang/gawk \
		gperf:${PORTSDIR}/devel/gperf \
		cmake:${PORTSDIR}/devel/cmake \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		nasm:${PORTSDIR}/devel/nasm \
		dvdread-config:${PORTSDIR}/multimedia/libdvdread \
		gtk-update-icon-cache:${PORTSDIR}/x11-toolkits/gtk20
LIB_DEPENDS=	asound.2:${PORTSDIR}/audio/alsa-lib \
		ass.5:${PORTSDIR}/multimedia/libass \
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		cdio.13:${PORTSDIR}/sysutils/libcdio	\
		curl.6:${PORTSDIR}/ftp/curl \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		enca.5:${PORTSDIR}/converters/enca \
		GLEW.1:${PORTSDIR}/graphics/glew \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg	\
		FLAC.10:${PORTSDIR}/audio/flac \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fribidi.3:${PORTSDIR}/converters/fribidi \
		lzo2.2:${PORTSDIR}/archivers/lzo2 \
		jasper.4:${PORTSDIR}/graphics/jasper \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		mad:${PORTSDIR}/audio/libmad \
		modplug:${PORTSDIR}/audio/libmodplug \
		mpeg2:${PORTSDIR}/multimedia/libmpeg2 \
		ogg.7:${PORTSDIR}/audio/libogg \
		pcre.1:${PORTSDIR}/devel/pcre \
		plist.1:${PORTSDIR}/devel/libplist \
		png.6:${PORTSDIR}/graphics/png \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		smbclient.0:${PORTSDIR}/net/samba-libsmbclient	\
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		yajl:${PORTSDIR}/devel/yajl
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3 \
		glxinfo:${PORTSDIR}/graphics/mesa-demos \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		xdpyinfo:${PORTSDIR}/x11/xdpyinfo

FETCH_ARGS=	-Fpr
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	autoconf libtool automake libltdl
GNU_CONFIGURE=	yes
USE_XORG=	xt xmu xrandr xtst
USE_GL=		glu
USE_SDL=	image mixer sdl
USE_MYSQL=	yes
USE_PYTHON=	2.5+
MAKE_JOBS_SAFE=	yes
NOPRECIOUSMAKEVARS=	yes
INSTALLS_ICONS=	yes
ONLY_FOR_ARCHS=	i386 amd64

PLIST_SUB+=	PYVER="${PYTHON_VERSION:S/python//:S/.//g}"

OPTIONS=	AVAHI		"Enable Avahi support"			on \
		LIBBLURAY	"Enable libbluray support"		on \
		HAL		"Enable HAL support"			on \
		LIRC		"Enable lirc support"			off \
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

CONFIGURE_ARGS+=	--disable-nfs

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

.if !defined(WITHOUT_HAL)
CONFIGURE_ARGS+=	--enable-hal
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.else
CONFIGURE_ARGS+=	--disable-hal
.endif

.if defined(WITH_LIRC)
RUN_DEPENDS+=	lircd:${PORTSDIR}/comms/lirc
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

.if ${CC} == "clang" || ${CXX} == "clang++"
CONFIGURE_ARGS+=	--disable-rsxs
PLIST_SUB+=	RSXS="@comment "
.else
PLIST_SUB+=	RSXS=""
.endif

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include <bsd.port.post.mk>
