PORTNAME=	kodi
DISTVERSION=	21.2
PORTREVISION=	2
CATEGORIES=	multimedia java
MASTER_SITES=	http://mirrors.kodi.tv/build-deps/sources/
DISTFILES=	apache-groovy-binary-${GROOVY_VERSION}.zip \
		commons-lang3-${COMMONS_LANG_VERSION}-bin.tar.gz \
		commons-text-${COMMONS_TEXT_VERSION}-bin.tar.gz
DIST_SUBDIR=	${PORTNAME}
# do not forget to fix devel/kodi-platform when updating kodi

PATCH_SITES=	https://github.com/xbmc/xbmc/commit/
PATCHFILES=	269053ebbfd3cc4a3156a511f54ab7f08a09a730.patch:-p1

MAINTAINER=	yzrh@noema.org
COMMENT=	Award winning media center application
WWW=		https://kodi.tv/

LICENSE=	GPLv2+

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc64 powerpc64le

BUILD_DEPENDS=	flatbuffers>0:devel/flatbuffers \
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
		libharfbuzz.so:print/harfbuzz \
		liblzo2.so:archivers/lzo2 \
		libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libpostproc.so:multimedia/ffmpeg \
		libspdlog.so:devel/spdlog \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libtag.so:audio/taglib \
		libtinyxml.so:textproc/tinyxml \
		libtinyxml2.so:textproc/tinyxml2 \
		libudfread.so:multimedia/libudfread \
		libuuid.so:misc/libuuid
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		autoreconf:build cmake:noninja compiler:c++17-lang cpe \
		desktop-file-utils gettext gmake gnome iconv java:build jpeg libtool \
		pkgconfig python sqlite ssl

KODI_CODENAME=		Omega
LIBDVDCSS_VERSION=	1.4.3-Next-Nexus-Alpha2-2
LIBDVDNAV_VERSION=	6.1.1-Next-Nexus-Alpha2-2
LIBDVDREAD_VERSION=	6.1.3-Next-Nexus-Alpha2-2
GROOVY_VERSION=		4.0.16
COMMONS_LANG_VERSION=	3.14.0
COMMONS_TEXT_VERSION=	1.11.0

USE_GITHUB=	yes
GH_TUPLE=	xbmc:xbmc:${DISTVERSION}-${KODI_CODENAME} \
		xbmc:libdvdcss:${LIBDVDCSS_VERSION}:libdvdcss/tools/depends/target/libdvdcss/native \
		xbmc:libdvdnav:${LIBDVDNAV_VERSION}:libdvdnav/tools/depends/target/libdvdnav/native \
		xbmc:libdvdread:${LIBDVDREAD_VERSION}:libdvdread/tools/depends/target/libdvdread/native

KODI_ARCH_aarch64=	aarch64
KODI_ARCH_amd64=	x86_64
KODI_ARCH_i386=		x86
KODI_ARCH_armv7=	armv7
KODI_ARCH_armv6=	armv6
KODI_ARCH_powerpc64=	powerpc64
KODI_ARCH_powerpc64le=	powerpc64le

PLIST_SUB=	ARCH=${KODI_ARCH_${ARCH}}

USE_LDCONFIG=	yes
USE_GNOME=	libxml2
CMAKE_ARGS=	-DGIT_VERSION="${DISTVERSION}-${KODI_CODENAME}" \
		-DLIBDVDCSS_URL="${DISTDIR}/${PORTNAME}/xbmc-libdvdcss-${LIBDVDCSS_VERSION}_GH0.tar.gz" \
		-DLIBDVDNAV_URL="${DISTDIR}/${PORTNAME}/xbmc-libdvdnav-${LIBDVDNAV_VERSION}_GH0.tar.gz" \
		-DLIBDVDREAD_URL="${DISTDIR}/${PORTNAME}/xbmc-libdvdread-${LIBDVDREAD_VERSION}_GH0.tar.gz" \
		-Dgroovy_SOURCE_DIR="${WRKSRC}/tools/depends/share/groovy" \
		-Dapache-commons-lang_SOURCE_DIR="${WRKSRC}/tools/depends/share/java/lang" \
		-Dapache-commons-text_SOURCE_DIR="${WRKSRC}/tools/depends/share/java/text" \
		-DCROSSGUID_INCLUDE_DIR="${LOCALBASE}/include" \
		-DCORE_PLATFORM_NAME:STRING="${KODI_PLATFORM}" \
		-DCMAKE_VERBOSE_MAKEFILE=ON
CMAKE_OFF=	ENABLE_INTERNAL_CROSSGUID
CONFIGURE_ENV=	_CPU_FEATURE="${CPU_FEATURE}"

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		AIRPLAY AVAHI LIBBLURAY CEC DAV1D DBUS \
			DVDCSS LCMS2 LIRC WEBSERVER MYSQL NFS DVD SMB TEST \
			UDEV UPNP VAAPI VDPAU XSLT DOCS
