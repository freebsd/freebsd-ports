# $FreeBSD$

PORTNAME=	kodi
DISTVERSION=	18.0.g201807222249
CATEGORIES=	multimedia
PKGNAMESUFFIX?=	-devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Award winning media center application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/copying.txt

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386

BUILD_DEPENDS=	rapidjson>=0:devel/rapidjson \
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
USES=		autoreconf:build cmake:outsource,noninja compiler:c++11-lib \
		gettext gmake iconv:wchar_t jpeg libtool pkgconfig python:2.7 \
		ssl sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_PROJECT=	xbmc
GH_TAGNAME=	64a79f3e8c1cc1af0b8dc4f645e60f6c889e3667
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

OPTIONS_DEFINE=	AVAHI CEC DBUS LIBBLURAY MYSQL NFS SMB UPNP VAAPI VDPAU WEBSERVER
OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT=	LIBBLURAY UPNP VAAPI VDPAU WEBSERVER X11
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_SINGLE=	PLATFORM
OPTIONS_SINGLE_PLATFORM=	GBM RPI WAYLAND X11
OPTIONS_EXCLUDE_amd64=	RPI
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

GBM_BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat
GBM_CMAKE_ON=		-DCORE_PLATFORM_NAME:STRING="gbm"
GBM_LIB_DEPENDS=	libinput.so:x11/libinput \
			libxkbcommon.so:x11/libxkbcommon

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
RPI_CMAKE_ON=		-DCORE_PLATFORM_NAME:STRING="rbpi"
RPI_LIB_DEPENDS=	libbrcmEGL.so:misc/raspberrypi-userland
RPI_LIB_DEPENDS_OFF=	libdrm.so:graphics/libdrm
RPI_PREVENTS=		VAAPI VDPAU
RPI_USE_OFF=		GL=egl,gl,glu

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

WAYLAND_BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat \
			wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_CMAKE_ON=	-DCORE_PLATFORM_NAME:STRING="wayland" \
			-DWAYLAND_RENDER_SYSTEM:STRING="gl"
WAYLAND_LIB_DEPENDS=	libinput.so:x11/libinput \
			libwayland-client++.so:graphics/waylandpp \
			libwayland-client.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon

WEBSERVER_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
WEBSERVER_CMAKE_BOOL=	ENABLE_MICROHTTPD

X11_CMAKE_ON=		-DCORE_PLATFORM_NAME:STRING="x11"
X11_USE=		XORG=x11,xext,xrandr

.include <bsd.port.options.mk>

.if ${SLAVE_PORT} == no
PORTDATA=	*
.endif

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

.if ${SLAVE_PORT} == no
post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/manpages/kodi.bin.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@cd ${STAGEDIR}${MAN1PREFIX}/man/man1 && ${LN} -sf kodi.bin.1.gz kodi.1.gz
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/TexturePacker
	@${FIND} ${STAGEDIR}${PREFIX}/lib/kodi -name '*.so' | ${XARGS} ${STRIP_CMD}
# Nothing useful here...
	@${RM} -r ${STAGEDIR}${DOCSDIR}
# No firewalld on FreeBSD...
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/firewalld
.endif

.include <bsd.port.mk>
