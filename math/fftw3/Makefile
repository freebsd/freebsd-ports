# New ports collection makefile for: fftw
# Date created:		Dec 28 1998
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	fftw3
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/ 		\
		http://www.fftw.org/ 			\
		ftp://theory.lcs.mit.edu/pub/fftw/	\
		ftp://pm.cse.rmit.edu.au/pub/dsp/fftw/
DISTNAME=	fftw-${PORTVERSION}

MAINTAINER=	ahze@ahze.net
COMMENT=	Fast C routines to compute the Discrete Fourier Transform

USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=15
USE_GNOME=	gnomehack gnomeprefix gnometarget lthack pkgconfig
USE_REINPLACE=	yes
USE_PERL5_BUILD=yes
INSTALLS_SHLIB=	yes

MAN1=	fftw-wisdom-to-conf.1 fftw-wisdom.1 fftwf-wisdom.1
INFO=	fftw3

CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
# FFTW --enable-single Options
CONFIGURE_ARGS_FFTW3F=--enable-single ${CONFIGURE_ARGS:N--enable-sse2}
FFTW3F_WRKSRC=	${WRKDIR}/${DISTNAME}-3F
FFTW3F_INSTALL_TARGET=install-pkgconfigDATA install-libLTLIBRARIES install-exec

OPTIONS=	OPTIMIZED_CFLAGS "Enable optimized CFLAGS" off \
		SMP_THREADS "Enable FFTW SMP threads library" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
OPTIONS+=	OPTIMIZED_ATHLON "Enable AMD K7(Athlon) optimizations" off \
		SSE "Enable SSE optimized routines" off

.endif

.if defined(WITH_OPTIMIZED_CFLAGS) && !defined(WITH_OPTIMIZED_ATHLON)
CONFIGURE_ENV+=	CFLAGS="${CFLAGS:N-O:N-O*} -O2 -ffast-math -fomit-frame-pointer"
.endif

.if defined(WITH_OPTIMIZED_ATHLON)
CONFIGURE_ARGS+=--enable-k7
CONFIGURE_ENV+=	CFLAGS="${CFLAGS:N-O:N-O*} -O3 -fomit-frame-pointer -fno-schedule-insns \
		-malign-double -fstrict-aliasing -mpreferred-stack-boundary=4 \
		-ffast-math"
.endif

.if defined(WITH_SSE)
.if ${OSVERSION} < 500000
USE_GCC=	3.3
.endif
CONFIGURE_ARGS+=--enable-sse2
CONFIGURE_ARGS_FFTW3F+=--enable-sse
CONFIGURE_ENV+=	CFLAGS="${CFLAGS:N-O:N-O*} -O2"
.endif

.if defined(WITH_SMP_THREADS)
CONFIGURE_ARGS+=--enable-threads
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/etc/fftw|${PREFIX}/etc/fftw|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/api/import-system-wisdom.c \
		${WRKSRC}/doc/fftw3* \
		${WRKSRC}/tools/fftw*wisdom.1
	@${FIND} ${WRKSRC} -name \*.bak -type f -exec ${RM} -f {} \;

pre-configure:
	@${CP} -Rf ${WRKSRC} ${FFTW3F_WRKSRC}
	@${REINPLACE_CMD} -e \
		's|EXTRA_DIST = fftw-wisdom-to-conf.in||; \
		s|fftw-wisdom-to-conf.in||; \
		s|fftw-wisdom-to-conf: $(top_builddir)/config.status||; \
		s|bin_SCRIPTS = fftw-wisdom-to-conf||' \
			${FFTW3F_WRKSRC}/tools/Makefile.in

post-configure:
	@${ECHO_MSG} "===>  Configuring for ${PORTNAME}-${PORTVERSION} (short)"
	@(cd ${FFTW3F_WRKSRC} && \
		${SETENV} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS_FFTW3F})

post-build:
	@${ECHO_MSG} "===>  Building for ${PORTNAME}-${PORTVERSION} (short)"
	@(cd ${FFTW3F_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
	@(cd ${FFTW3F_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${FFTW3F_INSTALL_TARGET})
	@${INSTALL_MAN} ${FFTW3F_WRKSRC}/tools/fftwf-wisdom.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
