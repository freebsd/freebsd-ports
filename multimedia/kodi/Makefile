# $FreeBSD$

PORTNAME=	kodi
DISTVERSION=	15.2
PORTREVISION=	1
CATEGORIES=	multimedia java
MASTER_SITES=	https://codeload.github.com/xbmc/xbmc/tar.gz/${KODI_COMMIT}?dummy=/ \
		GH:ffmpeg
DISTFILES=	${DISTVERSION}-Isengard${EXTRACT_SUFX} \
		${GH_PROJECT}-${GH_TAGNAME}.tar.gz:ffmpeg
EXTRACT_ONLY=	${DISTVERSION}-Isengard${EXTRACT_SUFX}

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
		gtk-update-icon-cache:${PORTSDIR}/x11-toolkits/gtk20 \
		swig2.0:${PORTSDIR}/devel/swig20
LIB_DEPENDS=	libass.so:${PORTSDIR}/multimedia/libass \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libcdio.so:${PORTSDIR}/sysutils/libcdio	\
		libcurl.so:${PORTSDIR}/ftp/curl \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libdrm.so:${PORTSDIR}/graphics/libdrm \
		libenca.so:${PORTSDIR}/converters/enca \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfribidi.so:${PORTSDIR}/converters/fribidi \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		liblzo2.so:${PORTSDIR}/archivers/lzo2 \
		libjasper.so:${PORTSDIR}/graphics/jasper \
		libltdl.so:${PORTSDIR}/devel/libltdl \
		libmodplug.so:${PORTSDIR}/audio/libmodplug \
		libmpeg2.so:${PORTSDIR}/multimedia/libmpeg2 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libpng.so:${PORTSDIR}/graphics/png \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libtag.so:${PORTSDIR}/audio/taglib \
		libtinyxml.so:${PORTSDIR}/textproc/tinyxml \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libxslt.so:${PORTSDIR}/textproc/libxslt	\
		libyajl.so:${PORTSDIR}/devel/yajl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		glxinfo:${PORTSDIR}/graphics/mesa-demos \
		python:${PORTSDIR}/lang/python \
		xdpyinfo:${PORTSDIR}/x11/xdpyinfo

USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_PROJECT=	ffmpeg
GH_TAGNAME=	2.6.4-Isengard
KODI_COMMIT=	f4dda26

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

WRKSRC=		${WRKDIR}/xbmc-${KODI_COMMIT}

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

OPTIONS_DEFAULT=	AIRPLAY AIRTUNES AVAHI LIBBLURAY LIRC MYSQL \
			NFS PULSEAUDIO RTMP SFTP SMB VAAPI VDPAU WEBSERVER

AIRPLAY_LIB_DEPENDS=	libplist.so:${PORTSDIR}/devel/libplist
AIRPLAY_CONFIGURE_ENABLE=	airplay

AIRTUNES_LIB_DEPENDS=	libshairplay.so:${PORTSDIR}/audio/shairplay
AIRTUNES_CONFIGURE_ENABLE=	airtunes

AVAHI_LIB_DEPENDS=	libavahi-client.so:${PORTSDIR}/net/avahi-app
AVAHI_CONFIGURE_ENABLE=	avahi

CEC_BROKEN=		libcec >= 3.0.0 has not been ported yet
CEC_BUILD_DEPENDS=	libcec>=3.0.0:${PORTSDIR}/multimedia/libcec
CEC_LIB_DEPENDS=	libcec.so:${PORTSDIR}/multimedia/libcec
CEC_CONFIGURE_ENABLE=	libcec

LIBBLURAY_LIB_DEPENDS=	libbluray.so:${PORTSDIR}/multimedia/libbluray
LIBBLURAY_CONFIGURE_ENABLE=	libbluray

LIRC_RUN_DEPENDS=	lircd:${PORTSDIR}/comms/lirc

MYSQL_USE=	MYSQL=yes
MYSQL_CONFIGURE_ENABLE=	mysql

NFS_LIB_DEPENDS=	libnfs.so:${PORTSDIR}/net/libnfs
NFS_CONFIGURE_ENABLE=	nfs

NONFREE_CONFIGURE_ENABLE=	non-free
NONFREE_VARS=		NO_CDROM="Restricted binary distribution" \
			NO_PACKAGE="Restricted binary distribution"

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse

RTMP_LIB_DEPENDS=	librtmp.so:${PORTSDIR}/multimedia/librtmp
RTMP_CONFIGURE_ENABLE=	rtmp

SMB_LIB_DEPENDS=	libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
SMB_RUN_DEPENDS=	nmblookup:${PORTSDIR}/net/samba-nmblookup
SMB_CONFIGURE_ENABLE=	samba

VAAPI_LIB_DEPENDS=	libva.so:${PORTSDIR}/multimedia/libva
VAAPI_CONFIGURE_ENABLE=	vaapi

VDPAU_LIB_DEPENDS=	libvdpau.so:${PORTSDIR}/multimedia/libvdpau
VDPAU_CONFIGURE_ENABLE=	vdpau

WEBSERVER_LIB_DEPENDS=	libmicrohttpd.so:${PORTSDIR}/www/libmicrohttpd
WEBSERVER_CONFIGURE_ENABLE=	webserver

SFTP_BUILD_DEPENDS=	${LOCALBASE}/lib/libssh.so:${PORTSDIR}/security/libssh
SFTP_RUN_DEPENDS=	${LOCALBASE}/lib/libssh.so:${PORTSDIR}/security/libssh
SFTP_CONFIGURE_ENABLE=	ssh

CONFIGURE_ARGS+=	--disable-debug --disable-alsa

post-extract:
	${MKDIR} ${WRKSRC}/tools/depends/target/ffmpeg/${GH_PROJECT}-${GH_TAGNAME}
	${TAR} --strip-components=1 -xf ${DISTDIR}/${GH_PROJECT}-${GH_TAGNAME}.tar.gz \
		 -C ${WRKSRC}/tools/depends/target/ffmpeg/${GH_PROJECT}-${GH_TAGNAME}

post-patch:
	${REINPLACE_CMD} 's;make;gmake;' \
		${WRKSRC}/bootstrap \
		${WRKSRC}/codegenerator.mk \
		${WRKSRC}/xbmc/Makefile.in
	${REINPLACE_CMD} 's;which swig;&2.0;' ${WRKSRC}/codegenerator.mk

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
