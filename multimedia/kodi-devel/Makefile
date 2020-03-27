# $FreeBSD$

PORTNAME=	kodi
DISTVERSION=	19.0.a20200318
PORTREVISION=	1
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Award winning media center application

LICENSE=	GPLv2+

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386

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
		libdrm.so:graphics/libdrm \
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

# Building libcpluff.a requires autoreconf and gmake.  Using ninja
# leads to dependency problems where libcpluff.a is not yet finished
# building when it's required.
USES=		autoreconf:build cmake:noninja compiler:c++11-lang gettext gl \
		gmake gnome iconv:wchar_t jpeg libtool pkgconfig python:3.5+ \
		sqlite ssl
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_PROJECT=	xbmc
GH_TAGNAME=	809e36a24c453c27cbfae05e08c2f2e3951c2e8f
USE_GL=		egl gl glu
USE_GNOME=	libxml2 libxslt
USE_JAVA=	yes
JAVA_BUILD=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DDVDNAV_LIBRARY="${LOCALBASE}/lib/libdvdnav.so" \
		-DDVDREAD_LIBRARY="${LOCALBASE}/lib/libdvdread.so" \
		-DLIBDVD_INCLUDE_DIRS="${LOCALBASE}/include"
CMAKE_OFF=	ENABLE_ALSA ENABLE_DVDCSS ENABLE_INTERNAL_CROSSGUID \
		ENABLE_INTERNAL_FFMPEG
CONFIGURE_ENV=	CPU_FEATURES=" Features=0xdeadbeef<${_CPU_FEATURES:ts,}>" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB}"

CONFLICTS_INSTALL=	kodi

_KODIARCH_i386=		x86
_KODIARCH_amd64=	x86_64
PLIST_SUB=		ARCH=${_KODIARCH_${ARCH}:U${ARCH}} \
			OPSYS=${OPSYS:tl}
PORTDATA=		*

OPTIONS_DEFINE=			AVAHI CEC DBUS LIBBLURAY MYSQL NFS SMB SSE UPNP \
				VAAPI VDPAU WEBSERVER
OPTIONS_DEFAULT=		AVAHI CEC DBUS GBM LIBBLURAY MYSQL NFS SMB \
				SNDIO UPNP VAAPI VDPAU WAYLAND WEBSERVER X11
OPTIONS_DEFAULT_amd64=		SSE
OPTIONS_GROUP=			SOUND
OPTIONS_GROUP_SOUND=		PULSEAUDIO SNDIO
OPTIONS_MULTI=			PLATFORM
OPTIONS_MULTI_PLATFORM=		GBM WAYLAND X11
OPTIONS_EXCLUDE_aarch64=	SSE
OPTIONS_EXCLUDE_armv6=		SSE
OPTIONS_EXCLUDE_armv7=		SSE
OPTIONS_SUB=			yes

CEC_DESC=	CEC adapter support
GBM_DESC=	GBM support (requires a kernel with evdev support)
PLATFORM_DESC=	Platform

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CMAKE_BOOL=	ENABLE_AVAHI

CEC_LIB_DEPENDS=	libcec.so:multimedia/libcec
CEC_CMAKE_BOOL=		ENABLE_CEC

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_BOOL=	ENABLE_DBUS

GBM_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
GBM_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
			libinput.so:x11/libinput \
			libxkbcommon.so:x11/libxkbcommon
GBM_VARS=		_KODI_PLATFORMS+=GBM
_KODI_GBM_ARGS=		-DCORE_PLATFORM_NAME:STRING="gbm" \
			-DGBM_RENDER_SYSTEM:STRING="gl"

LIBBLURAY_LIB_DEPENDS=	libbluray.so:multimedia/libbluray
LIBBLURAY_CMAKE_BOOL=	ENABLE_BLURAY

MYSQL_USES=		mysql
MYSQL_CMAKE_BOOL=	ENABLE_MYSQLCLIENT

NFS_LIB_DEPENDS=	libnfs.so:net/libnfs
NFS_CMAKE_BOOL=		ENABLE_NFS

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	ENABLE_PULSEAUDIO

SMB_USES=	samba:lib
SMB_CMAKE_BOOL=	ENABLE_SMBCLIENT

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_BOOL=	ENABLE_SNDIO

SSE_CMAKE_BOOL=		${_SSE_CPU_FEATURES:S/./_/g:S/^/ENABLE_/}
SSE_VARS=		_CPU_FEATURES+=${_SSE_CPU_FEATURES:ts,}
_SSE_CPU_FEATURES=	SSE SSE2 SSE3 SSE4.1 SSE4.2 SSSE3

