# New ports collection makefile for: fftw
# Date created:		Dec 28 1998
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	fftw3
PORTVERSION=	3.0.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/ 		\
		ftp://ftp.fftw.org/pub/fftw/old/ 	\
		ftp://theory.lcs.mit.edu/pub/fftw/	\
		ftp://pm.cse.rmit.edu.au/pub/dsp/fftw/
DISTNAME=	fftw-${PORTVERSION}

MAINTAINER=	ahze@ahze.net
COMMENT=	Fast C routines to compute the Discrete Fourier Transform

USE_GMAKE=	yes
USE_LIBTOOL_VER=13
USE_GNOME=	gnomehack gnomeprefix gnometarget lthack pkgconfig
INSTALLS_SHLIB=	yes

MAN1=	fftw-wisdom-to-conf.1 fftw-wisdom.1
INFO=	fftw3

CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"

OPTIONS=	OPTIMIZED_CFLAGS "Enable optimized CFLAGS" off \
		OPTIMIZED_ATHLON "Enable AMD K7(Athlon) optimizations" off \
		SMP_THREADS "Enable FFTW SMP threads library" off

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_CFLAGS) && !defined(WITH_OPTIMIZED_ATHLON)
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -O2 -ffast-math -fomit-frame-pointer"
.endif

.if defined(WITH_OPTIMIZED_ATHLON)
CONFIGURE_ARGS+=--enable-k7
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -O3 -fomit-frame-pointer -fno-schedule-insns \
		-malign-double -fstrict-aliasing -mpreferred-stack-boundary=4 \
		-ffast-math"
.endif

.if defined(WITH_SMP_THREADS)
CONFIGURE_ARGS+=--enable-threads
.endif

.include <bsd.port.post.mk>
