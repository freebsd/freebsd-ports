# $FreeBSD$

PORTNAME=	kodi
DISTVERSION=	18.7.1
PORTREVISION=	3
CATEGORIES=	multimedia java

PATCH_SITES=	https://github.com/xbmc/xbmc/commit/
PATCHFILES=	920cc74da069216d19f724ecf5246cf997861bc6.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Award winning media center application

LICENSE=	GPLv2+

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386

BUILD_DEPENDS=	flatbuffers>0:devel/flatbuffers \
		gperf>0:devel/gperf \
		rapidjson>0:devel/rapidjson \
		swig>0:devel/swig
LIB_DEPENDS=	libass.so:multimedia/libass \
		libavcodec.so:multimedia/ffmpeg \
		libavfilter.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libcdio.so:sysutils/libcdio \
		libcrossguid.so:devel/libcrossguid \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libfmt.so:devel/libfmt \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libfstrcmp.so:devel/fstrcmp \
		libgif.so:graphics/giflib \
		liblzo2.so:archivers/lzo2 \
		libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libpostproc.so:multimedia/ffmpeg \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libtag.so:audio/taglib \
		libtinyxml.so:textproc/tinyxml \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

USES=		autoreconf:build cmake:noninja compiler:c++14-lang gettext gl gmake \
		gnome iconv jpeg libtool pkgconfig python:2.7 ssl sqlite xorg

KODI_ARCH_amd64=x86_64
KODI_ARCH_i386=	x86
KODI_ARCH_armv7=armv7
KODI_ARCH_armv6=armv6

NOPRECIOUSMAKEVARS=	yes

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USE_JAVA=	yes
JAVA_BUILD=	jre
USE_GNOME=	libxml2
CMAKE_ARGS=	-Dlibdvdcss_URL="${DISTDIR}/xbmc-libdvdcss-1.4.2-Leia-Beta-5_GH0.tar.gz" \
		-Dlibdvdnav_URL="${DISTDIR}/xbmc-libdvdnav-6.0.0-Leia-Alpha-3_GH0.tar.gz" \
		-Dlibdvdread_URL="${DISTDIR}/xbmc-libdvdread-6.0.0-Leia-Alpha-3_GH0.tar.gz"
CMAKE_OFF=	ENABLE_INTERNAL_CROSSGUID \
		ENABLE_INTERNAL_FFMPEG
CONFIGURE_ENV=	_CPU_FEATURE="${CPU_FEATURE}"

KODI_CODENAME=		Leia
LIBDVDCSS_VERSION=	1.4.2-${KODI_CODENAME}-Beta-5
LIBDVDNAV_VERSION=	6.0.0-${KODI_CODENAME}-Alpha-3
LIBDVDREAD_VERSION=	6.0.0-${KODI_CODENAME}-Alpha-3

USE_GITHUB=	yes
GH_TUPLE=	xbmc:xbmc:${PORTVERSION}-${KODI_CODENAME} \
		xbmc:libdvdcss:${LIBDVDCSS_VERSION}:libdvdcss/tools/depends/target/libdvdcss/native \
		xbmc:libdvdnav:${LIBDVDNAV_VERSION}:libdvdnav/tools/depends/target/libdvdnav/native \
		xbmc:libdvdread:${LIBDVDREAD_VERSION}:libdvdread/tools/depends/target/libdvdread/native

PLIST_SUB=	ARCH=${KODI_ARCH_${ARCH}}

OPTIONS_SUB=		yes
# Not implemented: BLUETOOTH CAP
OPTIONS_DEFINE=		AIRPLAY AIRTUNES AVAHI CEC DBUS DOCS DVDCSS LCMS2 \
			LIBBLURAY LIRC NFS OPTICAL SMB UDEV UPNP VAAPI VDPAU \
			WEBSERVER XSLT
