PORTNAME=	fftw3
DISTVERSION=	3.3.11
CATEGORIES=	math
MASTER_SITES=	https://www.fftw.org/
PKGNAMESUFFIX=	${FFTW3_PKGNAMESUFFIX}
DISTNAME=	fftw-${DISTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT?=	Fast C routines to compute the Discrete Fourier Transform
WWW=		https://www.fftw.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

# Current flavors: default, float, long, and quad
# These are not FreeBSD Ports 'FLAVORS'; "flavor" is the term that
# upstream uses to differentiate library precision. The default is the
# double precision library.
FFTW3_FLAVOR?=	default
FFTW3_SUFX=

.if !make(maintainer-update*)
USES=		gmake libtool makeinfo perl5
.else
USES=		cmake
.endif
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-threads --disable-fortran
.if ${FFTW3_FLAVOR} == "default"
INSTALL_TARGET=	install-strip
.else
# For non-default flavors, install only the flavor-dependent components
# so that these flavors may coexist with the default flavor.
INSTALL_TARGET=	install-cmakeDATA install-pkgconfigDATA install-libLTLIBRARIES install-exec
.endif
# The standard 'check' target takes about 3 minutes to complete on 2026
# amd64 consumer hardware whereas 'smallcheck' completes in about a second.
# If 'smallcheck' fails, there is something very wrong.
TEST_TARGET=	smallcheck #bigcheck check exhaustive-check paranoid-check

SUB_FILES=	FFTW3LibraryDepends.cmake
SUB_LIST=	FFTW3_SUFX=${FFTW3_SUFX} \
		SHLIB_VER=${SHLIB_VER} \
		SHLIB_VER_MAJ=${SHLIB_VER_MAJ}

TEST_WRKSRC=	${WRKSRC}/tests

.if ${FFTW3_FLAVOR} == "default"
INFO=		fftw3
.endif
PLIST_SUB=	SHLIB_VER=${SHLIB_VER} \
		SHLIB_VER_MAJ=${SHLIB_VER_MAJ}

OPTIONS_DEFINE=		G77_WRAPPERS OPENMP OPENMPI OPTIMIZED_CFLAGS SIMD
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS SIMD
.for arch in aarch64 amd64 i386 powerpc64 powerpc64le riscv64
OPTIONS_DEFAULT_${arch}=OPENMP
.endfor
.if ${FFTW3_FLAVOR} == "quad"
OPTIONS_EXCLUDE+=	OPENMPI
.endif
OPTIONS_SUB=		yes

G77_WRAPPERS_DESC=		Alter Fortran wrappers for use with g77

OPENMP_DESC=			Build OpenMP multi-threaded libraries
OPENMP_USES=			compiler:env
OPENMP_USES_OFF=		compiler:env
OPENMP_CONFIGURE_ENABLE=	openmp

OPENMPI_DESC=			Build OpenMPI parallel libraries
OPENMPI_USES=			mpi:openmpi
OPENMPI_CONFIGURE_ENABLE=	mpi
OPENMPI_CONFIGURE_ENV=		MPICC=${MPICC} \
				MPIRUN=${MPIRUN}

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -fstrict-aliasing
.if !defined(WITH_DEBUG)
OPTIMIZED_CFLAGS_CFLAGS+=	-fomit-frame-pointer
.endif
OPTIMIZED_CFLAGS_VARS=		WITHOUT_NO_STRICT_ALIASING=yes

SHLIB_VER_MAJ=	${DISTVERSION:R:R}
SHLIB_VER_MIN=	7
SHLIB_VER_PAT=	${DISTVERSION:E}
SHLIB_VER=	${SHLIB_VER_MAJ}.${SHLIB_VER_MIN}.${SHLIB_VER_PAT}

.include <bsd.port.options.mk>

# Enable cycle counter via the CNTVCT_EL0 register for all variants on arm64.
.if ${ARCH} == "aarch64"
CONFIGURE_ARGS+=	--enable-armv8-cntvct-el0
.endif

.if ${FFTW3_FLAVOR} == "default"
.  if ${PORT_OPTIONS:MSIMD}
.    if !empty(MACHINE_CPU:Mavx)
CONFIGURE_ARGS+=	--enable-avx
.    endif
.    if !empty(MACHINE_CPU:Mavx2)
CONFIGURE_ARGS+=	--enable-avx2 --enable-fma
.    endif
.    if !empty(MACHINE_CPU:Msse2)
CONFIGURE_ARGS+=	--enable-sse2
.    endif
.  endif
.elif ${FFTW3_FLAVOR} == "float"
FFTW3_SUFX=		f
FFTW3_PKGNAMESUFFIX=	-float
CONFIGURE_ARGS+=	--enable-float
.  if ${PORT_OPTIONS:MSIMD}
.    if !empty(MACHINE_CPU:Mavx)
CONFIGURE_ARGS+=	--enable-avx
.    endif
.    if !empty(MACHINE_CPU:Mavx2)
CONFIGURE_ARGS+=	--enable-avx2 --enable-fma
.    endif
.    if !empty(MACHINE_CPU:Msse)
CONFIGURE_ARGS+=	--enable-sse2
.    endif
.    if !empty(MACHINE_CPU:Maltivec)
CONFIGURE_ARGS+=	--enable-altivec
.    endif
.    if !empty(MACHINE_CPU:Mvsx)
CONFIGURE_ARGS+=	--enable-vsx
.    endif
.    if ${ARCH} == "aarch64"
CONFIGURE_ARGS+=	--enable-neon
.    endif
.  endif
.elif ${FFTW3_FLAVOR} == "long"
FFTW3_SUFX=		l
FFTW3_PKGNAMESUFFIX=	-long
CONFIGURE_ARGS+=	--enable-long-double
.elif ${FFTW3_FLAVOR} == "quad"
FFTW3_SUFX=		q
FFTW3_PKGNAMESUFFIX=	-quad
CONFIGURE_ARGS+=	--enable-quad-precision
ONLY_FOR_ARCHS=		i386 amd64
USE_GCC=		yes
.endif

PLIST_SUB+=	FFTW3_SUFX="${FFTW3_SUFX}"
.if ${FFTW3_FLAVOR} == "default"
PLIST_SUB+=	DEF="" NONDEF="@comment "
.else
PLIST_SUB+=	DEF="@comment " NONDEF=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/fftw|${PREFIX}/etc/fftw|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/api/import-system-wisdom.c \
		${WRKSRC}/doc/fftw3* \
		${WRKSRC}/tools/*
	@${REINPLACE_CMD} -e '/^cmakedir/s|fftw3|fftw3@PREC_SUFFIX@|' \
		${WRKSRC}/Makefile.in
.if ${FFTW3_FLAVOR} != "default"
	@${REINPLACE_CMD} -E \
	-e '/(DIST_COMMON|bin_SCRIPTS|BUILT_SOURCES|EXTRA_DIST) =/, \
	/[^\]$$/s|[^[:blank:]]*fftw-wisdom-to-conf[^[:blank:]]*||' \
		${WRKSRC}/tools/Makefile.in
.endif

post-configure:
# After issuing --disable-fortran in order to avoid using a Fortran compiler
# during configuration, edit config.h to provide Fortran wrappers appropriate for
# gfortran, with ac_cv_f77_mangling="lower case, underscore, no extra underscore".
	@${REINPLACE_CMD} -e '/DISABLE_FORTRAN/d' ${WRKSRC}/config.h
	@${ECHO_CMD} "#define F77_FUNC(name,NAME) name ## _" >> ${WRKSRC}/config.h
	@${ECHO_CMD} "#define F77_FUNC_(name,NAME) name ## _" >> ${WRKSRC}/config.h
	@${ECHO_CMD} "#define F77_FUNC_EQUIV 1" >> ${WRKSRC}/config.h

post-configure-G77_WRAPPERS-on:
	@${ECHO_CMD} "#define WITH_G77_WRAPPERS 1" >> ${WRKSRC}/config.h

post-install:
	${INSTALL_DATA} ${WRKDIR}/FFTW3LibraryDepends.cmake ${STAGEDIR}${PREFIX}/lib/cmake/fftw3${FFTW3_SUFX}
.if ${FFTW3_FLAVOR} != "default"
	${INSTALL_MAN} ${WRKSRC}/tools/fftw${FFTW3_SUFX}-wisdom.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so
.endif

.if defined(MAINTAINER_MODE) && ${FFTW3_FLAVOR} == "default"
# FFTW3 uses an unconventional shared lib version naming scheme. This target
# updates SHLIB_VER_MIN, the only component that is unpredictable and must be
# determined from the source.
maintainer-update-SHLIB_VER_MIN: extract
	@AGE=$$(${SED} -n -e 's|^SHARED_VERSION_INFO="[^:]*:[^:]*:\([0-9]*\)".*|\1|p' ${WRKSRC}/configure.ac); \
	if [ -z "$${AGE}" ]; then \
		${ECHO_CMD} "Error: Could not extract AGE from ${WRKSRC}/configure.ac"; \
		exit 1; \
	elif [ "$${AGE}" = "${SHLIB_VER_MIN}" ]; then \
		${ECHO_CMD} "SHLIB_VER_MIN is already up to date ($${AGE}). Skipping."; \
	else \
		${ECHO_CMD} "Updating SHLIB_VER_MIN from ${SHLIB_VER_MIN} to $${AGE}..."; \
		${SED} -i '' -e "s|^\(SHLIB_VER_MIN=[[:space:]]*\)[0-9]*|\1$${AGE}|" ${.CURDIR}/Makefile; \
		${ECHO_CMD} "SHLIB_VER_MIN in ${.CURDIR}/Makefile updated successfully."; \
	fi

# FFTW3LibraryDepends.cmake is the target import file generated by CMake, but
# since we use autotools for completeness, we pre-grenerate a template that can
# be used by all of the FFTW3 flavors.
maintainer-update-cmake-depends: extract do-configure
	@${ECHO_CMD} "Generating FFTW3LibraryDepends.cmake.in..."
	@${MKDIR} ${FILESDIR}
	@${SED} \
		-e 's|fftw3|fftw3%%FFTW3_SUFX%%|g' \
		-e '/IMPORTED_LOCATION/ s|".*"|"%%PREFIX%%/lib/libfftw3%%FFTW3_SUFX%%.so.%%SHLIB_VER_MAJ%%"|' \
		-e '/IMPORTED_SONAME/ s|".*"|"libfftw3%%FFTW3_SUFX%%.so.%%SHLIB_VER%%"|' \
		${CONFIGURE_WRKSRC}/FFTW3LibraryDepends.cmake > ${FILESDIR}/FFTW3LibraryDepends.cmake.in
	@${ECHO_CMD} "Successfully updated ${FILESDIR}/FFTW3LibraryDepends.cmake.in."

# Consolidation of maintainer-update* targets. To be run with each PORTVERSION
# update and before testing.
maintainer-update: makesum maintainer-update-SHLIB_VER_MIN maintainer-update-cmake-depends clean
.endif

.include <bsd.port.mk>
