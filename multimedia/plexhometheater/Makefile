# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plexhometheater
PORTVERSION=	1.4.1
DISTVERSIONPREFIX=v
DISTVERSIONSUFFIX=.469-47a90f01
PORTREVISION=	13
CATEGORIES=	multimedia

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Media center frontend to multimedia/plexmediaserver

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

BUILD_DEPENDS=	enca:converters/enca \
		gawk:lang/gawk \
		gperf:devel/gperf \
		cmake:devel/cmake \
		zip:archivers/zip \
		nasm:devel/nasm \
		gtk-update-icon-cache:x11-toolkits/gtk20 \
		swig2.0:devel/swig20
LIB_DEPENDS=	libass.so:multimedia/libass \
		libavahi-client.so:net/avahi-app \
		libboost_thread.so:devel/boost-libs \
		libcdio.so:sysutils/libcdio \
		libcurl.so:ftp/curl \
		libdbus-1.so:devel/dbus \
		libenca.so:converters/enca \
		libFLAC.so:audio/flac \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libhal.so:sysutils/hal \
		libjasper.so:graphics/jasper \
		liblzo2.so:archivers/lzo2 \
		libmad.so:audio/libmad \
		libmicrohttpd.so:www/libmicrohttpd \
		libmodplug.so:audio/libmodplug \
		libmpeg2.so:multimedia/libmpeg2 \
		libpcre.so:devel/pcre \
		libplist.so:devel/libplist \
		libpng.so:graphics/png \
		librtmp.so:multimedia/librtmp \
		libsamplerate.so:audio/libsamplerate \
		libshairport.so:audio/libshairport \
		libsqlite3.so:databases/sqlite3 \
		libtag.so:audio/taglib \
		libtiff.so:graphics/tiff \
		libtinyxml.so:textproc/tinyxml \
		libva.so:multimedia/libva \
		libvdpau.so:multimedia/libvdpau \
		libvorbis.so:audio/libvorbis \
		libxslt.so:textproc/libxslt \
		libyajl.so:devel/yajl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		glxinfo:graphics/mesa-demos \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		xdpyinfo:x11/xdpyinfo

BROKEN=		Fails to build against libsamplerate-0.1.9
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2017-08-23

USE_GITHUB=	yes
GH_ACCOUNT=	plexinc
GH_PROJECT=	plex-home-theater-public
BUNDLE_LIBS=	yes

USES=		cmake:outsource iconv:wchar_t jpeg pkgconfig python:2
CMAKE_ARGS+=	-DENABLE_AUTOUPDATE:BOOL=false
CMAKE_ARGS+=	-DENABLE_DUMP_SYMBOLS:BOOL=false
CMAKE_ARGS+=	-DENABLE_PYTHON:BOOL=false
CMAKE_ARGS+=	-DUSE_INTERNAL_FFMPEG:BOOL=true
CMAKE_ARGS+=	-DCREATE_BUNDLE:BOOL=false
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH=${LOCALBASE}
CFLAGS+=	-isystem${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_XORG=	xt xmu xtst xrandr
USE_GL=		glu glew
USE_SDL=	image sdl mixer
INSTALLS_ICONS=	yes

ONLY_FOR_ARCHS=	i386 amd64
PLEX_ARCH_i386=	x86
PLEX_ARCH_amd64=x86_64

SUB_FILES=	${PORTNAME}.sh pkg-message
PLIST_SUB=	ARCH=${PLEX_ARCH_${ARCH}}

DESKTOP_ENTRIES="Plex Home Theater" \
		"${COMMENT}" \
		"${DATADIR}/media/plex-icon-120.png" \
		"plexhometheater.sh" \
		"AudioVideo;Video;" \
		true

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	CEC LIRC PULSEAUDIO
CEC_DESC=	Control plexhometheater over HDMI with TV remote

OPTIONS_DEFAULT=	CEC LIRC

CEC_BUILD_DEPENDS=	libcec>=3.0.0:multimedia/libcec
CEC_LIB_DEPENDS=	libcec.so:multimedia/libcec
CEC_CMAKE_OFF=		-DCMAKE_DISABLE_FIND_PACKAGE_CEC:BOOL=true

LIRC_RUN_DEPENDS=	lircd:comms/lirc

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_PulseAudio:BOOL=true

post-patch:
	@${REINPLACE_CMD} 's/[[:<:]]ARCH[[:>:]]/FFMPEG_ARCH/' \
		${WRKSRC}/lib/ffmpeg/Makefile \
		${WRKSRC}/lib/ffmpeg/common.mak \
		${WRKSRC}/lib/ffmpeg/configure \
		${WRKSRC}/lib/ffmpeg/libavcodec/Makefile
	@${REINPLACE_CMD} 's/iconv_open/libiconv_open/' \
		${WRKSRC}/plex/CMakeModules/FindIconv.cmake
	@${REINPLACE_CMD} 's/COMMAND\ make/COMMAND\ gmake/g' \
		${WRKSRC}/lib/ffmpeg/CMakeLists.txt

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/*.so
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
