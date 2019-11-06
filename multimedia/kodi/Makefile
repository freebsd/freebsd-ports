# $FreeBSD$

PORTNAME=	kodi
DISTVERSION=	17.6
PORTREVISION=	14
CATEGORIES=	multimedia java

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Award winning media center application

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386

BUILD_DEPENDS=	enca:converters/enca \
		gawk:lang/gawk \
		gperf:devel/gperf \
		cmake:devel/cmake \
		zip:archivers/zip \
		nasm:devel/nasm \
		swig3.0:devel/swig30
LIB_DEPENDS=	libass.so:multimedia/libass \
		libFLAC.so:audio/flac \
		libcdio.so:sysutils/libcdio \
		libcrossguid.so:devel/libcrossguid \
		libcurl.so:ftp/curl \
		libdbus-1.so:devel/dbus \
		libdcadec.so:multimedia/libdcadec \
		libenca.so:converters/enca \
		libexpat.so:textproc/expat2\
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libgcrypt.so:security/libgcrypt \
		libgmp.so:math/gmp \
		libgpg-error.so:security/libgpg-error \
		libgnutls.so:security/gnutls \
		libidn.so:dns/libidn \
		libinotify.so:devel/libinotify \
		libjasper.so:graphics/jasper \
		libltdl.so:devel/libltdl \
		liblzo2.so:archivers/lzo2 \
		libmodplug.so:audio/libmodplug \
		libmpeg2.so:multimedia/libmpeg2 \
		libnettle.so:security/nettle \
		libogg.so:audio/libogg \
		libp11-kit.so:security/p11-kit \
		libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libsamplerate.so:audio/libsamplerate \
		libsqlite3.so:databases/sqlite3 \
		libtag.so:audio/taglib \
		libtasn1.so:security/libtasn1 \
		libtiff.so:graphics/tiff \
		libtinyxml.so:textproc/tinyxml \
		libtspi.so:security/trousers \
		libunistring.so:devel/libunistring \
		libuuid.so:misc/e2fsprogs-libuuid \
		libvorbis.so:audio/libvorbis \
		libxslt.so:textproc/libxslt \
		libyajl.so:devel/yajl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		autoreconf:build compiler:c++11-lib gettext gmake gnome iconv \
		jpeg libtool pkgconfig python:-2.7 ssl

KODI_ARCH_i386=	x86
KODI_ARCH_amd64=x86_64
KODI_ARCH_armv6=armv6
KODI_ARCH_armv7=armv7

GNU_CONFIGURE=	yes
USE_JAVA=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
JAVA_BUILD=	jre
NOPRECIOUSMAKEVARS=	yes
CONFIGURE_ENV=	OPENSSL_LIBS="-L${OPENSSLLIB}" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}"

KODI_CODENAME=		Krypton
FFMPEG_VERS=		3.1.11
LIBDVDCSS_TAGNAME=	2f12236
LIBDVDNAV_TAGNAME=	981488f
LIBDVDREAD_TAGNAME=	17d99db

USE_GITHUB=	yes
GH_TUPLE=	xbmc:xbmc:${PORTVERSION}-${KODI_CODENAME} \
		xbmc:FFmpeg:${FFMPEG_VERS}-${KODI_CODENAME}-17.5:ffmpeg/tools/depends/target/ffmpeg \
		xbmc:libdvdcss:${LIBDVDCSS_TAGNAME}:libdvdcss/tools/depends/target/libdvdcss/native \
		xbmc:libdvdnav:${LIBDVDNAV_TAGNAME}:libdvdnav/tools/depends/target/libdvdnav/native \
		xbmc:libdvdread:${LIBDVDREAD_TAGNAME}:libdvdread/tools/depends/target/libdvdread/native

PLIST_SUB=	ARCH=${KODI_ARCH_${ARCH}}

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	AIRPLAY AIRTUNES AVAHI CEC DOCS \
		LCMS2 LIBBLURAY LIRC MYSQL NFS NONFREE PULSEAUDIO RTMP \
		SFTP SNDIO SMB VAAPI VDPAU WEBSERVER
OPTIONS_SINGLE=		RPI
OPTIONS_SINGLE_RPI=	RPI1 RPI2

OPTIONS_EXCLUDE_armv6=	LIRC VAAPI VDPAU
OPTIONS_EXCLUDE_armv7=	LIRC VAAPI VDPAU
OPTIONS_EXCLUDE_amd64=	RPI1 RPI2
OPTIONS_EXCLUDE_i386=	RPI1 RPI2

