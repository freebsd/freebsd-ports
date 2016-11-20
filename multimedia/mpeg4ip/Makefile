# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpeg4ip
PORTVERSION=	1.6.1
PORTREVISION=	35
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	LOCAL/ahze
# http://sourceforge.net/forum/forum.php?thread_id=1839453&forum_id=59136
#MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Standards-based system to encode, stream, and play MPEG-4 audio/video

BUILD_DEPENDS=	mp4v2>=1.9.1:multimedia/mp4v2 \
		${LOCALBASE}/include/linux/videodev.h:multimedia/v4l_compat
LIB_DEPENDS=	libfaac.so:audio/faac \
		libfaad.so:audio/faad \
		libmp3lame.so:audio/lame \
		libid3tag.so:audio/libid3tag \
		liba52.so:audio/liba52 \
		libmpeg2.so:multimedia/libmpeg2 \
		libavcodec0.so:multimedia/ffmpeg0 \
		libx264.so:multimedia/libx264
RUN_DEPENDS=	mp4v2>=1.9.1:multimedia/mp4v2

USE_GNOME=	gtk20
USE_SDL=	sdl
USES=		gmake libtool pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-Wno-return-type
CPPFLAGS+=	-I${LOCALBASE}/include/SDL -I${LOCALBASE}/include/ffmpeg0 -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib/ffmpeg0 -L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-ffmpeg=${LOCALBASE} \
		--enable-mp4live \
		--disable-static

OPTIONS_DEFINE=		ESOUND IPV6 NAS OPTIMIZED_CFLAGS XVID DOCS
OPTIONS_DEFAULT=	XVID

DOC_FILES=	${PORTDOCS}
PORTDOCS=	MAINREADME.html MP4LIVE_INTERNALS.html MPEG4IP_Guide.pdf \
		MP4LIVE_README.html PLAYER_INTERNALS.html PLAYER_README.html \
		ReadingList.txt encoding.htm m4rm.html \
		mp4player.jpg mrm.html pi.html prm.html

.include <bsd.port.options.mk>

###
## Auto detect possible extensions
###
# esound
.if exists(${LOCALBASE}/bin/esd-config) && empty(PORT_OPTIONS:MESOUND)
PORT_OPTIONS+=	ESOUND
.endif
# nas
.if exists(${LOCALBASE}/lib/libaudio.so) && empty(PORT_OPTIONS:MNAS)
PORT_OPTIONS+=	NAS
.endif
# xvid
.if exists(${LOCALBASE}/lib/libxvidcore.so) && empty(PORT_OPTIONS:MXVID)
PORT_OPTIONS+=	XVID
.endif

###
## Enable extensions based on user choices
###
# esound
.if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=	esound
.endif
# nas
.if ${PORT_OPTIONS:MNAS}
LIB_DEPENDS+=	libaudio.so:audio/nas
.endif

# ipv6
.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

# xvid
.if ${PORT_OPTIONS:MXVID}
LIB_DEPENDS+=	libxvidcore.so:multimedia/xvid

PLIST_SUB+=	XVID=""
.else
PLIST_SUB+=	XVID="@comment "
.endif

#post-patch:
pre-configure:
	@${TOUCH} -f ${WRKSRC}/bootstrapped
# don't compile or use libmp4v2
	@${REINPLACE_CMD} -e 's|mp4v2||' \
		${WRKSRC}/lib/Makefile.in
	@${FIND} ${WRKSRC} -type f -name Makefile.in | \
		${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|$$(top_builddir)/lib/mp4v2/libmp4v2.la||; \
		s|$$(top_srcdir)/lib/mp4v2/libmp4v2.la||; \
		s|@LIBS@|@LIBS@ -lmp4v2|; \
		s|nasm|yasm|'
	@${REINPLACE_CMD} -e 's|-Werror||' \
		${WRKSRC}/common/video/iso-mpeg4/src/Makefile.in
	@${REINPLACE_CMD} -e 's|mp4venc_template.par||' \
		${WRKSRC}/server/util/mp4encode/Makefile.in
	@${FIND} ${WRKSRC} -type f -name "*.[ch]" -or -name "*.cpp" | ${XARGS} -n 10 \
		${REINPLACE_CMD} -e \
		's|<stdint.h>|<inttypes.h>|; \
		s|<malloc.h>|<stdlib.h>|; \
		s|<avcodec.h>|<libavcodec/avcodec.h>|; \
		s|<swscale.h>|<libswscale/swscale.h>|; \
		s|<strstream.h>|<iostream>|'
# replacing distfile's libs with ports' versions
# SDL related fixes
# a few others
	@${REINPLACE_CMD} -E -e 's|lib/SDL/sdl-config|${SDL_CONFIG}|; \
		s|sdl-config|${SDL_CONFIG}|; \
		s|^(SDL_LIBS=).+$$|\1"`${SDL_CONFIG} --libs`"|; \
		s|-Wmissing-declarations||; s|-Wmissing-prototypes||; \
		s|>&/|>/|; s|nasm|yasm|' \
		${CONFIGURE_WRKSRC}/configure
# do not install manm man pages
	@${REINPLACE_CMD} -E \
		-e 's|api.mpt||' \
		-e 's|^(install-man.*)install-manm|\1|' \
		${WRKSRC}/doc/mp4v2/Makefile.in
	@${REINPLACE_CMD} -e 's|$${enable_ffmpeg}/lib/libavcodec.a|-lavcodec0 -lavutil0 -lswscale0|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|pSameples|pSamples|' \
		${WRKSRC}/server/mp4live/audio_l16.cpp

# replace bundled mp4v2 with placeholder
post-configure:
	@${RM} -r ${WRKSRC}/lib/mp4v2
	@${MKDIR} ${WRKSRC}/lib/mp4v2
	@echo '#include "mpeg4ip.h"' > ${WRKSRC}/lib/mp4v2/mp4.h

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/server/util/mp4encode/mp4encode \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} \
		${WRKSRC}/server/util/mp4encode/mp4venc_template.par \
		${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.if (defined(MACHINE_CPU) && ${MACHINE_CPU:Mmmx} == "mmx") && !defined(PACKAGE_BUILDING)
MMX=yes
.endif

###
## Enable extensions based on arch detection
###
# mmx
.if defined(MMX)
BUILD_DEPENDS+=	yasm:devel/yasm
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif
# compiler optimizations
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.endif

.include <bsd.port.mk>
