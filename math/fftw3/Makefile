# Created by: Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
# $FreeBSD$
#    $MCom: ports-experimental/math/fftw3/Makefile,v 1.1 2006/03/28 00:08:57 ahze Exp $

PORTNAME=	fftw3
PORTVERSION=	3.3.3
PORTREVISION?=	2
CATEGORIES=	math
MASTER_SITES=	http://www.fftw.org/ \
		ftp://ftp.fftw.org/pub/fftw/
PKGNAMESUFFIX=	${FFTW3_PKGNAMESUFFIX}
DISTNAME=	fftw-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Fast C routines to compute the Discrete Fourier Transform

LICENSE=	GPLv2

#current flavors: default, float, long, and quad
FFTW3_FLAVOR?=	default
FFTW3_SUFX=

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pathfix perl5 pkgconfig
USE_PERL5=	build
USE_LDCONFIG=	yes

CONFIGURE_ARGS=		--enable-shared --enable-threads --disable-fortran

.if ${FFTW3_FLAVOR} == "default"
INFO=	fftw3
.else
#For non-default flavors, build and install the flavor-dependent components
#only, so that these flavors may coexist with the default flavor
INSTALL_TARGET=	install-pkgconfigDATA install-libLTLIBRARIES install-exec
.endif

OPTIONS_DEFINE=		G77_WRAPPERS OPENMP OPTIMIZED_CFLAGS

G77_WRAPPERS_DESC=	Alter Fortran wrappers for use with g77
OPENMP_DESC=		Build OpenMP multithreaded libraries

OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENMP}
CONFIGURE_ARGS+=	--enable-openmp
PLIST_SUB+=	OPENMP=""
USES+=		compiler:openmp
.else
CONFIGURE_ARGS+=	--disable-openmp
PLIST_SUB+=	OPENMP="@comment "
USES+=		compiler:env
.endif

#Users must add altivec to MACHINE_CPU when desired:
#this is not currently done in bsd.cpu.mk
.if ${FFTW3_FLAVOR} == "default"
.  if !empty(MACHINE_CPU:Mavx)
CONFIGURE_ARGS+=--enable-avx
.  elif !empty(MACHINE_CPU:Msse2)
CONFIGURE_ARGS+=--enable-sse2
.  endif
.elif ${FFTW3_FLAVOR} == "float"
FFTW3_SUFX=	f
FFTW3_PKGNAMESUFFIX=	-float
CONFIGURE_ARGS+=--enable-float
.  if !empty(MACHINE_CPU:Mavx)
CONFIGURE_ARGS+=--enable-avx
.  elif !empty(MACHINE_CPU:Msse)
CONFIGURE_ARGS+=--enable-sse
.  elif !empty(ARCH:Mpowerpc*) && !empty(MACHINE_CPU:Maltivec)
CONFIGURE_ARGS+=--enable-altivec
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
.  if ${ARCH} == "i386" && (${COMPILER_TYPE} == "gcc" || !empty(USE_GCC))
CFLAGS+=	-malign-double
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
	@${FIND} ${WRKSRC} -type f \( -name \*.bak -or -name \*.orig \) -delete

post-configure:
#After issuing --disable-fortran in order to avoid using a Fortran compiler
#during configuration, edit config.h to provide Fortran wrappers appropriate for
#gfortran, with ac_cv_f77_mangling="lower case, underscore, no extra underscore"
	@${REINPLACE_CMD} -e '/DISABLE_FORTRAN/d' ${WRKSRC}/config.h
	@${ECHO_CMD} "#define F77_FUNC(name,NAME) name ## _" >> ${WRKSRC}/config.h
	@${ECHO_CMD} "#define F77_FUNC_(name,NAME) name ## _" >> ${WRKSRC}/config.h
	@${ECHO_CMD} "#define F77_FUNC_EQUIV 1" >> ${WRKSRC}/config.h
.if ${PORT_OPTIONS:MG77_WRAPPERS}
	@${ECHO_CMD} "#define WITH_G77_WRAPPERS 1" >> ${WRKSRC}/config.h
.endif

.if ${FFTW3_FLAVOR} != "default"
post-install:
	@${INSTALL_MAN} ${WRKSRC}/tools/fftw${FFTW3_SUFX}-wisdom.1 ${STAGEDIR}${PREFIX}/man/man1
.endif

regression-test test: smallcheck

.for t in bigcheck check exhaustive-check paranoid-check smallcheck
${t}: build
	@(cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_ARGS} ${t})
.endfor

.include <bsd.port.post.mk>