OPTIONS_DEFAULT=	LIBBLURAY CEC LCMS2 WEBSERVER DAV1D \
			DVD UPNP VAAPI VDPAU XSLT GBM WAYLAND X11 GL
OPTIONS_DEFAULT_amd64=	SSE SSE2 SSE3 SSSE3 SSE4_1 SSE4_2
OPTIONS_DEFAULT_i386=	SSE SSE2 SSE3
OPTIONS_SINGLE=		RENDER
OPTIONS_SINGLE_RENDER=	GL GLES
OPTIONS_GROUP=		SOUND FEATURE PLATFORM
OPTIONS_GROUP_SOUND=	ALSA PIPEWIRE PULSEAUDIO SNDIO
OPTIONS_GROUP_FEATURE=	SSE SSE2 SSE3 SSSE3 SSE4_1 SSE4_2 AVX AVX2
OPTIONS_GROUP_PLATFORM=	GBM WAYLAND X11
OPTIONS_EXCLUDE_aarch64=FEATURE
OPTIONS_EXCLUDE_armv7=	FEATURE
OPTIONS_EXCLUDE_armv6=	FEATURE
OPTIONS_EXCLUDE_powerpc64=	FEATURE
OPTIONS_EXCLUDE_powerpc64le=	FEATURE

PLATFORM_DESC=	Kodi platform
FEATURE_DESC=	X86 CPU feature

AIRPLAY_DESC=	AirPlay support
CEC_DESC=	CEC adapter support
DAV1D_DESC=	Use dav1d as AV1 decoder
DVD_DESC=	DVD support
UDEV_DESC=	Use libudev-devd
XSLT_DESC=	Use libxslt

RENDER_DESC=	Render system
GL_DESC=	OpenGL
GLES_DESC=	OpenGL ES

GBM_DESC=	GBM support

SSE2_DESC=	Use SSE2 optimized routines
SSE3_DESC=	Use SSE3 optimized routines
SSSE3_DESC=	Use SSSE3 optimized routines
SSE4_1_DESC=	Use SSE4.1 optimized routines
SSE4_2_DESC=	Use SSE4.2 optimized routines
AVX_DESC=	Use AVX optimized routines
AVX2_DESC=	Use AVX2 optimized routines

AIRPLAY_LIB_DEPENDS=	libplist-2.0.so:devel/libplist \
			libshairplay.so:audio/shairplay
AIRPLAY_CMAKE_BOOL=	ENABLE_PLIST \
			ENABLE_AIRTUNES

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CMAKE_BOOL=	ENABLE_AVAHI

LIBBLURAY_LIB_DEPENDS=	libbluray.so:multimedia/libbluray
LIBBLURAY_CMAKE_BOOL=	ENABLE_BLURAY

CEC_LIB_DEPENDS=	libcec.so:multimedia/libcec
CEC_CMAKE_BOOL=		ENABLE_CEC

DAV1D_LIB_DEPENDS=	libdav1d.so:multimedia/dav1d
DAV1D_CMAKE_BOOL=	ENABLE_DAV1D

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_BOOL=	ENABLE_DBUS

DVDCSS_CMAKE_BOOL=	ENABLE_DVDCSS

LCMS2_LIB_DEPENDS=	liblcms2.so.2:graphics/lcms2
LCMS2_CMAKE_BOOL=	ENABLE_LCMS2

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CMAKE_BOOL=	ENABLE_LIRCCLIENT

WEBSERVER_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
WEBSERVER_CMAKE_BOOL=	ENABLE_MICROHTTPD

NFS_LIB_DEPENDS=	libnfs.so:net/libnfs
NFS_CMAKE_BOOL=		ENABLE_NFS

DVD_CMAKE_BOOL=		ENABLE_OPTICAL

SMB_USES=		samba:lib
SMB_CMAKE_BOOL=		ENABLE_SMBCLIENT

TEST_LIB_DEPENDS=	libgtest.so:devel/googletest
TEST_CMAKE_BOOL=	ENABLE_TESTING

UDEV_LIB_DEPENDS=	libudev.so:devel/libudev-devd
UDEV_CMAKE_BOOL=	ENABLE_UDEV

UPNP_CMAKE_BOOL=	ENABLE_UPNP

VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_CMAKE_BOOL=	ENABLE_VAAPI

VDPAU_IMPLIES=		X11 GL
VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau
VDPAU_CMAKE_BOOL=	ENABLE_VDPAU

XSLT_LIB_DEPENDS=	libxslt.so:textproc/libxslt
XSLT_CMAKE_BOOL=	ENABLE_XSLT

