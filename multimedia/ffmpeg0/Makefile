# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffmpeg
PORTVERSION=	0.7.17
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	http://ffmpeg.org/releases/
PKGNAMESUFFIX=	0

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Realtime audio/video encoder/converter and streaming server

LICENSE=		GPLv2+ LGPL21+
LICENSE_COMB=		multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING.GPLv2
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPLv2.1

BUILD_DEPENDS=	yasm:devel/yasm \
		${LOCALBASE}/bin/as:devel/binutils \
		${LOCALBASE}/bin/texi2html:textproc/texi2html

PORTSCOUT=	limit:^0\.7.*

USES=		cpe gmake perl5 pkgconfig tar:bzip2 shebangfix
USE_LDCONFIG=	${PREFIX}/lib/ffmpeg${FFMPEG_SUFFIX}
USE_PERL5=	build
SHEBANG_FILES=	doc/texi2pod.pl
NOPRECIOUSMAKEVARS=	yes # ARCH

FFMPEG_SUFFIX=	0
HAS_CONFIGURE=	yes
CONFIGURE_LOG=	config.err
CONFIGURE_ENV+=	EXESUF="${FFMPEG_SUFFIX}"
MAKE_ARGS+=	EXESUF="${FFMPEG_SUFFIX}"
PLIST_SUB+=	SUFF="${FFMPEG_SUFFIX}"
PROGS=		ffmpeg ffprobe

CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin

CONFIGURE_ARGS+=--prefix="${PREFIX}" \
		--mandir="${PREFIX}/man" \
		--incdir="${PREFIX}/include/ffmpeg${FFMPEG_SUFFIX}" \
		--libdir="${PREFIX}/lib/ffmpeg${FFMPEG_SUFFIX}" \
		--shlibdir="${PREFIX}/lib/ffmpeg${FFMPEG_SUFFIX}" \
		--datadir="${DATADIR}" \
		--build-suffix="${FFMPEG_SUFFIX}" \
		--enable-shared \
		--enable-gpl \
		--enable-postproc \
		--enable-avfilter \
		--enable-pthreads \
		--enable-runtime-cpudetect \
		--cc="${CC}" \
		--extra-cflags="${FFMPEG_CFLAGS} -I${LOCALBASE}/include" \
		--extra-ldflags="-L${LOCALBASE}/lib ${FFMPEG_LDFLAGS}" \
		--extra-libs="-lpthread"

SHLIB_VER=	1
PLIST_SUB+=	SHLIB_VER=${SHLIB_VER}

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=		AACPLUS ALSA AMR_NB AMR_WB CELT DEBUG DIRAC FAAC \
			FFSERVER FREETYPE FREI0R GSM LAME OPENCV OPENJPEG \
			OPTIMIZED_CFLAGS RTMP SCHROEDINGER SDL SPEEX THEORA VAAPI \
			VDPAU VO_AACENC VO_AMRWBENC VORBIS VPX X11GRAB X264 XVID DOCS
OPTIONS_DEFAULT=	FFSERVER FREETYPE FREI0R OPENCV SCHROEDINGER \
			THEORA VORBIS VPX X264 XVID
OPTIONS_SUB=		yes

FFSERVER_DESC=		Build and install ffserver
X11GRAB_DESC=		Enable x11 grabbing

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_OFF=	--disable-indev=alsa \
			--disable-outdev=alsa

CELT_LIB_DEPENDS=	libcelt0.so:audio/celt
CELT_CONFIGURE_ENABLE=	libcelt

DIRAC_LIB_DEPENDS=	libdirac_encoder.so:multimedia/dirac
DIRAC_CONFIGURE_ENABLE=	libdirac

DEBUG_CONFIGURE_ON=	--disable-stripping
DEBUG_CONFIGURE_OFF=	--disable-debug

FFSERVER_CONFIGURE_OFF=	--disable-ffserver

FREETYPE_LIB_DEPENDS=		libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	libfreetype

