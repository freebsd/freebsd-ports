# $FreeBSD$

PORTNAME=	kodi
DISTVERSION=	18.1
DISTVERSIONSUFFIX=	-Leia
PORTREVISION=	2
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Award winning media center application

LICENSE=	GPLv2+

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386

BUILD_DEPENDS=	flatbuffers>=0:devel/flatbuffers \
		rapidjson>=0:devel/rapidjson \
		swig3.0:devel/swig30
LIB_DEPENDS=	libass.so:multimedia/libass \
		libavcodec.so:multimedia/ffmpeg \
		libavfilter.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libcdio.so:sysutils/libcdio \
		libcrossguid.so:devel/libcrossguid \
		libcurl.so:ftp/curl \
		libdvdnav.so:multimedia/libdvdnav \
		libdvdread.so:multimedia/libdvdread \
		libexpat.so:textproc/expat2 \
		libfmt.so:devel/libfmt \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libfstrcmp.so:devel/fstrcmp \
		libgif.so:graphics/giflib \
		libgnutls.so:security/gnutls \
		liblcms2.so:graphics/lcms2 \
		liblzo2.so:archivers/lzo2 \
		libpcre.so:devel/pcre \
		libpcrecpp.so:devel/pcre \
		libpng.so:graphics/png \
		libpostproc.so:multimedia/ffmpeg \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libtag.so:audio/taglib \
		libtinyxml.so:textproc/tinyxml \
		libudev.so:devel/libudev-devd \
		libuuid.so:misc/e2fsprogs-libuuid

# Building libcpluff.a requires autoreconf and gmake.  Using ninja
# leads to dependency problems where libcpluff.a is not yet finished
# building when it's required.
USES=		autoreconf:build cmake:noninja compiler:c++11-lib \
		gettext gmake gnome iconv:wchar_t jpeg libtool pkgconfig \
		python:2.7 ssl sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_PROJECT=	xbmc
USE_GNOME=	libxslt libxml2
USE_JAVA=	yes
JAVA_BUILD=	yes
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	kodi

CMAKE_ARGS=	-DLIBDVD_INCLUDE_DIRS="${LOCALBASE}/include" \
		-DDVDREAD_LIBRARY="${LOCALBASE}/lib/libdvdread.so" \
		-DDVDNAV_LIBRARY="${LOCALBASE}/lib/libdvdnav.so"
CMAKE_OFF=	ENABLE_ALSA \
		ENABLE_DVDCSS \
		ENABLE_INTERNAL_FFMPEG \
		ENABLE_INTERNAL_CROSSGUID
CONFIGURE_ENV=	OPENSSL_LIBS="-L${OPENSSLLIB}" OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		CPU_FEATURES=" Features=0xdeadbeef<${CPU_FEATURES:ts,}>"

KODIARCH_i386=	x86
KODIARCH_amd64=	x86_64

PLIST_SUB=	ARCH=${KODIARCH_${ARCH}:U${ARCH}} OPSYS=${OPSYS:tl}
PORTDATA=	*

OPTIONS_DEFINE=	AVAHI CEC DBUS LIBBLURAY MYSQL NFS SMB SSE UPNP VAAPI VDPAU WEBSERVER
OPTIONS_DEFAULT=	GBM LIBBLURAY UPNP VAAPI VDPAU WEBSERVER WAYLAND X11
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_MULTI=	PLATFORM
OPTIONS_MULTI_PLATFORM=	GBM RPI WAYLAND X11
OPTIONS_EXCLUDE_amd64=	RPI
OPTIONS_EXCLUDE_armv6=	SSE
OPTIONS_EXCLUDE_armv7=	SSE
OPTIONS_EXCLUDE_i386=	RPI
OPTIONS_SUB=	yes

OPTIONS_GROUP=		SOUND
OPTIONS_GROUP_SOUND=	PULSEAUDIO SNDIO

CEC_DESC=	CEC adapter support
GBM_DESC=	GBM support (requires a kernel with evdev support)
PLATFORM_DESC=	Platform
RPI_DESC=	Raspberry Pi support

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CMAKE_BOOL=	ENABLE_AVAHI

CEC_LIB_DEPENDS=	libcec.so:multimedia/libcec
CEC_CMAKE_BOOL=		ENABLE_CEC

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_BOOL=	ENABLE_DBUS

KODI_GBM_ARGS=		-DCORE_PLATFORM_NAME:STRING="gbm" \
			-DGBM_RENDER_SYSTEM:STRING="gl"
GBM_CFLAGS=		-I${LOCALBASE}/include/libepoll-shim
GBM_LDFLAGS=		-L${LOCALBASE}/lib -lepoll-shim -lpthread -lrt
GBM_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
GBM_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
			libinput.so:x11/libinput \
			libxkbcommon.so:x11/libxkbcommon
GBM_VARS=		KODI_PLATFORMS+=GBM

LIBBLURAY_LIB_DEPENDS=	libbluray.so:multimedia/libbluray
LIBBLURAY_CMAKE_BOOL=	ENABLE_BLURAY

MYSQL_USES=		mysql
MYSQL_CMAKE_BOOL=	ENABLE_MYSQLCLIENT

NFS_LIB_DEPENDS=	libnfs.so:net/libnfs
NFS_CMAKE_BOOL=		ENABLE_NFS

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	ENABLE_PULSEAUDIO

# For RPI, disable VAAPI in multimedia/ffmpeg too, so that mesa-libs
# is *not* installed via libva in the build environment.  Both
# mesa-libs and raspberrypi-userland conflict with each other.
KODI_RBPI_ARGS=		-DCORE_PLATFORM_NAME:STRING="rbpi"
RPI_LIB_DEPENDS=	libbrcmEGL.so:misc/raspberrypi-userland
RPI_LIB_DEPENDS_OFF=	libdrm.so:graphics/libdrm
RPI_PREVENTS=		GBM VAAPI VDPAU WAYLAND X11
RPI_USES_OFF=		gl
RPI_USE_OFF=		GL=egl,gl,glu
RPI_VARS=		KODI_PLATFORMS+=RBPI

