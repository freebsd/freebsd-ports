# $FreeBSD$

PORTNAME=	xbmc
DISTVERSION=	12.2
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://mirrors.xbmc.org/releases/source/

MAINTAINER=	mickael.maillot@gmail.com
COMMENT=	Award winning media center application

LICENSE=	GPLv2

BUILD_DEPENDS=	enca:${PORTSDIR}/converters/enca \
		gawk:${PORTSDIR}/lang/gawk \
		gperf:${PORTSDIR}/devel/gperf \
		cmake:${PORTSDIR}/devel/cmake \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		nasm:${PORTSDIR}/devel/nasm \
		dvdread-config:${PORTSDIR}/multimedia/libdvdread \
		gtk-update-icon-cache:${PORTSDIR}/x11-toolkits/gtk20 \
		swig2.0:${PORTSDIR}/devel/swig20
LIB_DEPENDS=	libass.so:${PORTSDIR}/multimedia/libass \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libcdio.so:${PORTSDIR}/sysutils/libcdio	\
		libcurl.so:${PORTSDIR}/ftp/curl \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libenca.so:${PORTSDIR}/converters/enca \
		libGLEW.so:${PORTSDIR}/graphics/glew \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfribidi.so:${PORTSDIR}/converters/fribidi \
		liblzo2.so:${PORTSDIR}/archivers/lzo2 \
		libjasper.so:${PORTSDIR}/graphics/jasper \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libmad.so:${PORTSDIR}/audio/libmad \
		libmodplug.so:${PORTSDIR}/audio/libmodplug \
		libmpeg2.so:${PORTSDIR}/multimedia/libmpeg2 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libpng15.so:${PORTSDIR}/graphics/png \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libtag.so:${PORTSDIR}/audio/taglib \
		libtinyxml.so:${PORTSDIR}/textproc/tinyxml \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libyajl.so:${PORTSDIR}/devel/yajl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		glxinfo:${PORTSDIR}/graphics/mesa-demos \
		nmblookup:${PORTSDIR}/net/samba-nmblookup \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		xdpyinfo:${PORTSDIR}/x11/xdpyinfo

FETCH_ARGS=	-Fpr
USES=		gmake iconv pkgconfig
USE_AUTOTOOLS=	autoconf libtool automake libltdl
GNU_CONFIGURE=	yes
USE_XORG=	xt xmu xrandr xtst
USE_GL=		glu
USE_SDL=	image sdl
USE_PYTHON=	-2.7
USE_JAVA=	yes
JAVA_BUILD=	jre
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

OPTIONS_DEFINE=	AIRPLAY AIRTUNES AVAHI CEC EXTERNAL_FFMPEG LAME \
		LIBBLURAY HAL LIRC MYSQL NONFREE PULSEAUDIO RTMP SFTP \
		SMB VAAPI VDPAU VORBIS WEBSERVER
AIRPLAY_DESC=	AirPlay support via libplist
AIRTUNES_DESC=	AirTunes support via libshairport
CEC_DESC=	CEC adapter support
EXTERNAL_FFMPEG_DESC=	Use external ffmpeg
NONFREE_DESC=	Enable non-free components (rar, ccx, ffmpeg)
SFTP_DESC=	SSH SFTP support via libssh
VORBIS_DESC=	Ogg Vorbis audio encoder

OPTIONS_DEFAULT=	AIRPLAY AVAHI CEC LIBBLURAY HAL MYSQL \
			RTMP SFTP SMB VORBIS WEBSERVER

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000
OPTIONS_DEFAULT+=	EXTERNAL_FFMPEG
.endif

CONFIGURE_ARGS+=	--disable-nfs

.include <bsd.port.options.mk>

.if ${ARCH} == i386
PLIST_SUB+=	ARCH="x86"
.else
PLIST_SUB+=	ARCH="x86_64"
.endif

.if ${OSVERSION} <= 800096
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
USE_SDL+=	mixer
CONFIGURE_ARGS+=	--disable-oss
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if ${PORT_OPTIONS:MAIRPLAY}
CONFIGURE_ARGS+=	--enable-airplay
LIB_DEPENDS+=	plist:${PORTSDIR}/devel/libplist
.else
CONFIGURE_ARGS+=	--disable-airplay
.endif

.if ${PORT_OPTIONS:MAIRTUNES}
CONFIGURE_ARGS+=	--enable-airtunes
LIB_DEPENDS+=	shairport:${PORTSDIR}/audio/libshairport
.else
CONFIGURE_ARGS+=	--disable-airtunes
.endif

