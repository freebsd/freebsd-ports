PORTNAME=	ffmpeg
DISTVERSION=	3.0.2
CATEGORIES=	multimedia audio net
MASTER_SITES=	https://ffmpeg.org/releases/
PKGNAMESUFFIX=	3

PATCH_SITES=	https://github.com/hrydgard/ppsspp-ffmpeg/commit/
PATCHFILES=	9c4f84d9d9ad147f4a44cff582829647a0c65420.patch:-p1

MAINTAINER=	kreinholz@gmail.com
COMMENT=	Realtime audio/video encoder/converter and streaming server (legacy 3.* series)
WWW=		https://ffmpeg.org/

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

NOT_FOR_ARCHS=	mips mips64 powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	emulators/ppsspp only supports little-endian, see \
		https://github.com/hrydgard/ppsspp/issues/8823

USES=		compiler:c11 cpe gmake localbase:ldflags perl5 pkgconfig \
		shebangfix tar:xz
USE_PERL5=	build
SHEBANG_FILES=	doc/texi2pod.pl
USE_LDCONFIG=	yes

.ifdef PKGNAMESUFFIX
PORTSCOUT=	limit:^3\.
PREFIX=		${LOCALBASE}/${PKGBASE} # avoid conflict with the default
.endif

HAS_CONFIGURE=	yes
CONFIGURE_LOG=	ffbuild/config.log

LDFLAGS_aarch64=-Wl,-z,notext

INSTALL_TARGET=	install-libs install-headers

NOPRECIOUSMAKEVARS=	yes
MAKE_ENV+=	V=1

.if defined(WITH_DEBUG)
CONFIGURE_ARGS=	--disable-stripping
.else
CONFIGURE_ARGS=	--disable-debug
.endif

CONFIGURE_ARGS+=--prefix="${PREFIX}" \
		--pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		--enable-static \
		--disable-shared \
		--enable-pic \
		--enable-zlib \
		--disable-everything \
		--enable-gpl \
		--cc="${CC}" \
		--cxx="${CXX}" \
		--disable-avdevice \
		--disable-filters \
		--disable-programs \
		--disable-network \
		--disable-avfilter \
		--disable-postproc \
		--disable-encoders \
		--disable-doc \
		--disable-ffplay \
		--disable-ffprobe \
		--disable-ffserver \
		--disable-ffmpeg \
		--enable-decoder=h264 \
		--enable-decoder=mpeg4 \
		--enable-decoder=h263 \
		--enable-decoder=h263p \
		--enable-decoder=mpeg2video \
		--enable-decoder=mjpeg \
		--enable-decoder=mjpegb \
		--enable-decoder=aac \
		--enable-decoder=aac_latm \
		--enable-decoder=atrac3 \
		--enable-decoder=atrac3p \
		--enable-decoder=mp3 \
		--enable-decoder=pcm_s16le \
		--enable-decoder=pcm_s8 \
		--enable-demuxer=h264 \
		--enable-demuxer=h263 \
		--enable-demuxer=m4v \
		--enable-demuxer=mpegps \
		--enable-demuxer=mpegvideo \
		--enable-demuxer=avi \
		--enable-demuxer=mp3 \
		--enable-demuxer=aac \
		--enable-demuxer=pmp \
		--enable-demuxer=oma \
		--enable-demuxer=pcm_s16le \
		--enable-demuxer=pcm_s8 \
		--enable-demuxer=wav \
		--enable-encoder=ffv1 \
		--enable-encoder=huffyuv \
		--enable-encoder=mpeg4 \
		--enable-encoder=pcm_s16le \
		--enable-muxer=avi \
		--enable-parser=h264 \
		--enable-parser=mpeg4video \
		--enable-parser=mpegvideo \
		--enable-parser=aac \
		--enable-parser=aac_latm \
		--enable-parser=mpegaudio \
		--enable-protocol=file \
		--disable-sdl \
		--disable-asm \
		--disable-iconv \
		--disable-vaapi \
		--disable-hwaccels

OPTIONS_DEFINE=		LTO OPTIMIZED_CFLAGS RTCPU
OPTIONS_DEFAULT=	LTO OPTIMIZED_CFLAGS
OPTIONS_DEFAULT_amd64=	RTCPU
OPTIONS_EXCLUDE_aarch64=RTCPU

RTCPU_DESC=		Detect CPU capabilities at runtime

LTO_CONFIGURE_ENABLE=	lto

OPTIMIZED_CFLAGS_CONFIGURE_ENABLE=	optimizations

RTCPU_CONFIGURE_ENABLE=	runtime-cpudetect

.include <bsd.port.mk>