SMB_USES=		samba:lib
SMB_CMAKE_BOOL=		ENABLE_SMBCLIENT

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_BOOL=	ENABLE_SNDIO

SSE_CPU_FEATURES=	SSE SSE2 SSE3 SSSE3 SSE4.1 SSE4.2
SSE_CMAKE_BOOL=		${SSE_CPU_FEATURES:S/./_/g:S/^/ENABLE_/}
SSE_VARS=		CPU_FEATURES+=${SSE_CPU_FEATURES:ts,}

UPNP_CMAKE_BOOL=	ENABLE_UPNP
# XXX: Upstream is https://github.com/plutinosoft/Neptune
UPNP_CXXFLAGS=		-DNPT_CONFIG_HAVE_ARPA_INET_H \
			-DNPT_CONFIG_HAVE_GETADDRINFO \
			-DNPT_CONFIG_HAVE_GETIFADDRS \
			-DNPT_CONFIG_HAVE_INET_NTOP \
			-DNPT_CONFIG_HAVE_INET_PTON \
			-DNPT_CONFIG_HAVE_NET_IF_DL_H \
			-DNPT_CONFIG_HAVE_SOCKADDR_DL \
			-DNPT_CONFIG_HAVE_SOCKADDR_IN_SIN_LEN

VAAPI_CMAKE_BOOL=	ENABLE_VAAPI
VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva

VDPAU_CMAKE_BOOL=	ENABLE_VDPAU
VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau

KODI_WAYLAND_ARGS=	-DCORE_PLATFORM_NAME:STRING="wayland" \
			-DWAYLAND_RENDER_SYSTEM:STRING="gl"
WAYLAND_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
			wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libinput.so:x11/libinput \
			libwayland-client++.so:graphics/waylandpp \
			libwayland-client.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_VARS=		KODI_PLATFORMS+=WAYLAND

WEBSERVER_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
WEBSERVER_CMAKE_BOOL=	ENABLE_MICROHTTPD

KODI_X11_ARGS=		-DCORE_PLATFORM_NAME:STRING="x11"
KODI_X11_BINS=		kodi-x11 kodi-xrandr
X11_USE=		XORG=x11,xext,xrandr
X11_VARS=		KODI_PLATFORMS+=X11

.include <bsd.port.options.mk>

post-patch:
# Do not try to download dvdnav/dvdread during the build, instead
# we'll manually point the build to the system's libdvd{nav,read}.so
# (see CMAKE_ARGS).
	@${REINPLACE_CMD} 's@KODI_DEPENDSBUILD@true@' \
		${WRKSRC}/cmake/modules/FindLibDvd.cmake
# Make sure freebsd.xml is in sync with linux.xml since the
# upstream devs do not sync them
	@${CP} ${WRKSRC}/system/settings/linux.xml \
		${WRKSRC}/system/settings/freebsd.xml
# Make sure Kodi can find keyboard layouts from xkeyboard-config
	@${REINPLACE_CMD} 's,/usr/share/X11/xkb/rules/,${LOCALBASE}/share/X11/xkb/rules/,g' \
		${WRKSRC}/xbmc/platform/linux/input/LibInputSettings.cpp

do-configure:
.for platform in ${KODI_PLATFORMS:O}
	@${ECHO_MSG} "===> Performing out-of-source build for ${platform}"
	${MKDIR} ${CONFIGURE_WRKSRC}/${platform}
	@cd ${CONFIGURE_WRKSRC}/${platform} && ${SETENV} ${CONFIGURE_ENV} \
		${CMAKE_BIN} ${CMAKE_ARGS} ${KODI_${platform}_ARGS} \
		${CMAKE_SOURCE_PATH}
.endfor

do-build:
# build in reverse to avoid touching some source files in later
# builds and triggering rebuilds/relinks in the first platform
# install phase.
.for platform in ${KODI_PLATFORMS:O:[-1..1]}
	@${ECHO_MSG} "===>  Building for ${platform}"
	@${DO_MAKE_BUILD} -C ${BUILD_WRKSRC}/${platform} ${ALL_TARGET}
.endfor

do-install:
# Do a full install for the first platform including shared data files...
.for platform in ${KODI_PLATFORMS:O:[1]}
	@${ECHO_MSG} "===>  Installing for ${platform}"
	@cd ${INSTALL_WRKSRC}/${platform} && ${SETENV} ${MAKE_ENV} ${FAKEROOT} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
.endfor
# ... followed by only the other platform binaries
.for platform in ${KODI_PLATFORMS:O:[2..-1]}
	@${ECHO_MSG} "===>  Installing for ${platform}"
	cd ${INSTALL_WRKSRC}/${platform} && \
		${INSTALL_PROGRAM} ${KODI_${platform}_BINS:Ukodi-${platform:tl}} \
		${STAGEDIR}${PREFIX}/lib/kodi
.endfor
	${INSTALL_MAN} ${WRKSRC}/docs/manpages/kodi.bin.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@cd ${STAGEDIR}${MAN1PREFIX}/man/man1 && ${LN} -sf kodi.bin.1.gz kodi.1.gz
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/TexturePacker
	@${FIND} ${STAGEDIR}${PREFIX}/lib/kodi -name '*.so' | ${XARGS} ${STRIP_CMD}
# Nothing useful here...
	@${RM} -r ${STAGEDIR}${DOCSDIR}
# No firewalld on FreeBSD...
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/firewalld

.include <bsd.port.mk>