AIRPLAY_DESC=	AirPlay support via libplist
AIRTUNES_DESC=	AirTunes support via libshairplay
CEC_DESC=	CEC adapter support
NONFREE_DESC=	Enable non-free components (rar, ccx, ffmpeg)
SFTP_DESC=	SSH SFTP support via libssh
RPI1_DESC=	build for RPI1-B (cpu=arm1176jzf-s)
RPI2_DESC=	build for RPI2 (cpu=cortex-a7, neon enabled)

OPTIONS_DEFAULT=	AIRPLAY AIRTUNES AVAHI CEC LIRC \
		MYSQL NFS RTMP SFTP SMB VAAPI VDPAU WEBSERVER
OPTIONS_DEFAULT_armv6=	RPI1
OPTIONS_DEFAULT_armv7=	RPI1

AIRPLAY_LIB_DEPENDS=	libplist.so:devel/libplist
AIRPLAY_CONFIGURE_ENABLE=	airplay

AIRTUNES_LIB_DEPENDS=	libshairplay.so:audio/shairplay
AIRTUNES_CONFIGURE_ENABLE=	airtunes

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CONFIGURE_ENABLE=	avahi

CEC_BUILD_DEPENDS=	libcec>=3.1.0:multimedia/libcec
CEC_LIB_DEPENDS=	libcec.so:multimedia/libcec
CEC_CONFIGURE_ENABLE=	libcec

LCMS2_LIB_DEPENDS=	liblcms2.so.2:graphics/lcms2
LCMS2_CONFIGURE_ENABLE=	lcms2

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

RPI1_CONFIGURE_ON=	--with-platform=raspberry-pi
RPI2_CONFIGURE_ON=	--with-platform=raspberry-pi2

RTMP_LIB_DEPENDS=	librtmp.so:multimedia/librtmp
RTMP_CONFIGURE_ENABLE=	rtmp

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ENABLE=	sndio
SNDIO_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-sndio

SMB_USES=		samba:lib
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

CONFIGURE_ARGS+=	--disable-debug --enable-gl --disable-gles \
			--disable-openmax --disable-tegra \
			--disable-profiling --enable-x11 --disable-alsa \
			--enable-dbus --enable-upnp --disable-mid \
			--disable-mdnsembedded --enable-libxslt \
			--disable-texturepacker --disable-libusb \
			--disable-libbluetooth --disable-libcap \
			--disable-gtest --disable-libav-compat

.include <bsd.port.options.mk>

.if ${ARCH} != armv6 && ${ARCH} != armv7
BUILD_DEPENDS+=	gtk-update-icon-cache:x11-toolkits/gtk20
LIB_DEPENDS+=	libdrm.so:graphics/libdrm
RUN_DEPENDS+=	glxinfo:graphics/mesa-demos \
		xdpyinfo:x11/xdpyinfo
USES+=		gl sdl xorg
USE_XORG=	x11 xcb xext xmu xrandr xt xtst
USE_GL=		egl gl glu glew
USE_SDL=	image sdl2
INSTALLS_ICONS=	yes
PLIST_SUB+=	ARM="@comment "
PLIST_SUB+=	X86=""
.else
# armv6 || armv7 (rpi1 and rpi2 only)
EXTRA_PATCHES+=	${FILESDIR}/extra-armv6_hal
CONFIGURE_ARGS+=	--enable-player=omxplayer
LIB_DEPENDS+=	libEGL.so:misc/raspberrypi-userland \
		libhal.so:sysutils/hal \
		libtiff.so:graphics/tiff
PLIST_SUB+=	ARM=""
PLIST_SUB+=	X86="@comment "
SUB_FILES=	pkg-message
.endif

post-patch:
	${REINPLACE_CMD} 's;make;gmake;' \
		${WRKSRC}/bootstrap \
		${WRKSRC}/codegenerator.mk \
		${WRKSRC}/xbmc/Makefile.in
	${REINPLACE_CMD} 's;which swig;&3.0;' ${WRKSRC}/codegenerator.mk
	${RM} ${WRKSRC}/system/settings/rbp2.xml.orig

pre-configure:
	cd ${WRKSRC} && ${SH} ./bootstrap

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/manpages/kodi.bin.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	(cd ${STAGEDIR}${MAN1PREFIX}/man/man1 && ${LN} -sf kodi.bin.1.gz kodi.1.gz)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/kodi/kodi.bin
	${FIND} ${STAGEDIR}${PREFIX}/lib/kodi -name '*.so' -or -name '*.xbs' -or -name '*.vis' \
		| ${XARGS} ${STRIP_CMD}
.if ${ARCH} != armv6 && ${ARCH} != armv7
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/kodi/kodi-xrandr
.endif

.include <bsd.port.mk>
