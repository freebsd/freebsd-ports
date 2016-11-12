# $FreeBSD$

PORTNAME=	kodi
DISTVERSION=	16.1
PORTREVISION=	2
CATEGORIES=	multimedia java

MAINTAINER=	mickael.maillot@gmail.com
COMMENT=	Award winning media center application

LICENSE=	GPLv2

BUILD_DEPENDS=	enca:converters/enca \
		gawk:lang/gawk \
		gperf:devel/gperf \
		cmake:devel/cmake \
		zip:archivers/zip \
		nasm:devel/nasm \
		gtk-update-icon-cache:x11-toolkits/gtk20 \
		swig3.0:devel/swig30
LIB_DEPENDS=	libass.so:multimedia/libass \
		libFLAC.so:audio/flac \
		libboost_thread.so:devel/boost-libs \
		libcdio.so:sysutils/libcdio	\
		libcrossguid.so:devel/libcrossguid \
		libcurl.so:ftp/curl \
		libdbus-1.so:devel/dbus \
		libdcadec.so:multimedia/libdcadec \
		libdrm.so:graphics/libdrm \
		libenca.so:converters/enca \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libgnutls.so:security/gnutls \
		libjasper.so:graphics/jasper \
		libltdl.so:devel/libltdl \
		liblzo2.so:archivers/lzo2 \
		libmodplug.so:audio/libmodplug \
		libmpeg2.so:multimedia/libmpeg2 \
		libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libsamplerate.so:audio/libsamplerate \
		libsqlite3.so:databases/sqlite3 \
		libtag.so:audio/taglib \
		libtinyxml.so:textproc/tinyxml \
		libvorbis.so:audio/libvorbis \
		libxslt.so:textproc/libxslt	\
		libyajl.so:devel/yajl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		glxinfo:graphics/mesa-demos \
		python:lang/python \
		xdpyinfo:x11/xdpyinfo

USE_GITHUB=	yes
GH_TUPLE=	xbmc:xbmc:c327c53 xbmc:FFmpeg:2.8.6-Jarvis-16.0:ffmpeg

USES=		autoreconf:build compiler:c++11-lib gettext gmake iconv jpeg \
		libtool pkgconfig python:2
GNU_CONFIGURE=	yes
USE_XORG=	xmu xrandr xt xtst
USE_GL=		glu glew
USE_SDL=	image sdl2
USE_JAVA=	yes
USE_LDCONFIG=	yes
JAVA_BUILD=	jre
NOPRECIOUSMAKEVARS=	yes
INSTALLS_ICONS=	yes

ONLY_FOR_ARCHS=	i386 amd64
KODI_ARCH_i386=	x86
KODI_ARCH_amd64=x86_64

PLIST_SUB=	ARCH=${KODI_ARCH_${ARCH}}

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	AIRPLAY AIRTUNES AVAHI CEC DOCS \
		LIBBLURAY LIRC MYSQL NFS NONFREE PULSEAUDIO RTMP \
		SFTP SMB VAAPI VDPAU WEBSERVER
AIRPLAY_DESC=	AirPlay support via libplist
AIRTUNES_DESC=	AirTunes support via libshairplay
CEC_DESC=	CEC adapter support
NONFREE_DESC=	Enable non-free components (rar, ccx, ffmpeg)
SFTP_DESC=	SSH SFTP support via libssh

OPTIONS_DEFAULT=	AIRPLAY AIRTUNES AVAHI CEC LIBBLURAY LIRC \
		MYSQL NFS RTMP SFTP SMB VAAPI VDPAU WEBSERVER

AIRPLAY_LIB_DEPENDS=	libplist.so:devel/libplist
AIRPLAY_CONFIGURE_ENABLE=	airplay

AIRTUNES_LIB_DEPENDS=	libshairplay.so:audio/shairplay
AIRTUNES_CONFIGURE_ENABLE=	airtunes

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CONFIGURE_ENABLE=	avahi

CEC_BUILD_DEPENDS=	libcec>=3.1.0:multimedia/libcec
CEC_LIB_DEPENDS=	libcec.so:multimedia/libcec
CEC_CONFIGURE_ENABLE=	libcec

LIBBLURAY_LIB_DEPENDS=	libbluray.so:multimedia/libbluray
LIBBLURAY_CONFIGURE_ENABLE=	libbluray

LIRC_RUN_DEPENDS=	lircd:comms/lirc

MYSQL_USES=	mysql
MYSQL_CONFIGURE_ENABLE=	mysql

NFS_LIB_DEPENDS=	libnfs.so:net/libnfs
NFS_CONFIGURE_ENABLE=	nfs

NONFREE_CONFIGURE_ENABLE=	non-free
NONFREE_VARS=		NO_CDROM="Restricted binary distribution" \
			NO_PACKAGE="Restricted binary distribution"

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse

RTMP_LIB_DEPENDS=	librtmp.so:multimedia/librtmp
RTMP_CONFIGURE_ENABLE=	rtmp

SMB_LIB_DEPENDS=	libsmbclient.so:net/samba-libsmbclient
SMB_RUN_DEPENDS=	nmblookup:net/samba-nmblookup
SMB_CONFIGURE_ENABLE=	samba

VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_CONFIGURE_ENABLE=	vaapi

VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau
VDPAU_CONFIGURE_ENABLE=	vdpau

WEBSERVER_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
WEBSERVER_CONFIGURE_ENABLE=	webserver

SFTP_BUILD_DEPENDS=	${LOCALBASE}/lib/libssh.so:security/libssh
SFTP_RUN_DEPENDS=	${LOCALBASE}/lib/libssh.so:security/libssh
SFTP_CONFIGURE_ENABLE=	ssh

CONFIGURE_ARGS+=	--disable-debug --disable-alsa --disable-texturepacker

post-extract:
	${MV} ${WRKSRC_ffmpeg} ${WRKSRC}/tools/depends/target/ffmpeg/

post-patch:
	${REINPLACE_CMD} 's;make;gmake;' \
		${WRKSRC}/bootstrap \
		${WRKSRC}/codegenerator.mk \
		${WRKSRC}/xbmc/Makefile.in
	${REINPLACE_CMD} 's;which swig;&3.0;' ${WRKSRC}/codegenerator.mk

pre-configure:
	cd ${WRKSRC} && ${SH} ./bootstrap

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/manpages/kodi.bin.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	(cd ${STAGEDIR}${MAN1PREFIX}/man/man1 && ${LN} -sf kodi.bin.1.gz kodi.1.gz)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/kodi/kodi.bin
	${FIND} ${STAGEDIR}${PREFIX}/lib/kodi -name '*.so' -or -name '*.xbs' -or -name '*.vis' \
		| ${XARGS} ${STRIP_CMD}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/kodi/kodi-xrandr

.include <bsd.port.mk>
