# $FreeBSD$

PORTNAME=	plexhometheater
PORTVERSION=	1.2.2
PORTREVISION=	3
CATEGORIES=	multimedia

MAINTAINER=	woodsb02@gmail.com
COMMENT=	Media center frontend to multimedia/plexmediaserver

LICENSE=	GPLv2

BUILD_DEPENDS=	enca:${PORTSDIR}/converters/enca \
		gawk:${PORTSDIR}/lang/gawk \
		gperf:${PORTSDIR}/devel/gperf \
		cmake:${PORTSDIR}/devel/cmake \
		gmake:${PORTSDIR}/devel/gmake \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		nasm:${PORTSDIR}/devel/nasm \
		gtk-update-icon-cache:${PORTSDIR}/x11-toolkits/gtk20 \
		swig2.0:${PORTSDIR}/devel/swig20

LIB_DEPENDS=	libass.so:${PORTSDIR}/multimedia/libass \
		libavahi-client.so:${PORTSDIR}/net/avahi-app \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libcdio.so:${PORTSDIR}/sysutils/libcdio \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libenca.so:${PORTSDIR}/converters/enca \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfribidi.so:${PORTSDIR}/converters/fribidi \
		libGLEW.so:${PORTSDIR}/graphics/glew \
		libhal.so:${PORTSDIR}/sysutils/hal \
		libjasper.so:${PORTSDIR}/graphics/jasper \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		liblzo2.so:${PORTSDIR}/archivers/lzo2 \
		libmad.so:${PORTSDIR}/audio/libmad \
		libmicrohttpd.so:${PORTSDIR}/www/libmicrohttpd \
		libmodplug.so:${PORTSDIR}/audio/libmodplug \
		libmpeg2.so:${PORTSDIR}/multimedia/libmpeg2 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libplist.so:${PORTSDIR}/devel/libplist \
		libpng15.so:${PORTSDIR}/graphics/png \
		librtmp.so:${PORTSDIR}/multimedia/librtmp \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libshairport.so:${PORTSDIR}/audio/libshairport \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libtag.so:${PORTSDIR}/audio/taglib \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libtinyxml.so:${PORTSDIR}/textproc/tinyxml \
		libva.so:${PORTSDIR}/multimedia/libva \
		libvdpau.so:${PORTSDIR}/multimedia/libvdpau \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libxslt.so:${PORTSDIR}/textproc/libxslt \
		libyajl.so:${PORTSDIR}/devel/yajl \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		glxinfo:${PORTSDIR}/graphics/mesa-demos \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow \
		xdpyinfo:${PORTSDIR}/x11/xdpyinfo

USE_GITHUB=	yes
GH_ACCOUNT=	plexinc
GH_PROJECT=	plex-home-theater-public
GH_COMMIT=	2d6426d
GH_TAGNAME=	pht-v1.2.2

USES=		cmake:outsource iconv:wchar_t pkgconfig python:2
CMAKE_ARGS+=	-DENABLE_AUTOUPDATE:BOOL=false
CMAKE_ARGS+=	-DENABLE_DUMP_SYMBOLS:BOOL=false
CMAKE_ARGS+=	-DENABLE_PYTHON:BOOL=false
CMAKE_ARGS+=	-DUSE_INTERNAL_FFMPEG:BOOL=true
CMAKE_ARGS+=	-DCREATE_BUNDLE:BOOL=false
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH=${LOCALBASE}
CFLAGS+=	-isystem${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_XORG=	xt xmu xtst xrandr
USE_GL=		glu
USE_SDL=	image sdl mixer
INSTALLS_ICONS=	yes
ONLY_FOR_ARCHS=	i386 amd64

SUB_FILES=	${PORTNAME}.sh pkg-message

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

CEC_LIB_DEPENDS=	libcec.so:${PORTSDIR}/multimedia/libcec
CEC_CMAKE_OFF=		-DCMAKE_DISABLE_FIND_PACKAGE_CEC:BOOL=true

LIRC_RUN_DEPENDS=	lircd:${PORTSDIR}/comms/lirc

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_PulseAudio:BOOL=true

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
PLIST_SUB+=	ARCH="x86"
.else
PLIST_SUB+=	ARCH="x86_64"
.endif

.if ${OPSYS} == "FreeBSD" && ${OSVERSION} < 900033
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
MAKE_ENV=	COMPILER_PATH=${LOCALBASE}/bin
.endif

post-patch:
	@${REINPLACE_CMD} 's/[[:<:]]ARCH[[:>:]]/FFMPEG_ARCH/' \
		${WRKSRC}/lib/ffmpeg/Makefile \
		${WRKSRC}/lib/ffmpeg/common.mak \
		${WRKSRC}/lib/ffmpeg/configure \
		${WRKSRC}/lib/ffmpeg/libavcodec/Makefile
	@${REINPLACE_CMD} 's/iconv_open/libiconv_open/' \
		${WRKSRC}/plex/CMakeModules/FindIconv.cmake

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
