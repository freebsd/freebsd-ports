# New ports collection makefile for:    xbmc
# Date created:				2010-09-16
# Whom: 				Mickael Maillot <mickael.maillot@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xbmc
PORTVERSION=	11.0
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://mirrors.xbmc.org/releases/source/

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
LIB_DEPENDS=	ass:${PORTSDIR}/multimedia/libass \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		cdio:${PORTSDIR}/sysutils/libcdio	\
		curl:${PORTSDIR}/ftp/curl \
		dbus-1:${PORTSDIR}/devel/dbus \
		enca:${PORTSDIR}/converters/enca \
		GLEW:${PORTSDIR}/graphics/glew \
		avcodec:${PORTSDIR}/multimedia/ffmpeg	\
		FLAC:${PORTSDIR}/audio/flac \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2 \
		fribidi:${PORTSDIR}/converters/fribidi \
		lzo2:${PORTSDIR}/archivers/lzo2 \
		jasper:${PORTSDIR}/graphics/jasper \
		jpeg:${PORTSDIR}/graphics/jpeg \
		mad:${PORTSDIR}/audio/libmad \
		modplug:${PORTSDIR}/audio/libmodplug \
		mpeg2:${PORTSDIR}/multimedia/libmpeg2 \
		ogg:${PORTSDIR}/audio/libogg \
		pcre:${PORTSDIR}/devel/pcre \
		plist:${PORTSDIR}/devel/libplist \
		png15:${PORTSDIR}/graphics/png \
		samplerate:${PORTSDIR}/audio/libsamplerate \
		smbclient:${PORTSDIR}/net/samba-libsmbclient	\
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		vorbis:${PORTSDIR}/audio/libvorbis \
		yajl:${PORTSDIR}/devel/yajl
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3 \
		glxinfo:${PORTSDIR}/graphics/mesa-demos \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		xdpyinfo:${PORTSDIR}/x11/xdpyinfo

FETCH_ARGS=	-Fpr
USE_GMAKE=	yes
USE_PKGCONFIG=	build
USE_AUTOTOOLS=	autoconf libtool automake libltdl
GNU_CONFIGURE=	yes
USE_XORG=	xt xmu xrandr xtst
USE_GL=		glu
USE_SDL=	image sdl
USE_MYSQL=	yes
USE_PYTHON=	2.5+
MAKE_JOBS_SAFE=	yes
NOPRECIOUSMAKEVARS=	yes
INSTALLS_ICONS=	yes
ONLY_FOR_ARCHS=	i386 amd64
CONFLICTS_INSTALL=	xbmc-pva-ppa-odk-[0-9]*

DESKTOP_ENTRIES="XBMC" \
		"${COMMENT}" \
		"${DATADIR}/media/icon.png" \
		"xbmc" \
		"AudioVideo;Video;" \
		true

OPTIONS_DEFINE=	AVAHI LIBBLURAY HAL LIRC NONFREE OSS PULSEAUDIO RTMP VAAPI VDPAU WEBSERVER
NONFREE_DESC=		Enable non-free components (rar, ccx, ffmpeg)

OPTIONS_DEFAULT=	AVAHI LIBBLURAY HAL RTMP WEBSERVER

CONFIGURE_ARGS+=	--disable-nfs

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if ${ARCH} == i386
PLIST_SUB+=	ARCH="x86"
.else
PLIST_SUB+=	ARCH="x86_64"
.endif

.if ${PORT_OPTIONS:MAVAHAHI}
CONFIGURE_ARGS+=	--enable-avahi
LIB_DEPENDS+=	avahi-common:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if ${PORT_OPTIONS:MLIBBLURAY}
CONFIGURE_ARGS+=	--enable-libbluray
LIB_DEPENDS+=	bluray:${PORTSDIR}/multimedia/libbluray
.else
CONFIGURE_ARGS+=	--disable-libbluray
.endif

.if ${PORT_OPTIONS:MHAL}
CONFIGURE_ARGS+=	--enable-hal
LIB_DEPENDS+=	hal:${PORTSDIR}/sysutils/hal
.else
CONFIGURE_ARGS+=	--disable-hal
.endif

.if ${PORT_OPTIONS:MLIRC}
RUN_DEPENDS+=	lircd:${PORTSDIR}/comms/lirc
.endif

.if ${PORT_OPTIONS:MNONFREE}
CONFIGURE_ARGS+=	--enable-non-free
NO_CDROM=	Restricted binary distribution
NO_PACKAGE=	${NO_CDROM}
.else
CONFIGURE_ARGS+=	--disable-non-free
.endif

.if ${PORT_OPTIONS:MOSS}
.if ${OSVERSION} <= 800096
IGNORE=	requires sound rewrite from 8.0-RELEASE or later
.endif
CONFIGURE_ARGS+=	--disable-alsa
.else
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
USE_SDL+=	mixer
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
CONFIGURE_ARGS+=	--enable-pulse
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

.if ${PORT_OPTIONS:MRTMP}
CONFIGURE_ARGS+=	--enable-rtmp
LIB_DEPENDS+=	rtmp:${PORTSDIR}/multimedia/rtmpdump
.else
CONFIGURE_ARGS+=	--disable-rtmp
.endif

.if ${PORT_OPTIONS:MVAAPI}
LIB_DEPENDS+=	va:${PORTSDIR}/multimedia/libva
CONFIGURE_ARGS+=	--enable-vaapi
.else
CONFIGURE_ARGS+=	--disable-vaapi
.endif

.if ${PORT_OPTIONS:MVDPAU}
LIB_DEPENDS+=	vdpau:${PORTSDIR}/multimedia/libvdpau
CONFIGURE_ARGS+=	--enable-vdpau
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

.if ${PORT_OPTIONS:MWEBSERVER}
CONFIGURE_ARGS+=	--enable-webserver
LIB_DEPENDS+=	microhttpd:${PORTSDIR}/www/libmicrohttpd
.else
CONFIGURE_ARGS+=	--disable-webserver
.endif

.if ${CC} == "clang" || ${CXX} == "clang++"
CONFIGURE_ARGS+=	--disable-rsxs
PLIST_SUB+=	RSXS="@comment "
.else
PLIST_SUB+=	RSXS=""
.endif

post-patch:
.if ${PORT_OPTIONS:MOSS}
	@(cd ${WRKSRC}; \
	${BZCAT} ${FILESDIR}/extra-patch-oss.bz2 | ${PATCH} ${PATCH_DIST_ARGS})
	@${RM} ${WRKSRC}/language/English/strings.xml.orig
	@${RM} ${WRKSRC}/addons/skin.confluence/sounds/sounds.xml.orig
.endif

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