UPNP_CMAKE_BOOL=	ENABLE_UPNP
# XXX: Upstream is https://github.com/plutinosoft/Neptune
UPNP_CXXFLAGS=		-DNPT_CONFIG_HAVE_ARPA_INET_H \
			-DNPT_CONFIG_HAVE_GETADDRINFO \
			-DNPT_CONFIG_HAVE_GETIFADDRS \
			-DNPT_CONFIG_HAVE_INET_NTOP -DNPT_CONFIG_HAVE_INET_PTON \
			-DNPT_CONFIG_HAVE_NET_IF_DL_H \
			-DNPT_CONFIG_HAVE_SOCKADDR_DL \
			-DNPT_CONFIG_HAVE_SOCKADDR_IN_SIN_LEN

VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_CMAKE_BOOL=	ENABLE_VAAPI

VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau
VDPAU_CMAKE_BOOL=	ENABLE_VDPAU

WAYLAND_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
			wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libinput.so:x11/libinput \
			libwayland-client++.so:graphics/waylandpp \
			libwayland-client.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_VARS=		_KODI_PLATFORMS+=WAYLAND
_KODI_WAYLAND_ARGS=	-DCORE_PLATFORM_NAME:STRING="wayland" \
			-DWAYLAND_RENDER_SYSTEM:STRING="gl"

WEBSERVER_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
WEBSERVER_CMAKE_BOOL=	ENABLE_MICROHTTPD

X11_USES=	xorg
X11_USE=	XORG=x11,xext,xrandr
X11_VARS=	_KODI_PLATFORMS+=X11
_KODI_X11_ARGS=	-DCORE_PLATFORM_NAME:STRING="x11"
_KODI_X11_BINS=	kodi-x11 kodi-xrandr

.include <bsd.port.options.mk>

post-patch:
# Do not try to download dvdnav/dvdread during the build, instead
# we'll manually point the build to the system's libdvd{nav,read}.so
# (see CMAKE_ARGS).
	@${REINPLACE_CMD} 's@KODI_DEPENDSBUILD@true@' \
		${WRKSRC}/cmake/modules/FindLibDvd.cmake
# Abort build if freebsd.xml and linux.xml differ again.  The
# upstream devs forget to sync them.  When that happens it might
# be time to file a PR again.
	@cd ${WRKSRC}/system/settings && \
		if ! /usr/bin/cmp -s freebsd.xml linux.xml; then \
			${ECHO_MSG} "=> freebsd.xml out of sync with linux.xml again"; \
			${FALSE}; \
		fi
# Make sure Kodi can find keyboard layouts from xkeyboard-config
	@${REINPLACE_CMD} 's,/usr/share/X11/xkb/rules/,${LOCALBASE}/share/X11/xkb/rules/,g' \
		${WRKSRC}/xbmc/platform/linux/input/LibInputSettings.cpp

do-configure:
.for platform in ${_KODI_PLATFORMS:O}
	@${ECHO_MSG} "===> Performing out-of-source build for ${platform}"
	${MKDIR} ${CONFIGURE_WRKSRC}/${platform}
	@cd ${CONFIGURE_WRKSRC}/${platform} && ${SETENV} ${CONFIGURE_ENV} \
		${CMAKE_BIN} ${CMAKE_ARGS} ${_KODI_${platform}_ARGS} \
		${CMAKE_SOURCE_PATH}
.endfor

do-build:
# build in reverse to avoid touching some source files in later
# builds and triggering rebuilds/relinks in the first platform
# install phase.
.for platform in ${_KODI_PLATFORMS:O:[-1..1]}
	@${ECHO_MSG} "===>  Building for ${platform}"
	@${DO_MAKE_BUILD} -C ${BUILD_WRKSRC}/${platform} ${ALL_TARGET}
.endfor

do-install:
# Do a full install for the first platform including shared data files...
.for platform in ${_KODI_PLATFORMS:O:[1]}
	@${ECHO_MSG} "===>  Installing for ${platform}"
	@cd ${INSTALL_WRKSRC}/${platform} && ${SETENV} ${MAKE_ENV} ${FAKEROOT} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
.endfor
# ... followed by only the other platform binaries
.for platform in ${_KODI_PLATFORMS:O:[2..-1]}
	@${ECHO_MSG} "===>  Installing for ${platform}"
	cd ${INSTALL_WRKSRC}/${platform} && \
		${INSTALL_PROGRAM} ${_KODI_${platform}_BINS:Ukodi-${platform:tl}} \
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
