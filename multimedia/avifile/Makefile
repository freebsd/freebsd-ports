# New ports collection makefile for:   avifile
# Date created: 	16 September 2000
# Whom: 		Holger Lamm
#
# $FreeBSD$
#

PORTNAME=	avifile
PORTVERSION=	0.7.18.20021107
PORTEPOCH=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://avifile.sourceforge.net/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.(.{8})$/-\1/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	holger@e-gitt.net

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_SUBMAKE=	yes
USE_REINPLACE=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:C/^(.{3}).*/\1/}-${PORTVERSION:C/^(.{6}).+$/\1/}

LIBTOOLFILES=	acinclude.m4
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib `${ECHO_CMD} ${PTHREAD_LIBS}`"
CONFIGURE_ARGS= --with-gnu-ld --enable-iconv \
		--disable-divx4
CONFIGURE_TARGET=

PLIST_SUB=	LIB_VERSION="${LIB_VERSION}" VERSION="${VERSION}"

MAN1=		aviplay.1

#CODEC_PORT=	${PORTSDIR}/multimedia/win32-codecs
CODEC_PORT=	${.CURDIR}/../win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE

LIB_VERSION=	3
VERSION=	0.7
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
DIFF?=		/usr/bin/diff
FMT?=		/usr/bin/fmt

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_A52=yes
WITHOUT_XVID=yes
.endif