GL_CMAKE_ON=		-DAPP_RENDER_SYSTEM:STRING="gl"
GL_USES=		gl
GL_USE=			GL=gl

GLES_CMAKE_ON=		-DAPP_RENDER_SYSTEM:STRING="gles"
GLES_USES=		gl
GLES_USE=		GL=glesv2

MYSQL_USES=		mysql
MYSQL_CMAKE_BOOL=	ENABLE_MYSQLCLIENT

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	ENABLE_ALSA

PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CMAKE_BOOL=	ENABLE_PIPEWIRE

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

GBM_IMPLIES=		UDEV
GBM_VARS=		KODI_PLATFORM+=gbm
GBM_USES=		gl
GBM_USE=		GL=egl,gbm,glu
GBM_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
GBM_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
			libdrm.so:graphics/libdrm \
			libxkbcommon.so:x11/libxkbcommon \
			libinput.so:x11/libinput \
			libdisplay-info.so:sysutils/libdisplay-info
GBM_RUN_DEPENDS=	mesa-dri>0:graphics/mesa-dri

WAYLAND_VARS=		KODI_PLATFORM+=wayland
WAYLAND_CATEGORIES=	wayland
WAYLAND_USES=		gl
WAYLAND_USE=		GL=egl,glu
WAYLAND_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
			wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libdrm.so:graphics/libdrm \
			libxkbcommon.so:x11/libxkbcommon \
			libinput.so:x11/libinput \
			libwayland-client++.so:graphics/waylandpp

X11_VARS=		KODI_PLATFORM+=x11
X11_USES=		xorg gl
X11_USE=		XORG=x11,xext,xrandr GL=egl,gbm,glu
X11_LIB_DEPENDS=	libdrm.so:graphics/libdrm

.include <bsd.port.options.mk>

.if (!empty(PORT_OPTIONS:MGBM) && !empty(PORT_OPTIONS:MWAYLAND) || !empty(PORT_OPTIONS:MGBM) && !empty(PORT_OPTIONS:MX11) || !empty(PORT_OPTIONS:MWAYLAND) && !empty(PORT_OPTIONS:MX11)) && !empty(PORT_OPTIONS:MGLES)
BROKEN=	option GLES does not build with multiple PLATFORM
.endif

.if !empty(PORT_OPTIONS:MGBM) && !empty(PORT_OPTIONS:MWAYLAND) || !empty(PORT_OPTIONS:MGBM) && !empty(PORT_OPTIONS:MX11) || !empty(PORT_OPTIONS:MWAYLAND) && !empty(PORT_OPTIONS:MX11)
PLIST_SUB+=	KODICOMBINED="" \
		KODIGBM="@comment " \
		KODIWAYLAND="@comment " \
		KODIX11="@comment "
.else
PLIST_SUB+=	KODICOMBINED="@comment "

.if !empty(PORT_OPTIONS:MGBM)
PLIST_SUB+=	KODIGBM=""
.else
PLIST_SUB+=	KODIGBM="@comment "
.endif

.if !empty(PORT_OPTIONS:MWAYLAND)
PLIST_SUB+=	KODIWAYLAND=""
.else
PLIST_SUB+=	KODIWAYLAND="@comment "
.endif

.if !empty(PORT_OPTIONS:MX11)
PLIST_SUB+=	KODIX11=""
.else
PLIST_SUB+=	KODIX11="@comment "
.endif
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/tools/depends/share
	@${MV} ${WRKDIR}/groovy-${GROOVY_VERSION} ${WRKSRC}/tools/depends/share/groovy

	@${MKDIR} ${WRKSRC}/tools/depends/share/java
	@${MV} ${WRKDIR}/commons-lang3-${COMMONS_LANG_VERSION} ${WRKSRC}/tools/depends/share/java/lang
	@${MV} ${WRKDIR}/commons-text-${COMMONS_TEXT_VERSION} ${WRKSRC}/tools/depends/share/java/text

post-patch:
	${REINPLACE_CMD} 's|/usr/share|${LOCALBASE}/share|' \
		${WRKSRC}/xbmc/platform/linux/input/LibInputSettings.cpp

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/manpages/kodi.bin.1 ${STAGEDIR}${PREFIX}/share/man/man1
	cd ${STAGEDIR}${PREFIX}/share/man/man1 && ${LN} -s kodi.bin.1.gz kodi.1.gz
	cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} kodi-TexturePacker TexturePacker
	${FIND} ${STAGEDIR}${PREFIX}/lib/kodi -type f -name '*.so' -print0 | ${XARGS} -0 ${STRIP_CMD}
	${RM} -r ${STAGEDIR}${PREFIX}/lib/firewalld

.include <bsd.port.mk>