FREI0R_BUILD_DEPENDS=		${LOCALBASE}/include/frei0r.h:graphics/frei0r
FREI0R_CONFIGURE_ENABLE=	frei0r

GSM_LIB_DEPENDS=		libgsm.so:audio/gsm
GSM_CONFIGURE_ENABLE=		libgsm

LAME_LIB_DEPENDS=		libmp3lame.so:audio/lame
LAME_CONFIGURE_ENABLE=		libmp3lame

OPENCV_LIB_DEPENDS=		libopencv_imgproc.so:graphics/opencv2-core
OPENCV_CONFIGURE_ENABLE=	libopencv

OPENJPEG_LIB_DEPENDS=		libopenjpeg.so:graphics/openjpeg15
OPENJPEG_CONFIGURE_ENABLE=	libopenjpeg

RTMP_USE=			OPENSSL=yes

SCHROEDINGER_LIB_DEPENDS=	libschroedinger-1.0.so:multimedia/schroedinger
SCHROEDINGER_CONFIGURE_ENABLE=	libschroedinger

SPEEX_LIB_DEPENDS=		libspeex.so:audio/speex
SPEEX_CONFIGURE_ENABLE=		libspeex

THEORA_LIB_DEPENDS=		libtheora.so:multimedia/libtheora
THEORA_CONFIGURE_ENABLE=	libtheora

X11GRAB_USE=		XORG=x11,xext,xfixes
X11GRAB_CONFIGURE_ON=	--enable-x11grab

X264_LIB_DEPENDS=	libx264.so:multimedia/libx264
X264_CONFIGURE_ENABLE=	libx264

XVID_LIB_DEPENDS=	libxvidcore.so:multimedia/xvid
XVID_CONFIGURE_ENABLE=	libxvid

VDPAU_BUILD_DEPENDS=	${LOCALBASE}/include/vdpau/vdpau.h:multimedia/libvdpau
VDPAU_CONFIGURE_ENABLE=	vdpau

VPX_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
VPX_CONFIGURE_ENABLE=	libvpx

COMPAT_HEADERS=libavcodec/avcodec.h \
	libavcodec/opt.h \
	libavcodec/vdpau.h \
	libavcodec/xvmc.h \
	libavdevice/avdevice.h \
	libavfilter/avfilter.h \
	libavformat/avformat.h \
	libavformat/avio.h \
	libavutil/adler32.h \
	libavutil/avstring.h \
	libavutil/avutil.h \
	libavutil/base64.h \
	libavutil/common.h \
	libavutil/crc.h \
	libavutil/fifo.h \
	libavutil/intfloat_readwrite.h \
	libavutil/log.h \
	libavutil/lzo.h \
	libavutil/mathematics.h \
	libavutil/md5.h \
	libavutil/mem.h \
	libavutil/pixfmt.h \
	libavutil/rational.h \
	libavutil/sha1.h \
	libpostproc/postprocess.h \
	libswscale/swscale.h

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD" && ${OSVERSION} < 1000000
CONFIGURE_ARGS+=	--enable-memalign-hack
.endif

.if ${ARCH} == armv6
CONFIGURE_ENV+=	ASFLAGS=-no-integrated-as
CFLAGS+=	-no-integrated-as
.endif

DOC_FILES=	CREDITS INSTALL LICENSE MAINTAINERS README RELEASE
# under doc subdirectory
DOC_DOCFILES=	APIchanges RELEASE_NOTES TODO *.txt *.html

.if ${PORT_OPTIONS:MFFSERVER}
USE_RC_SUBR=	ffserver${FFMPEG_SUFFIX}
PROGS+=		ffserver
.endif

# sse hardware vector support
.if defined(MACHINE_CPU) && (${MACHINE_CPU:Msse} == "sse" || ${MACHINE_CPU:Mamd64} == "amd64")
_BUILTIN_VECTOR=	yes
.else
CONFIGURE_ARGS+=	--disable-sse
.endif

