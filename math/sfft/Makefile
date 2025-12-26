PORTNAME=	sfft
DISTVERSION=	0.1.0
PORTREVISION=	15
CATEGORIES=	math
MASTER_SITES=	http://spiral.net/software/sfft/ LOCAL/bf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optimized Sparse Fast Fourier Transform
WWW=		https://spiral.net/software/sfft.html

LICENSE=	GPLv2

ONLY_FOR_ARCHS=		aarch64 amd64 armv7 i386
ONLY_FOR_ARCHS_REASON=	requires SSE instructions, which are x86-specific

BROKEN_armv7=	/usr/local/bin/ld: error: unsupported option: -z relro

BUILD_DEPENDS_aarch64=	${LOCALBASE}/include/sse2neon.h:devel/sse2neon
BUILD_DEPENDS_armv7=	${BUILD_DEPENDS_aarch64}
BUILD_DEPENDS+=	${BUILD_DEPENDS_${ARCH}}

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		localbase:ldflags uidfix zip
USE_GCC=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS PROFILE DOCS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
CFLAGS_armv7=	-mfpu=neon
CFLAGS_i386=	-msse2
CFLAGS+=	-fopenmp -Iflopcount
CXXFLAGS+=	${CFLAGS_${ARCH}} -fopenmp -Iflopcount
HEADERS=	sfft.h
HDIR=		include/sfft
MAKE_ENV=	LDADD="-lfftw3 ${LIBM}" LIB=sfft SHLIB_MAJOR="${SHLIB_MAJOR}" \
		SRCCONF=/dev/null SRCS="${SRCS}"

PLIST_FILES=	${HEADERS:S|^|${HDIR}/|} lib/libsfft.a lib/libsfft.so \
		lib/libsfft.so.${SHLIB_MAJOR}

SHLIB_MAJOR=	1
SRCS=	common.cc computefourier-1.0-2.0.cc \
	computefourier-3.0.cc fftw.cc filters.cc parameters.cc \
	sfft.cc simulation.cc timer.cc utils.cc

.include <bsd.port.options.mk>

LIBM=	-lm

.if ${PORT_OPTIONS:MDOCS} || make(makesum)
DISTFILES+=	sfft-doc.pdf
PORTDOCS=	sfft-doc.pdf
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math
.endif

.if ${PORT_OPTIONS:MPROFILE}
.if defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE)
IGNORE=		you have defined WITH_PROFILE, but have also defined\
WITHOUT_PROFILE, NOPROFILE, or NO_PROFILE
.elif !exists(/usr/lib/libc_p.a)
IGNORE=		you have chosen WITH_PROFILE, but have not installed the\
base system profiling libraries
.endif
PLIST_FILES+=	lib/libsfft_p.a
.else
MAKE_ENV+=	WITHOUT_PROFILE=yes
.endif

post-extract:
	@${PRINTF} "LIBDIR=\t${PREFIX}/lib\n.include <bsd.lib.mk>\n" > \
		${BUILD_WRKSRC}/Makefile

CORELIMIT?=	/usr/bin/limits -Sc 0

do-test:
	cd ${BUILD_WRKSRC} && ${CXX} ${CXXFLAGS} -o sfft-verification verification.cc \
		${LDFLAGS} libsfft.a -lfftw3 ${LIBM}
.for v in 1 2 3
. for k in 5 10 50
	@${ECHO_CMD} "Checking sfft version $v with $k frequency components:"
	cd ${BUILD_WRKSRC} && ${CORELIMIT} ./sfft-verification -k $k -r 3 -v $v || ${TRUE}
. endfor
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${HDIR}
	@cd ${BUILD_WRKSRC}; ${INSTALL_DATA} ${HEADERS} ${STAGEDIR}${PREFIX}/${HDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
