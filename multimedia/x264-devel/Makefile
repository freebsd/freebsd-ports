# New ports collection makefile for:	x264
# Date created:		2005-01-11
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	x264
PORTVERSION=	0.0.20041029
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/contrib/ \
		http://ftp.snt.utwente.nl/pub/software/videolan/contrib/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0.0.//}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Multimedia library for encoding H.264/AVC video streams

BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm

USE_GETOPT_LONG=yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=	default
CFLAGS+=	-DSYS_FREEBSD

PLIST_FILES=	bin/x264 \
		include/x264.h \
		lib/libx264.a

OPTIONS=	DEBUG "Enable Debugging" Off \
		OPTIMIZED_CFLAGS "Enable Optimized CFLAGS" Off

.include <bsd.port.pre.mk>

.if ${ARCH}=="i386" || ${ARCH}=="amd64"
CFLAGS+=-DARCH_X86
.if ${MACHINE_CPU:Mmmx}
CFLAGS+=-DHAVE_MMXEXT
.endif
.if ${MACHINE_CPU:Msse}
CFLAGS+=-DHAVE_SSE2
.endif
.endif

.if defined(WITH_DEBUG)
CFLAGS+=	-g -DDEBUG
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O2 -funroll-loops
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%CFLAGS%%|${CFLAGS} ${CPPFLAGS}|; \
		s|-lm|${LDFLAGS} -lm|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x264 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/x264.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libx264.a ${PREFIX}/lib

.include <bsd.port.post.mk>