# mmx support
.if defined(MACHINE_CPU) && ${MACHINE_CPU:Mmmx} == "" && ${MACHINE_CPU:Mamd64} == ""
CONFIGURE_ARGS+=	--disable-mmx
_NO_BUILTIN_VECTOR=	yes
.endif

# builtin vector, requires mmx and sse
.if !defined(_NO_BUILTIN_VECTOR) && defined(_BUILTIN_VECTOR)
CFLAGS+=	-msse
.endif

# optimizations
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math -fno-finite-math-only -fomit-frame-pointer
.endif

#aacplus
.if ${PORT_OPTIONS:MAACPLUS}
FFMPEG_NONFREE=	yes
LIB_DEPENDS+=	libaacplus.so:audio/libaacplus
CONFIGURE_ARGS+=	--enable-libaacplus
.else
CONFIGURE_ARGS+=	--disable-libaacplus
.endif

# Opencore AMR NB
.if ${PORT_OPTIONS:MAMR_NB}
FFMPEG_LICENSE_GPL3=	yes
LIB_DEPENDS+=	libopencore-amrnb.so:audio/opencore-amr
CONFIGURE_ARGS+=	--enable-libopencore-amrnb
.else
CONFIGURE_ARGS+=	--disable-libopencore-amrnb
.endif

# Opencore AMR WB
.if ${PORT_OPTIONS:MAMR_WB}
FFMPEG_LICENSE_GPL3=	yes
LIB_DEPENDS+=	libopencore-amrwb.so:audio/opencore-amr
CONFIGURE_ARGS+=	--enable-libopencore-amrwb
.else
CONFIGURE_ARGS+=	--disable-libopencore-amrwb
.endif

# faac
.if ${PORT_OPTIONS:MFAAC}
FFMPEG_NONFREE=	yes
LIB_DEPENDS+=	libfaac.so:audio/faac
CONFIGURE_ARGS+=	--enable-libfaac
.else
CONFIGURE_ARGS+=	--disable-libfaac
.endif

# rtmp
.if ${PORT_OPTIONS:MRTMP}
LIB_DEPENDS+=	librtmp.so:multimedia/librtmp
CONFIGURE_ARGS+=	--enable-librtmp
. if ${OPENSSLBASE} != "/usr"
FFMPEG_CFLAGS+=		-I${OPENSSLINC}
FFMPEG_LDFLAGS+=	-L${OPENSSLLIB}
. endif
.else
CONFIGURE_ARGS+=	--disable-librtmp
.endif

# sdl
.if ${PORT_OPTIONS:MSDL}
USE_SDL+=	sdl
PLIST_FILES+=	bin/ffplay${FFMPEG_SUFFIX} man/man1/ffplay${FFMPEG_SUFFIX}.1.gz
PROGS+=		ffplay
.else
CONFIGURE_ARGS+=	--disable-ffplay
.endif

# vaapi
.if ${PORT_OPTIONS:MVAAPI}
FFMPEG_LICENSE_GPL3=	yes
LIB_DEPENDS+=	libva.so:multimedia/libva
CONFIGURE_ARGS+=	--enable-vaapi
.else
CONFIGURE_ARGS+=	--disable-vaapi
.endif

# vo-aacenc
.if ${PORT_OPTIONS:MVO_AACENC}
FFMPEG_LICENSE_GPL3=	yes
LIB_DEPENDS+=	libvo-aacenc.so:audio/vo-aacenc
CONFIGURE_ARGS+=	--enable-libvo-aacenc
.else
CONFIGURE_ARGS+=	--disable-libvo-aacenc
.endif

# vo-amrwbenc
.if ${PORT_OPTIONS:MVO_AMRWBENC}
FFMPEG_LICENSE_GPL3=	yes
LIB_DEPENDS+=	libvo-amrwbenc.so:audio/vo-amrwbenc
CONFIGURE_ARGS+=	--enable-libvo-amrwbenc
.else
CONFIGURE_ARGS+=	--disable-libvo-amrwbenc
.endif

