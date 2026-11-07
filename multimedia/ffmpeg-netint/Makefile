PORTNAME=	ffmpeg-netint
DISTVERSIONPREFIX=	v
DISTVERSION=	5.9.0
CATEGORIES=	multimedia

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	FFmpeg with NETINT Quadra hardware codecs and filters
WWW=		https://github.com/NETINT-Technologies/netint_ffmpeg

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LGPLv2.1

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	NETINT supports Quadra cards only on these architectures
IGNORE_FreeBSD_14=	needs the Linux-compatible ioctls of nvme(4), added in FreeBSD 15.0

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libxcoder.so:multimedia/libxcoder

USES=		compiler:c11 gmake iconv localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	NETINT-Technologies
GH_PROJECT=	netint_ffmpeg

HAS_CONFIGURE=	yes
# FFmpeg 7.1 based: keep out of the way of multimedia/ffmpeg
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--datadir="${DATADIR}" \
		--incdir="${PREFIX}/include/${PORTNAME}" \
		--libdir="${PREFIX}/lib/${PORTNAME}" \
		--pkgconfigdir="${PREFIX}/lib/${PORTNAME}/pkgconfig" \
		--progs-suffix="-netint" \
		--cc="${CC}" \
		--cxx="${CXX}" \
		--disable-autodetect \
		--disable-doc \
		--disable-static \
		--enable-bzlib \
		--enable-iconv \
		--enable-libfontconfig \
		--enable-libfreetype \
		--enable-libfribidi \
		--enable-ni_quadra \
		--enable-pic \
		--enable-pthreads \
		--enable-rpath \
		--enable-shared \
		--enable-zlib
CONFIGURE_LOG=	ffbuild/config.log
MAKE_ENV=	V=1
NOPRECIOUSMAKEVARS=	yes # ARCH

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--disable-stripping
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.include <bsd.port.mk>
