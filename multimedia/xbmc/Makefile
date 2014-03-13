# $FreeBSD$

PORTNAME=	xbmc
DISTVERSION=	13.0.beta1
PORTREVISION=	1
CATEGORIES=	multimedia

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
		libxslt.so:${PORTSDIR}/textproc/libxslt	\
		libyajl.so:${PORTSDIR}/devel/yajl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		glxinfo:${PORTSDIR}/graphics/mesa-demos \
		nmblookup:${PORTSDIR}/net/samba-nmblookup \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		xdpyinfo:${PORTSDIR}/x11/xdpyinfo

USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_COMMIT=	128426f
GH_TAGNAME=	Gotham-beta1

USES=		gmake iconv:wchar_t pkgconfig
USE_AUTOTOOLS=	autoconf libtool automake libltdl
GNU_CONFIGURE=	yes
USE_XORG=	xt xmu xtst
USE_GL=		glu
USE_SDL=	image sdl
USE_PYTHON=	2
USE_JAVA=	yes
JAVA_BUILD=	jre
NOPRECIOUSMAKEVARS=	yes
INSTALLS_ICONS=	yes
ONLY_FOR_ARCHS=	i386 amd64

DESKTOP_ENTRIES="XBMC" \
		"${COMMENT}" \
		"${DATADIR}/media/icon.png" \
		"xbmc" \
		"AudioVideo;Video;" \
		true

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	AIRPLAY AIRTUNES AVAHI CEC LAME \
		LIBBLURAY HAL LIRC MYSQL NONFREE PULSEAUDIO RTMP SFTP \
		SMB VAAPI VDPAU VORBIS WEBSERVER XRANDR
AIRPLAY_DESC=	AirPlay support via libplist
AIRTUNES_DESC=	AirTunes support via libshairport
CEC_DESC=	CEC adapter support
NONFREE_DESC=	Enable non-free components (rar, ccx, ffmpeg)
SFTP_DESC=	SSH SFTP support via libssh
VORBIS_DESC=	Ogg Vorbis audio encoder

OPTIONS_DEFAULT=	AIRPLAY AIRTUNES AVAHI CEC LIBBLURAY HAL LIRC MYSQL \
			RTMP SFTP SMB VAAPI VDPAU VORBIS WEBSERVER XRANDR

AIRPLAY_LIB_DEPENDS=	libplist.so:${PORTSDIR}/devel/libplist
AIRPLAY_CONFIGURE_ENABLE=	airplay

AIRTUNES_LIB_DEPENDS=	libshairport.so:${PORTSDIR}/audio/libshairport
AIRTUNES_CONFIGURE_ENABLE=	airtunes

AVAHI_LIB_DEPENDS=	libavahi-client.so:${PORTSDIR}/net/avahi-app
AVAHI_CONFIGURE_ENABLE=	avahi

CEC_LIB_DEPENDS=	libcec.so:${PORTSDIR}/multimedia/libcec
CEC_CONFIGURE_ENABLE=	libcec

LIBBLURAY_LIB_DEPENDS=	libbluray.so:${PORTSDIR}/multimedia/libbluray
LIBBLURAY_CONFIGURE_ENABLE=	libbluray

HAL_LIB_DEPENDS=	libhal.so:${PORTSDIR}/sysutils/hal
HAL_CONFIGURE_ENABLE=	hal

LAME_LIB_DEPENDS=	libmp3lame.so:${PORTSDIR}/audio/lame
LAME_CONFIGURE_ENABLE=	libmp3lame

LIRC_RUN_DEPENDS=	lircd:${PORTSDIR}/comms/lirc

MYSQL_USE=	MYSQL=yes
MYSQL_CONFIGURE_ENABLE=	mysql

NONFREE_CONFIGURE_ENABLE=	non-free

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse

RTMP_LIB_DEPENDS=	librtmp.so:${PORTSDIR}/multimedia/librtmp
RTMP_CONFIGURE_ENABLE=	rtmp

SMB_LIB_DEPENDS=	libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
SMB_CONFIGURE_ENABLE=	samba

VAAPI_LIB_DEPENDS=	libva.so:${PORTSDIR}/multimedia/libva
VAAPI_CONFIGURE_ENABLE=	vaapi

VDPAU_LIB_DEPENDS=	libvdpau.so:${PORTSDIR}/multimedia/libvdpau
VDPAU_CONFIGURE_ENABLE=	vdpau

VORBIS_LIB_DEPENDS=	libvorbisenc.so:${PORTSDIR}/audio/libvorbis
VORBIS_CONFIGURE_ENABLE=	libvorbisenc

WEBSERVER_LIB_DEPENDS=	libmicrohttpd.so:${PORTSDIR}/www/libmicrohttpd
WEBSERVER_CONFIGURE_ENABLE=	webserver

SFTP_BUILD_DEPENDS=	${LOCALBASE}/lib/libssh.so:${PORTSDIR}/security/libssh
SFTP_RUN_DEPENDS=	${LOCALBASE}/lib/libssh.so:${PORTSDIR}/security/libssh
SFTP_CONFIGURE_ENABLE=	ssh

XRANDR_USE=	XORG=xrandr
XRANDR_CONFIGURE_ENABLE=	xrandr

CONFIGURE_ARGS+=	--disable-debug --disable-nfs --disable-alsa

.include <bsd.port.options.mk>

.if ${ARCH} == i386
PLIST_SUB+=	ARCH="x86"
.else
PLIST_SUB+=	ARCH="x86_64"
.endif

.if ${OSVERSION} < 900033
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

.if ${PORT_OPTIONS:MNONFREE}
NO_CDROM=	Restricted binary distribution
NO_PACKAGE=	${NO_CDROM}
.endif

post-patch:
	${REINPLACE_CMD} 's;"event\.h";"sidplay/event.h";' \
		${WRKSRC}/lib/libsidplay2/libsidplay/src/event.cpp \
		${WRKSRC}/lib/libsidplay2/libsidplay/src/mos6510/mos6510.h \
		${WRKSRC}/lib/libsidplay2/libsidplay/src/mos6526/mos6526.h \
		${WRKSRC}/lib/libsidplay2/libsidplay/src/mos656x/mos656x.h
	${REINPLACE_CMD} 's;make;gmake;' \
		${WRKSRC}/bootstrap \
		${WRKSRC}/tools/TexturePacker/Makefile.in
	${REINPLACE_CMD} 's;which swig;&2.0;' ${WRKSRC}/codegenerator.mk
	${REINPLACE_CMD} '/^autopoint/d' ${WRKSRC}/lib/cpluff/autogen.sh
	${REINPLACE_CMD} 's;static weak_ptr;static boost::weak_ptr;' \
		${WRKSRC}/xbmc/cores/dvdplayer/DVDCodecs/Video/VAAPI.cpp

run-autotools:
	cd ${WRKSRC} && ${SH} ./bootstrap
	${REINPLACE_CMD} "s;'' iconv;iconv;" ${WRKSRC}/configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/manpages/xbmc.bin.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	(cd ${STAGEDIR}${MAN1PREFIX}/man/man1 && ${LN} -sf xbmc.bin.1.gz xbmc.1.gz)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/xbmc/xbmc.bin
	${FIND} ${STAGEDIR}${PREFIX}/lib/xbmc -name '*.so' -or -name '*.xbs' -or -name '*.vis' \
		| ${XARGS} ${STRIP_CMD}
.if ${PORT_OPTIONS:MXRANDR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/xbmc/xbmc-xrandr
.endif

.include <bsd.port.mk>