# vorbis
.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbisenc.so:audio/libvorbis
CONFIGURE_ARGS+=	--enable-libvorbis
FFMPEG_CFLAGS+=		-I${LOCALBASE}/include/vorbis
.else
CONFIGURE_ARGS+=	--disable-libvorbis
.endif

# License knobs
.if defined(FFMPEG_NONFREE)
RESTRICTED=	linking to libfaac or libaacplus restricts redistribution
CONFIGURE_ARGS+=	--enable-nonfree
.endif

.if defined(FFMPEG_LICENSE_GPL3)
LICENSE+=		GPLv3+ LGPL3+
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.GPLv3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPLv3
CONFIGURE_ARGS+=	--enable-version3
.endif

post-patch:
# {C,LD}FLAGS safeness
	@${REINPLACE_CMD} -e 's|$$(LIBDIR)/pkgconfig|$$(DESTDIR)$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/subdir.mak
	@${REINPLACE_CMD} -e 's|/etc/ffserver.conf|${PREFIX}/etc/ffserver${FFMPEG_SUFFIX}.conf|' \
		${WRKSRC}/ffserver.c
	@${REINPLACE_CMD} -E \
		-e "s|(EXTRALIBS[[:space:]]*=)|\1-L${LOCALBASE}/lib |g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|gsm/gsm.h|gsm.h|g" \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|-ldl||; s|$$(LIBMAJOR)|${SHLIB_VER}|g;' \
		-e 's|opencv opencv/cxcore.h|opencv-core opencv2/core/core_c.h|g' \
		-e 's|check_ldflags -Wl,--as-needed||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.if ${PORT_OPTIONS:MSDL}
	@${REINPLACE_CMD} -E \
		-e 's|sdl-config|${SDL_CONFIG}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -E \
		-e 's|#include <SDL|#include <SDL/SDL|'
.endif

post-configure:
.if empty(PORT_OPTIONS:MTHEORA)
	@${REINPLACE_CMD} -E \
		-e 's|^(CONFIG_LIBTHEORA).*$$|\1=no|' \
		${WRKSRC}/config.mak
.endif
	@${REINPLACE_CMD} -E \
		-e 's|\$$\(INSTALL\) -m 644 \$$\(MANPAGES\) "\$$\(MANDIR\)/man1"||g' \
			${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E \
		-e 's|\$$\$$\(INSTALL\) -m 644 \$$\$$\^ "\$$\(DESTDIR\)\$$\(prefix\)/libdata/pkgconfig"|\$$\$$\(INSTALL\) -m 644 \$$\$$\^ "\$$\(DESTDIR\)\$$\(prefix\)/libdata/pkgconfig/lib\$$\(NAME\)0.pc"|' \
			${WRKSRC}/subdir.mak

post-install:
.if ${PORT_OPTIONS:MFFSERVER}
	${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf ${STAGEDIR}${PREFIX}/etc/ffserver${FFMPEG_SUFFIX}.conf-dist
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.for FILE in ${DOC_DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.for i in ${PROGS}
	${INSTALL_MAN} ${WRKSRC}/doc/${i}.1 ${STAGEDIR}${MANPREFIX}/man/man1/${i}0.1
.endfor
	@${REINPLACE_CMD} \
		-e 's|libavcodec|libavcodec0|' \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libavformat0.pc
	@${REINPLACE_CMD} \
		-e 's|libavutil|libavutil0|' \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libavcodec0.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libpostproc0.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libswscale0.pc
	@${REINPLACE_CMD} \
		-e 's|libavformat|libavformat0|' \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libavdevice0.pc
	@${RM}	${STAGEDIR}${PREFIX}/libdata/pkgconfig/libavcodec0.pc.bak \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libpostproc0.pc.bak \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libswscale0.pc.bak \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libavformat0.pc.bak \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libavdevice0.pc.bak

.include <bsd.port.post.mk>
