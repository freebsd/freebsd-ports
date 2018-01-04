# $FreeBSD$

PORTNAME=	kodi
DISTVERSION=	18.0.g20171213
PORTREVISION=	1
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Award winning media center application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

BROKEN_FreeBSD_10=	does not build
ONLY_FOR_ARCHS=	amd64 i386

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
		libdrm.so:graphics/libdrm \
		libdvdnav.so:multimedia/libdvdnav \
		libdvdread.so:multimedia/libdvdread \
		libexpat.so:textproc/expat2 \
		libfmt.so:devel/libfmt \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libgif.so:graphics/giflib \
		liblcms2.so:graphics/lcms2 \
		liblzo2.so:archivers/lzo2 \
		libpcre.so:devel/pcre \
		libpcrecpp.so:devel/pcre \
		libpng16.so:graphics/png \
		libpostproc.so:multimedia/ffmpeg \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libtag.so:audio/taglib \
		libtinyxml.so:textproc/tinyxml \
		libuuid.so:misc/e2fsprogs-libuuid

# Building libcpluff.a requires autoreconf and gmake.  Using ninja
# leads to dependency problems where libcpluff.a is not yet finished
# building when it's required.
USES=		autoreconf:build cmake:outsource,noninja compiler:c++11-lib \
		gettext gmake iconv:wchar_t jpeg libtool pkgconfig python:-2.7 \
		ssl sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc
GH_PROJECT=	xbmc
GH_TAGNAME=	5853600d6655ff888bd6bd9e89fb58883080b6d2
USE_GNOME=	libxslt libxml2
USE_GL=		egl gl glu
USE_JAVA=	yes
JAVA_BUILD=	yes
USE_LDCONFIG=	yes
USE_XORG=	x11 xext xrandr

CONFLICTS_INSTALL=	kodi-[0-9]*

CMAKE_ARGS=	-DCORE_PLATFORM_NAME=X11 \
		-DENABLE_ALSA=no \
		-DENABLE_INTERNAL_FFMPEG=no \
		-DENABLE_INTERNAL_CROSSGUID=no \
		-DENABLE_DVDCSS=no \
		-DLIBDVD_INCLUDE_DIRS="${LOCALBASE}/include" \
		-DDVDREAD_LIBRARY="${LOCALBASE}/lib/libdvdread.so" \
		-DDVDNAV_LIBRARY="${LOCALBASE}/lib/libdvdnav.so"
CONFIGURE_ENV=	OPENSSL_LIBS="-L${OPENSSLLIB}" OPENSSL_CFLAGS="-I${OPENSSLINC}"

KODIARCH_i386=	x86
KODIARCH_amd64=	x86_64

PLIST_SUB=	ARCH=${KODIARCH_${ARCH}} OPSYS=${OPSYS:tl}

OPTIONS_DEFINE=	AVAHI CEC DBUS LIBBLURAY MYSQL NFS SMB SSH VAAPI VDPAU \
		WEBSERVER
OPTIONS_DEFAULT=	SNDIO SSH VAAPI VDPAU WEBSERVER
OPTIONS_SUB=	yes

# Choosing one of SNDIO or PULSEAUDIO is mandatory right now if you
# want audio output.  The OSS backend is currently not hooked into
# Kodi's audio sink factory due to recent refactorings.
OPTIONS_MULTI=		SOUND
OPTIONS_MULTI_SOUND=	PULSEAUDIO SNDIO

CEC_DESC=	CEC adapter support

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CMAKE_BOOL=	ENABLE_AVAHI

CEC_LIB_DEPENDS=	libcec.so:multimedia/libcec
CEC_CMAKE_BOOL=		ENABLE_CEC

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_BOOL=	ENABLE_DBUS

LIBBLURAY_LIB_DEPENDS=	libbluray.so:multimedia/libbluray
LIBBLURAY_CMAKE_BOOL=	ENABLE_BLURAY

MYSQL_USES=		mysql
MYSQL_CMAKE_BOOL=	ENABLE_MYSQLCLIENT

NFS_LIB_DEPENDS=	libnfs.so:net/libnfs
NFS_CMAKE_BOOL=		ENABLE_NFS

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	ENABLE_PULSEAUDIO

SMB_USES=		samba:lib
SMB_CMAKE_BOOL=		ENABLE_SMBCLIENT

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_BOOL=	ENABLE_SNDIO

SSH_LIB_DEPENDS=	libssh.so:security/libssh
SSH_CMAKE_BOOL=		ENABLE_SSH

VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_CMAKE_BOOL=	ENABLE_VAAPI

VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau
VDPAU_CMAKE_BOOL=	ENABLE_VDPAU

WEBSERVER_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
WEBSERVER_CMAKE_BOOL=	ENABLE_MICROHTTPD

post-patch:
# Do not try to download dvdnav/dvdread during the build, instead
# we'll manually point the build to the system's libdvd{nav,read}.so
# (see CMAKE_ARGS).
	@${REINPLACE_CMD} 's@KODI_DEPENDSBUILD@true@' \
		${WRKSRC}/cmake/modules/FindLibDvd.cmake

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/manpages/kodi.bin.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@cd ${STAGEDIR}${MAN1PREFIX}/man/man1 && ${LN} -sf kodi.bin.1.gz kodi.1.gz
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/TexturePacker
	@${FIND} ${STAGEDIR}${PREFIX}/lib/kodi -name '*.so' | ${XARGS} ${STRIP_CMD}
# Nothing useful here...
	@${RM} -rf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