OPTIONS_DEFAULT=	AIRPLAY AIRTUNES AVAHI CEC DVDCSS LIBBLURAY NFS OPTICAL SMB \
			UDEV UPNP VAAPI VDPAU WEBSERVER X11 XSLT
OPTIONS_DEFAULT_amd64=	SSE SSE2 SSE3
OPTIONS_DEFAULT_i386=	SSE SSE2 SSE3
OPTIONS_SINGLE=		PLATFORM
OPTIONS_SINGLE_PLATFORM=GBM RPI WAYLAND X11
OPTIONS_RADIO=		DATABASE
OPTIONS_RADIO_DATABASE=	MARIADB MYSQL
OPTIONS_GROUP=		SOUND FEATURE
# Broken: ALSA
OPTIONS_GROUP_SOUND=	PULSEAUDIO SNDIO
OPTIONS_GROUP_FEATURE=	SSE SSE2 SSE3 SSSE3 SSE4_1 SSE4_2 AVX AVX2
OPTIONS_EXCLUDE_amd64=	RPI
OPTIONS_EXCLUDE_i386=	RPI
OPTIONS_EXCLUDE_armv7=	FEATURE
OPTIONS_EXCLUDE_armv6=	FEATURE

AIRPLAY_DESC=	AirPlay support via libplist
AIRTUNES_DESC=	AirTunes support via libshairplay
AVX_DESC=	Use AVX optimized routines
AVX2_DESC=	Use AVX2 optimized routines
BLUETOOTH_DESC=	Bluetooth support via bluez
CAP_DESC=	Capability support via libcap
CEC_DESC=	CEC adapter support
DATABASE_DESC=	Database
FEATURE_DESC=	X86 CPU feature
GBM_DESC=	GBM support
MARIADB_DESC=	MariaDB database support
OPTICAL_DESC=	Optical disc support
PLATFORM_DESC=	Kodi platform
RPI_DESC=	Raspberry Pi support
SSE2_DESC=	Use SSE2 optimized routines
SSE3_DESC=	Use SSE3 optimized routines
SSSE3_DESC=	Use SSSE3 optimized routines
SSE4_1_DESC=	Use SSE4.1 optimized routines
SSE4_2_DESC=	Use SSE4.2 optimized routines
UDEV_DESC=	Use libudev-devd
XSLT_DESC=	Use libxslt

AIRPLAY_LIB_DEPENDS=	libplist.so:devel/libplist
AIRPLAY_CMAKE_BOOL=	ENABLE_PLIST

AIRTUNES_LIB_DEPENDS=	libshairplay.so:audio/shairplay
AIRTUNES_CMAKE_BOOL=	ENABLE_AIRTUNES

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CMAKE_BOOL=	ENABLE_AVAHI

BLUETOOTH_CMAKE_BOOL=	ENABLE_BLUETOOTH

CAP_CMAKE_BOOL=		ENABLE_CAP

CEC_LIB_DEPENDS=	libcec.so:multimedia/libcec
CEC_CMAKE_BOOL=		ENABLE_CEC

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_BOOL=	ENABLE_DBUS

DVDCSS_CMAKE_BOOL=	ENABLE_DVDCSS

LCMS2_LIB_DEPENDS=	liblcms2.so.2:graphics/lcms2
LCMS2_CMAKE_BOOL=	ENABLE_LCMS2

LIBBLURAY_LIB_DEPENDS=	libbluray.so:multimedia/libbluray
LIBBLURAY_CMAKE_BOOL=	ENABLE_BLURAY

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CMAKE_BOOL=	ENABLE_LIRCCLIENT

MARIADB_USES=		mysql:104m
MARIADB_CMAKE_BOOL=	ENABLE_MARIADBCLIENT
MARIADB_CMAKE_ON=	-DMARIADBCLIENT_INCLUDE_DIR="${LOCALBASE}/include"

MYSQL_USES=		mysql
MYSQL_CMAKE_BOOL=	ENABLE_MYSQLCLIENT

