# New ports collection makefile for:	x264
# Date created:		2005-01-11
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	x264
PORTVERSION=	0.0.20050125
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_LOCAL:S|$|ahze/|}
#		http://download.videolan.org/pub/videolan/contrib/ \
#		http://ftp.snt.utwente.nl/pub/software/videolan/contrib/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0.0.//}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Multimedia library and tool for encoding H.264/AVC video streams

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386

USE_GETOPT_LONG=yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=	default
SHLIB_VER=	0
CFLAGS+=	-DSYS_FREEBSD
INSTALLS_SHLIB=	yes

PLIST_FILES=	bin/x264 \
		include/x264.h \
		lib/libx264.a \
		lib/libx264.so \
		lib/libx264.so.${SHLIB_VER}

OPTIONS=	DEBUG "Enable Debugging" Off \
		OPTIMIZED_CFLAGS "Enable Optimized CFLAGS" Off

.include <bsd.port.pre.mk>

.if ${ARCH}=="i386"
CFLAGS+=-DARCH_X86
.endif

.if ${MACHINE_CPU:Mmmx}
CFLAGS+=-DHAVE_MMXEXT
.endif

.if ${MACHINE_CPU:Msse}
CFLAGS+=-DHAVE_SSE2
.endif

.if !defined(WITH_DEBUG)
MAKE_ENV+=	NDEBUG="1"
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O2 -funroll-loops
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%CFLAGS%%|${CPPFLAGS} ${CFLAGS}|; \
		s|%%SHLIB_VER%%|${SHLIB_VER}|; \
		s|-lm|${LDFLAGS} -lm|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x264 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/x264.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libx264.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libx264.so.${SHLIB_VER} ${PREFIX}/lib
	${LN} -sf libx264.so.${SHLIB_VER} ${PREFIX}/lib/libx264.so

.include <bsd.port.post.mk>