# compilation optimizations
.if defined(WITH_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--enable-release
. if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-x86opt
. endif
.else
CONFIGURE_ARGS+=	--disable-release
.endif

# soundblaster can be passed ac3 instead of letting avifile decode
# it
.if defined(WITH_AC3_PASSTHROUGH)
CONFIGURE_ARGS+=	--enable-ac3passthrough
PLIST_SUB+=	AC3_PASS=""
.else
CONFIGURE_ARGS+=	--disable-ac3passthrough
PLIST_SUB+=	AC3_PASS="@comment "
.endif

# liba52
.if !defined(WITHOUT_A52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52

CONFIGURE_ARGS+=	--enable-a52 \
			--disable-ffmpeg-a52bin \
			--with-a52-prefix=${LOCALBASE}
PLIST_SUB+=	A52=""
.else
CONFIGURE_ARGS+=	--disable-a52

PLIST_SUB+=	A52="@comment "
.endif

# libmad
.if !defined(WITHOUT_MAD)
LIB_DEPENDS+=	mad.1:${PORTSDIR}/audio/mad

PLIST_SUB+=	MAD=""
.else
CONFIGURE_ARGS+=	--disable-mad
PLIST_SUB+=	MAD="@comment "
.endif

# qt
.if !defined(WITHOUT_QT)
. if exists(${X11BASE}/include/qt2/qapp.h)
USE_QT_VER=	2
. else
USE_QT_VER=	3
. endif
PLIST_SUB+=	QT=""
.else
CONFIGURE_ARGS+=	--without-qt

PLIST_SUB+=	QT="@comment "
.endif

# sdl
.if !defined(WITHOUT_SDL)
LIB_DEPENDS+=	SDL-1.1.4:${PORTSDIR}/devel/sdl12

CONFIGURE_ARGS+=	--with-sdl-prefix=${LOCALBASE} \
			--with-sdl-exec-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

# libvorbis; thus, libogg
.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.2:${PORTSDIR}/audio/libvorbis

CONFIGURE_ARGS+=	--with-vorbis-prefix=${LOCALBASE} \
			--with-ogg-prefix=${LOCALBASE}
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	VORBIS="@comment "
.endif

# xvid
.if !defined(WITHOUT_XVID)
LIB_DEPENDS+=	xvidcore.0:${PORTSDIR}/graphics/xvid

CONFIGURE_ARGS+=	--with-xvid-prefix=${LOCALBASE}
PLIST_SUB+=	XVID=""
.else
CONFIGURE_ARGS+=	--disable-xvid
PLIST_SUB+=	XVID="@comment "
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable compilation optimizations by defining"
	@${ECHO_MSG} "	WITH_OPTIMIZED_CFLAGS."
.endif
.if !defined(WITH_AC3_PASSTHROUGH)
	@${ECHO_MSG} "You can enable soundblaster ac3 passthrough support by"
	@${ECHO_MSG} "	defining WITH_AC3_PASSTHROUGH."
.endif
.if !defined(WITHOUT_A52)
	@${ECHO_MSG} "You can disable ac3 (liba52) support by defining WITHOUT_A52."
.endif
.if !defined(WITHOUT_MAD)
	@${ECHO_MSG} "You can disable mad support by defining WITHOUT_MAD."
.endif
.if !defined(WITHOUT_QT)
	@${ECHO_MSG} "You can disable QT supported tools by defining WITHOUT_QT."
.endif
.if !defined(WITHOUT_SDL)
	@${ECHO_MSG} "You can disable SDL supported tools by defining WITHOUT_SDL."
.endif
.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG} "You can disable vorbis support by defining WITHOUT_VORBIS."
.endif
.if !defined(WITHOUT_XVID)
	@${ECHO_MSG} "You can disable xvid support by defining WITHOUT_XVID."
.endif

pre-extract:
	@if [ -f ${LOCALBASE}/lib/libpth.so ]; then \
	  ${ECHO_MSG} "Error: This packet does not compile when the \
packet 'pth' is installed.";\
	  ${FALSE};\
	fi

post-extract:
# grab does not work outside Linux for now
	@${RM} -f ${WRKSRC}/ffmpeg/libav/grab.c
	@${TOUCH} ${WRKSRC}/ffmpeg/libav/grab.c

post-patch:
# linux/ioctl.h -> sys/ioctl.h
	@${REINPLACE_CMD} -e 's|linux/ioctl.h|sys/ioctl.h|' \
		${WRKSRC}/drivers/libdha/kernelhelper/dhahelper.h
.if !defined(WITHOUT_MAD)
	@${REINPLACE_CMD} -e 's|MAD_LDADD = \@MAD_LDADD\@|MAD_LDADD = -L${LOCALBASE}/lib \@MAD_LDADD\@|' \
		${WRKSRC}/plugins/libmad/Makefile.in
.endif
.if !defined(WITHOUT_QT)
. if exists(${X11BASE}/include/qt2/qapp.h)
	@${REINPLACE_CMD} -e 's|qt-mt|qt2-mt|' ${WRKSRC}/configure
. endif
	@${REINPLACE_CMD} -e 's|QT_CFLAGS = \@QT_CFLAGS\@|QT_CFLAGS = -I${X11BASE}/include \@QT_CFLAGS\@|; \
		s|QT_LIBS = \@QT_LIBS\@|QT_LIBS = -L${X11BASE}/lib \@QT_LIBS\@|' \
		${WRKSRC}/libavqt/Makefile.in
.endif
.if !defined(WITHOUT_XVID)
	@${REINPLACE_CMD} -e 's|XVID_LIBS = \@XVID_LIBS\@|XVID_LIBS = -L${LOCALBASE}/lib \@XVID_LIBS\@|' \
		${WRKSRC}/plugins/libxvid/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|__THROW||' \
		${WRKSRC}/plugins/libwin32/loader/dshow/DS_Filter.h
	@${REINPLACE_CMD} -e 's|-ljpeg|-L${LOCALBASE}/lib -ljpeg|' \
		${WRKSRC}/samples/mjpeg_plugin/Makefile.in
# if we have LAME
	@${REINPLACE_CMD} -e 's|-lmp3lame|-L${LOCALBASE}/lib -lmp3lame|' \
		${WRKSRC}/configure
# use portname without version to build dir names
	@${REINPLACE_CMD} -E -e 's|(PACKAGE[:space:]*=[:space:]*avifile).*|\1|' \
		${WRKSRC}/configure
# fix build in -CURRENT
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|#include <malloc.h>|#include <stdlib.h>|g'
# use correct signal type
	@${REINPLACE_CMD} -e 's|sighandler_t|sig_t|' \
		${WRKSRC}/samples/misc/benchmark.cpp
# fix breakage if either auto{conf,make} are installed
# do not version library names
# fix incorrect behavior of configure script
	@${FIND} ${WRKSRC} \( -name Makefile.in -o -name configure \) | \
		${XARGS} -n 10 ${REINPLACE_CMD} -E -e \
		's|INSTALL = \@INSTALL\@|INSTALL = ${INSTALL}|; \
		s!-release[[:space:]]+\$$\([^\)]+\)!!; \
		s!ACLOCAL =!ACLOCAL = ${TRUE} || !; \
		s!AUTOCONF =!AUTOCONF = ${TRUE} || !; \
		s!AUTOHEADER =!AUTOHEADER = ${TRUE} || !; \
		s!AUTOMAKE =!AUTOMAKE = ${TRUE} || !'

post-configure:
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PKGMESSAGE} ${DOCSDIR}/README
.endif
	@${FMT} < ${PKGMESSAGE}

.if ${ARCH} == "i386"
RUN_DEPENDS+=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

CONFIGURE_ARGS+=	--enable-x86opt \
			--enable-win32 \
			--with-win32-path=${LOCALBASE}/lib/win32

PLIST_SUB+=	FFMPEG="" WIN32=""
.else
CONFIGURE_ARGS+=	--disable-x86opt --disable-win32 \
			--disable-ffmpeg

PLIST_SUB+=	FFMPEG="@comment " WIN32="@comment "
.endif

# hack taken from ogle to make it work with liba52 + djbfft
.if exists(${LOCALBASE}/lib/liba52.la)
LIBA52_DEP_LIBS!=	${GREP} dependency_libs ${LOCALBASE}/lib/liba52.la | ${CUT} -d \' -f 2
.else
LIBA52_DEP_LIBS=
.endif

# if we have LAME
.if exists(${LOCALBASE}/lib/libmp3lame.so)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame

PLIST_SUB+=	NOLAME="@comment " LAME=""
.else
PLIST_SUB+=	NOLAME="" LAME="@comment "
.endif

.include <bsd.port.post.mk>