.if ${PORT_OPTIONS:MAVAHI}
CONFIGURE_ARGS+=	--enable-avahi
LIB_DEPENDS+=	avahi-common:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if ${PORT_OPTIONS:MCEC}
CONFIGURE_ARGS+=	--enable-libcec
LIB_DEPENDS+=	cec:${PORTSDIR}/multimedia/libcec
.else
CONFIGURE_ARGS+=	--disable-libcec
.endif

.if ${PORT_OPTIONS:MEXTERNAL_FFMPEG}
CONFIGURE_ARGS+=	--enable-external-ffmpeg
FFMPEG_SUFFIX=	1
CONFIGURE_ENV+=	FFMPEG_SUFFIX="${FFMPEG_SUFFIX}"
PLIST_SUB+=	EXTERNAL_FFMPEG="@comment "
BUILD_DEPENDS+=	ffmpeg${FFMPEG_SUFFIX}>0.11:${PORTSDIR}/multimedia/ffmpeg${FFMPEG_SUFFIX}
RUN_DEPENDS+=	ffmpeg${FFMPEG_SUFFIX}>0.11:${PORTSDIR}/multimedia/ffmpeg${FFMPEG_SUFFIX}
.else
CONFIGURE_ARGS+=	--disable-external-ffmpeg
PLIST_SUB+=	EXTERNAL_FFMPEG=""
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

.if ${PORT_OPTIONS:MLAME}
CONFIGURE_ARGS+=	--enable-libmp3lame
LIB_DEPENDS+=	mp3lame:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=	--disable-libmp3lame
.endif

.if ${PORT_OPTIONS:MLIRC}
RUN_DEPENDS+=	lircd:${PORTSDIR}/comms/lirc
.endif

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--enable-mysql
USE_MYSQL=	yes
.else
CONFIGURE_ARGS+=	--disable-mysql
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

.if ${PORT_OPTIONS:MSFTP}
CONFIGURE_ARGS+=	--enable-ssh
BUILD_DEPENDS+=	${LOCALBASE}/lib/libssh.so:${PORTSDIR}/security/libssh
RUN_DEPENDS+=	${LOCALBASE}/lib/libssh.so:${PORTSDIR}/security/libssh
.else
CONFIGURE_ARGS+=	--disable-ssh
.endif

.if ${PORT_OPTIONS:MSMB}
CONFIGURE_ARGS+=	--enable-samba
LIB_DEPENDS+=	smbclient:${PORTSDIR}/net/samba-libsmbclient
.else
CONFIGURE_ARGS+=	--disable-samba
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

.if ${PORT_OPTIONS:MVORBIS}
CONFIGURE_ARGS+=	--enable-libvorbisenc
LIB_DEPENDS+=	ogg:${PORTSDIR}/audio/libogg
.else
CONFIGURE_ARGS+=	--disable-libvorbisenc
.endif

.if ${PORT_OPTIONS:MWEBSERVER}
CONFIGURE_ARGS+=	--enable-webserver
LIB_DEPENDS+=	microhttpd:${PORTSDIR}/www/libmicrohttpd
.else
CONFIGURE_ARGS+=	--disable-webserver
.endif

post-patch:
	${REINPLACE_CMD} 's;"event\.h";"sidplay/event.h";' \
		${WRKSRC}/lib/libsidplay2/libsidplay/src/event.cpp \
		${WRKSRC}/lib/libsidplay2/libsidplay/src/mos6510/mos6510.h \
		${WRKSRC}/lib/libsidplay2/libsidplay/src/mos6526/mos6526.h \
		${WRKSRC}/lib/libsidplay2/libsidplay/src/mos656x/mos656x.h
	${REINPLACE_CMD} 's;make;gmake;' ${WRKSRC}/bootstrap
	${REINPLACE_CMD} 's;which swig;&2.0;' ${WRKSRC}/codegenerator.mk
.if empty(ICONV_LIB)
	${REINPLACE_CMD}  -e 's;^checking for main in -liconv\.\.\.;checking for iconv...;' \
			-e 's;-liconv;${ICONV_LIB};' ${WRKSRC}/configure
.endif

run-autotools:
	@cd ${WRKSRC} && ${SH} ./bootstrap

post-install:
	@${INSTALL_MAN} ${WRKSRC}/docs/manpages/xbmc.bin.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@(cd ${STAGEDIR}${MAN1PREFIX}/man/man1 && ${LN} -sf xbmc.bin.1.gz xbmc.1.gz)

.include <bsd.port.post.mk>
