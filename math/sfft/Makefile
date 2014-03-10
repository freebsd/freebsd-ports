# Created by: bf@FreeBSD.org
# $FreeBSD$

PORTNAME=	sfft
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://spiral.net/software/sfft/ LOCAL/bf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Optimized Sparse Fast Fourier Transform

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3

USES=		zip
USE_GCC=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS PROFILE
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
CFLAGS+=	-fopenmp -msse2 -Iflopcount -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
HEADERS=	sfft.h
HDIR=		include/sfft
MAKE_ENV=	LDADD="-lfftw3 ${LIBM}" LIB=sfft SHLIB_MAJOR="${SHLIB_MAJOR}" \
		SRCCONF=/dev/null SRCS="${SRCS}"

PLIST_DIRS=	${HDIR}
PLIST_FILES=	${HEADERS:S|^|${HDIR}/|} lib/libsfft.a lib/libsfft.so \
		lib/libsfft.so.${SHLIB_MAJOR}

SHLIB_MAJOR=	1
SRCS=	common.cc computefourier-1.0-2.0.cc \
	computefourier-3.0.cc fftw.cc filters.cc parameters.cc \
	sfft.cc simulation.cc timer.cc utils.cc

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if !${ARCH:Mamd64} && !${MACHINE_CPU:Msse2}
IGNORE=	this port requires SSE2, and benefits from SSE3 -- set CPUTYPE\
appropriately
.endif

LIBM=	-lm
.if ${OSVERSION} < 1000034
LIB_DEPENDS+=	libmissing.so:${PORTSDIR}/math/libmissing
LIBM+=		-lmissing
.endif

.if ${PORT_OPTIONS:MDOCS} || make(makesum)
DISTFILES+=	sfft-doc.pdf
PORTDOCS=	sfft-doc.pdf
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math
.endif

.if ${PORT_OPTIONS:MPROFILE}
.if defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE)
IGNORE =	you have defined WITH_PROFILE, but have also defined\
WITHOUT_PROFILE, NOPROFILE, or NO_PROFILE
.elif !exists(/usr/lib/libc_p.a)
IGNORE  =	you have chosen WITH_PROFILE, but have not installed the\
base system profiling libraries
.endif
PLIST_FILES+=	lib/libsfft_p.a
.else
MAKE_ENV+=	NO_PROFILE=yes
.endif

post-extract:
	@${CP} /usr/include/complex.h ${BUILD_WRKSRC}/sfftcomplex.h
	@${PRINTF} "LIBDIR=\t${PREFIX}/lib\n.include <bsd.lib.mk>\n" > \
		${BUILD_WRKSRC}/Makefile

post-patch:
	@${REINPLACE_CMD} -e 's/string\.h/cstring/' \
		${WRKSRC}/src/utils.cc
.if ${OSVERSION} < 1000034
	@${REINPLACE_CMD} -e '\|<complex.h>|{x; \
	s|^.*$$|#include "missing_complex.h"|; H; x;}' \
		${WRKSRC}/src/fft.h
.endif
	@${REINPLACE_CMD} -E -e '/<complex\.h>/ \
	{s/<complex\.h>/ "sfftcomplex.h"/; x ; \
	s|^.*$$|#endif|; G; x; \
	s|^.*$$|extern "C" {|; G; x; \
	s|^.*$$|#ifdef __cplusplus|; G; x; \
	s|^.*$$|#ifdef __cplusplus|; H; \
	s|^.*$$|}|; H; \
	s|^.*$$|#endif|; H; x;}' \
		${WRKSRC}/src/computefourier-1.0-2.0.h \
		${WRKSRC}/src/computefourier-3.0.h \
		${WRKSRC}/src/fft.h

CORELIMIT?=	/usr/bin/limits -Sc 0

check regression-test test: build
	@cd ${BUILD_WRKSRC}; \
	${CXX} ${CXXFLAGS} -o sfft-verification verification.cc \
	${LDFLAGS} libsfft.a -lfftw3 ${LIBM} ; \
	for _v in 1 2 3 ; do \
	for _k in 5 10 50; do \
	echo "Checking sfft version $${_v} with $${_k} frequency components:"; \
	${CORELIMIT} ./sfft-verification -k $${_k} -r 3 -v $${_v} || ${TRUE} ; \
	done ; done

post-install:
	@${MKDIR} ${PREFIX}/${HDIR}
	@cd ${BUILD_WRKSRC}; ${INSTALL_DATA} ${HEADERS} ${PREFIX}/${HDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${_DISTDIR}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