NFS_LIB_DEPENDS=	libnfs.so:net/libnfs
NFS_CMAKE_BOOL=		ENABLE_NFS

OPTICAL_CMAKE_BOOL=	ENABLE_OPTICAL

SMB_USES=		samba:lib
SMB_CMAKE_BOOL=		ENABLE_SMBCLIENT

UDEV_LIB_DEPENDS=	libudev.so:devel/libudev-devd
UDEV_CMAKE_BOOL=	ENABLE_UDEV

UPNP_CMAKE_BOOL=	ENABLE_UPNP

VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_CMAKE_BOOL=	ENABLE_VAAPI

VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau
VDPAU_CMAKE_BOOL=	ENABLE_VDPAU

WEBSERVER_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
WEBSERVER_CMAKE_BOOL=	ENABLE_MICROHTTPD

XSLT_LIB_DEPENDS=	libxslt.so:textproc/libxslt
XSLT_CMAKE_BOOL=	ENABLE_XSLT

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	ENABLE_ALSA

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	ENABLE_PULSEAUDIO

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_BOOL=	ENABLE_SNDIO

SSE_VARS=		CPU_FEATURE+=SSE
SSE2_VARS=		CPU_FEATURE+=SSE2
SSE3_VARS=		CPU_FEATURE+=SSE3
SSSE3_VARS=		CPU_FEATURE+=SSSE3
SSE4_1_VARS=		CPU_FEATURE+=SSE4.1
SSE4_2_VARS=		CPU_FEATURE+=SSE4.2
AVX_VARS=		CPU_FEATURE+=AVX
AVX2_VARS=		CPU_FEATURE+=AVX2

GBM_USE=		GL=egl,gbm,glu
GBM_CFLAGS=		-I${LOCALBASE}/include/libepoll-shim
GBM_LDFLAGS=		-L${LOCALBASE}/lib -lepoll-shim
GBM_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
GBM_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
			libdrm.so:graphics/libdrm \
			libxkbcommon.so:x11/libxkbcommon \
			libinput.so:x11/libinput
GBM_CMAKE_ON=		-DCORE_PLATFORM_NAME:STRING="gbm" \
			-DGBM_RENDER_SYSTEM:STRING="gl"

RPI_LIB_DEPENDS=	libbrcmGLESv2.so:misc/raspberrypi-userland \
			libbrcmEGL.so:misc/raspberrypi-userland \
			libxkbcommon.so:x11/libxkbcommon \
			libinput.so:x11/libinput
RPI_CMAKE_ON=		-DCORE_PLATFORM_NAME:STRING="rbpi"

WAYLAND_USE=		GL=egl,glu
WAYLAND_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
			wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libdrm.so:graphics/libdrm \
			libxkbcommon.so:x11/libxkbcommon \
			libwayland-client++.so:graphics/waylandpp
WAYLAND_CMAKE_ON=	-DCORE_PLATFORM_NAME:STRING="wayland" \
			-DWAYLAND_RENDER_SYSTEM:STRING="gl"

X11_USE=		XORG=x11,xext,xrandr GL=egl,gl,glu
X11_LIB_DEPENDS=	libdrm.so:graphics/libdrm
X11_CMAKE_ON=		-DCORE_PLATFORM_NAME:STRING="x11"

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} 's|/usr/share|${LOCALBASE}/share|' \
		${WRKSRC}/xbmc/platform/linux/input/LibInputSettings.cpp

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/manpages/kodi.bin.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	cd ${STAGEDIR}${MAN1PREFIX}/man/man1 && ${LN} -s kodi.bin.1.gz kodi.1.gz
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/TexturePacker
	${FIND} ${STAGEDIR}${PREFIX}/lib/kodi -type f -name '*.so' -print0 | ${XARGS} -0 ${STRIP_CMD}
	${RM} -rf ${STAGEDIR}${PREFIX}/lib/firewalld

.include <bsd.port.mk>
