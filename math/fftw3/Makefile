# Created by: Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
# $FreeBSD$

PORTNAME=	fftw3
DISTVERSION=	3.3.6-pl2
PORTREVISION?=	2
CATEGORIES=	math
MASTER_SITES=	http://www.fftw.org/ \
		ftp://ftp.fftw.org/pub/fftw/
PKGNAMESUFFIX=	${FFTW3_PKGNAMESUFFIX}
DISTNAME=	fftw-${DISTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT?=	Fast C routines to compute the Discrete Fourier Transform

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

#current flavors: default, float, long, and quad
FFTW3_FLAVOR?=	default
FFTW3_SUFX=

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	smallcheck #bigcheck check exhaustive-check paranoid-check
TEST_WRKSRC=	${WRKSRC}/tests
USES=		gmake libtool makeinfo pathfix perl5 pkgconfig
USE_PERL5=	build
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-shared --enable-threads --disable-fortran
MPIDIR?=	${LOCALBASE}/mpi/openmpi

.if ${FFTW3_FLAVOR} == "default"
INFO=	fftw3
.else
#For non-default flavors, build and install the flavor-dependent components
#only, so that these flavors may coexist with the default flavor
INSTALL_TARGET=	install-pkgconfigDATA install-libLTLIBRARIES install-exec
.endif

OPTIONS_DEFINE=		G77_WRAPPERS OPENMP OPENMPI OPTIMIZED_CFLAGS SIMD
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS SIMD
.if ${FFTW3_FLAVOR} == "quad"
OPTIONS_EXCLUDE+=	OPENMPI
.endif
OPTIONS_SUB=		yes

G77_WRAPPERS_DESC=		Alter Fortran wrappers for use with g77

OPENMP_DESC=			Build OpenMP multithreaded libraries
OPENMP_USES=			compiler:openmp
OPENMP_USES_OFF=		compiler:env
OPENMP_CONFIGURE_ENABLE=	openmp
OPENMP_EXTRA_PATCHES=		${FILESDIR}/extrapatch-tests_fftw-bench.c

OPENMPI_DESC=			Build OpenMPI parallel libraries
OPENMPI_LIB_DEPENDS=		libmpi.so:net/openmpi
OPENMPI_CONFIGURE_ENABLE=	mpi
OPENMPI_CONFIGURE_ENV=		MPICC=${MPIDIR}/bin/mpicc \
				MPIRUN=${MPIDIR}/bin/mpirun

.include <bsd.port.options.mk>

#Users must add altivec to MACHINE_CPU when desired:
#this is not currently done in bsd.cpu.mk
.if ${FFTW3_FLAVOR} == "default"
.  if ${PORT_OPTIONS:MSIMD}
.    if !empty(MACHINE_CPU:Mavx)
CONFIGURE_ARGS+=--enable-avx
.    endif
.    if !empty(MACHINE_CPU:Mavx2)
CONFIGURE_ARGS+=--enable-avx2 --enable-fma
.    endif
.    if !empty(MACHINE_CPU:Msse2)
CONFIGURE_ARGS+=--enable-sse2
.    endif
.  endif
.elif ${FFTW3_FLAVOR} == "float"
FFTW3_SUFX=	f
FFTW3_PKGNAMESUFFIX=	-float
CONFIGURE_ARGS+=--enable-float
.  if ${PORT_OPTIONS:MSIMD}
.    if !empty(MACHINE_CPU:Mavx)
CONFIGURE_ARGS+=--enable-avx
.    endif
.    if !empty(MACHINE_CPU:Mavx2)
CONFIGURE_ARGS+=--enable-avx2 --enable-fma
.    endif
.    if !empty(MACHINE_CPU:Msse)
CONFIGURE_ARGS+=--enable-sse2
.    endif
.    if !empty(ARCH:Mpowerpc*) && !empty(MACHINE_CPU:Maltivec)
CONFIGURE_ARGS+=--enable-altivec
.    endif
.  endif
.elif ${FFTW3_FLAVOR} == "long"
FFTW3_SUFX=	l
FFTW3_PKGNAMESUFFIX=	-long
CONFIGURE_ARGS+=--enable-long-double
.elif ${FFTW3_FLAVOR} == "quad"
FFTW3_SUFX=	q
FFTW3_PKGNAMESUFFIX=	-quad
CONFIGURE_ARGS+=--enable-quad-precision
ONLY_FOR_ARCHS=		i386 amd64
USE_GCC=	yes
.endif

.if ${FFTW3_FLAVOR} == "default"
PLIST_SUB+=	DEF="" NONDEF="@comment "
.else
PLIST_SUB+=	DEF="@comment " NONDEF=""
.endif

PLIST_SUB+=	FFTW3_SUFX="${FFTW3_SUFX}"

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math -fstrict-aliasing
.  if !defined(WITH_DEBUG)
CFLAGS+=	-fomit-frame-pointer
.  endif
.  if ${ARCH} == "i386" && (${COMPILER_TYPE} == "gcc" || !empty(USE_GCC)) && !${PORT_OPTIONS:MOPENMPI}
CFLAGS+=	-malign-double
.  endif
.  if ${ARCH} == "armv6" && ${OPSYS} == FreeBSD && ${OSVERSION} < 1200032
CFLAGS+=	-fno-unsafe-math-optimizations
.  endif
WITHOUT_NO_STRICT_ALIASING=	yes
.endif # end OPTIMIZED_CFLAGS

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/fftw|${PREFIX}/etc/fftw|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/api/import-system-wisdom.c \
		${WRKSRC}/doc/fftw3* \
		${WRKSRC}/tools/*
.if ${FFTW3_FLAVOR} != "default"
	@${REINPLACE_CMD} -E \
	-e '/(DIST_COMMON|bin_SCRIPTS|BUILT_SOURCES|EXTRA_DIST) =/,\
	/[^\]$$/s/[^[:blank:]]*fftw-wisdom-to-conf[^[:blank:]]*//' \
		${WRKSRC}/tools/Makefile.in
.endif

post-configure:
#After issuing --disable-fortran in order to avoid using a Fortran compiler
#during configuration, edit config.h to provide Fortran wrappers appropriate for
#gfortran, with ac_cv_f77_mangling="lower case, underscore, no extra underscore"
	@${REINPLACE_CMD} -e '/DISABLE_FORTRAN/d' ${WRKSRC}/config.h
	@${ECHO_CMD} "#define F77_FUNC(name,NAME) name ## _" >> ${WRKSRC}/config.h
	@${ECHO_CMD} "#define F77_FUNC_(name,NAME) name ## _" >> ${WRKSRC}/config.h
	@${ECHO_CMD} "#define F77_FUNC_EQUIV 1" >> ${WRKSRC}/config.h

post-configure-G77_WRAPPERS-on:
	@${ECHO_CMD} "#define WITH_G77_WRAPPERS 1" >> ${WRKSRC}/config.h

.if ${FFTW3_FLAVOR} != "default"
post-install:
	${INSTALL_MAN} ${WRKSRC}/tools/fftw${FFTW3_SUFX}-wisdom.1 ${STAGEDIR}${PREFIX}/man/man1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so
.endif

.include <bsd.port.post.mk>
