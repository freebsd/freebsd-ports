# New ports collection makefile for:	gavl
# Date created:		2004-08-29
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	gavl
PORTVERSION=	1.1.1
CATEGORIES=	multimedia
MASTER_SITES=	SF/gmerlin/${PORTNAME}/${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	A library for handling uncompressed video and audio data

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		samplerate.1:${PORTSDIR}/audio/libsamplerate

USE_GNOME=	pkgconfig gnometarget gnomehack
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-cpuflags --without-doxygen

PORTDOCS=	README

OPTIONS=	OPTIMIZED_CFLAGS "Additional optimizations" off

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_CFLAGS) && ${ARCH} == i386 && ${OSVERSION} < 700000
# Build fails on FreeBSD-6.3 i386 with optimized cflags with gcc 3.4
USE_GCC=	4.2+
.endif

post-patch:
	# This is possibly wrong, but benchmark does not affect library functionality, so
	@${REINPLACE_CMD} -e 's|CLOCK_PROCESS_CPUTIME_ID|CLOCK_PROF|g' \
		${WRKSRC}/src/benchmark.c
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e \
	's|-O3 -funroll-all-loops -fomit-frame-pointer -ffast-math||g' \
		${WRKSRC}/configure
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
