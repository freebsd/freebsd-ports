# New ports collection makefile for:	ffmpeg
# Date created:		Tue Sep 25 15:52:09 BRT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ffmpeg
PORTVERSION=	0.4.5
PORTREVISION=	7
CATEGORIES=	multimedia audio net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	lioux
DISTNAME=	ffmpeg-cvs-2002101400

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Hyper fast realtime audio/video encoder/converter, streaming server

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

WRKSRC=		${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=	i386
USE_GETOPT_LONG=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS= --cc="${CC}" --prefix="${PREFIX}" \
		--make="${GMAKE}" --enable-shared \
		--extra-libs="-lm -L${LOCALBASE}/lib"
PLIST_SUB=	SHLIB_VERSION=${SHLIB_VERSION}
INSTALLS_SHLIB=	yes
NO_LATEST_LINK=	yes

SHLIB_VERSION=	0
#
DOC_FILES=	COPYING Changelog README VERSION
# under subdir doc
DOC_DOCFILES=	FAQ README.dev README.tech \
		TODO bench.txt ffmpeg.txt \
		HOWTO-STREAM README.beos \
		ffserver.txt
HEADER_FILES=	libavcodec/avcodec.h libavcodec/common.h \
		libavcodec/dsputil.h
LIB_FILES=	libavcodec/libavcodec.a libav/libavformat.a

.include <bsd.port.pre.mk>

## lib detection
##
## lame mp3
.if exists(${LOCALBASE}/lib/libmp3lame.so.0)
WITH_MP3=yes
.endif
## vorbis
.if exists(${LOCALBASE}/lib/libvorbisenc.so.2)
WITH_VORBIS=yes
.endif

## support activation
##
## disable a52
.ifndef(WITHOUT_A52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52

CONFIGURE_ARGS+=	--enable-a52 \
			--enable-a52bin
.else
CONFIGURE_ARGS+=	--enable-a52 \
			--disable-a52bin
.endif
## disable mmx
.ifdef(WITHOUT_MMX)
CONFIGURE_ARGS+=	--disable-mmx
.endif
## mp3
.ifdef(WITH_MP3)
LIB_DEPENDS+=		mp3lame.0:${PORTSDIR}/audio/lame

CONFIGURE_ARGS+=	--enable-mp3lame
.endif
## optimization
.ifdef(WITH_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--extra-cflags="${CFLAGS} -I${LOCALBASE}/include \
				-O3 -ffast-math -fomit-frame-pointer"
.else
CONFIGURE_ARGS+=	--extra-cflags="${CFLAGS} -I${LOCALBASE}/include"
.endif
## vorbis
.ifdef(WITH_VORBIS)
LIB_DEPENDS+=		vorbisenc.2:${PORTSDIR}/audio/libvorbis

CONFIGURE_ARGS+=	--enable-vorbis
.endif

pre-everything::
.ifndef(WITHOUT_LIBA52)
	@${ECHO_MSG} "You can disable liba52 support by defining WITHOUT_LIBA52"
.endif
.ifndef(WITHOUT_MMX)
	@${ECHO_MSG} "Define WITHOUT_MMX if your system does not support MMX"
.endif
.ifndef(WITH_MP3)
	@${ECHO_MSG} 'Define WITH_MP3 to enable lame MP3 codec'
.endif
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG}
	@${ECHO_MSG} 'You can enable additional compilation optimizations'
	@${ECHO_MSG} 'by defining WITH_OPTIMIZED_CFLAGS'
.endif
.ifndef(WITH_VORBIS)
	@${ECHO_MSG} 'Define WITH_VORBIS to enable libvorbisenc VORBIS codec'
.endif
.if !(defined(WITH_BKTR_FORMAT) && defined(WITH_BKTR_DEV))
	@${ECHO_MSG}
	@${ECHO_MSG} 'If you want to capture from a bktr(4) supported card'
	@${ECHO_MSG} 'you will probably need to set the input device and format'
	@${ECHO_MSG} 'You can set WITH_BKTR_FORMAT to NTSC or PAL and you can set'
	@${ECHO_MSG} 'WITH_BKTR_DEV to 0, 1, 2 or 3 (1 is usually the tuner)'
	@${ECHO_MSG} 'so for a PAL tuner make WITH_BKTR_FORMAT=PAL WITH_BKTR_DEV=1'
	@${ECHO_MSG}
	@${ECHO_MSG} 'Warning: invalid settings will probably dump cores'
	@${ECHO_MSG}
.endif

post-extract:
# install booktree extension
	@${CP} ${FILESDIR}/grab_bsdbktr.c ${WRKSRC}/libav/

post-patch:
	@${REINPLACE_CMD} -e "s!/etc/ffserver.conf!${PREFIX}/etc/ffserver.conf!g" \
		${WRKSRC}/ffserver.c
# malloc.h was deprecated in favor of stdlib.h
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|malloc.h|stdlib.h|'
.ifdef(WITH_BKTR_FORMAT)
	@${REINPLACE_CMD} -e \
		"s!VIDEO_FORMAT NTSC!VIDEO_FORMAT ${WITH_BKTR_FORMAT}!" \
		${WRKSRC}/libav/grab_bsdbktr.c
.endif
.ifdef(WITH_BKTR_DEV)
	@${REINPLACE_CMD} -e \
		"s!VIDEO_INPUT METEOR_INPUT_DEV0!VIDEO_INPUT METEOR_INPUT_DEV${WITH_BKTR_DEV}!" \
		${WRKSRC}/libav/grab_bsdbktr.c
.endif
.ifndef(WITHOUT_LIBA52)
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${WRKSRC}/configure
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for file in ${DOC_DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif
	@${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${PREFIX}/etc/ffserver.conf.sample
.for file in ${HEADER_FILES}
# fix header references prior to installation
	@${REINPLACE_CMD} -e 's|"common.h"|<ffmpeg/common.h>|; \
		s|"avcodec.h"|<ffmpeg/avcodec.h>|' \
		${WRKSRC}/${file}
	@${INSTALL_DATA} ${WRKSRC}/${file} \
		${PREFIX}/include/ffmpeg/${file:T}
.endfor
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/${file:T}
.endfor
# add shared lib link
	@${LN} -sf libavcodec.so \
		${PREFIX}/lib/libavcodec.so.${SHLIB_VERSION}
# show PKGMESSAGE
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
