# Created by: bf@FreeBSD.org
# $FreeBSD$

PORTNAME=	libflame
DISTVERSION=	5.2.0
CATEGORIES=	math

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	FLAME dense linear algebra library

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	amd64 i386 powerpc64 powerpc
ONLY_FOR_ARCHS_REASON=	make system does not support other architectures yet

BUILD_DEPENDS=	bash:shells/bash

GNU_CONFIGURE=	yes
USES=		compiler:c11 gmake python:3.7
USE_CSTD=	c99
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	flame

OPTIONS_RADIO=	PARALLELIZATION
OPTIONS_RADIO_PARALLELIZATION=	NONE THREADS OPENMP
OPTIONS_DEFAULT=	THREADS
NONE_DESC=		serial libflame
THREADS_DESC=		pthread based parallelization
OPENMP_DESC=		OpenMP based parallelization

# enable dynamic build always
CONFIGURE_ARGS=		--enable-dynamic-build
# our shell is also prone to the argument list too long bug
CONFIGURE_ARGS+=	--enable-max-arg-list-hack
# use libflame as a LAPACK
CONFIGURE_ARGS+=	--enable-lapack2flame
# add our CFLAGS to theirs
CONFIGURE_ARGS+=	--with-extra-cflags="${CFLAGS}"
# enable supermatrix
CONFIGURE_ARGS+=	--enable-supermatrix
# disable ldim alignment (we cannot assume input to be aligned)
CONFIGURE_ARGS+=	--disable-ldim-alignment

.for b in M K N
.if defined(${b}_BLOCKSIZE)
CONFIGURE_ARGS+=	--enable-default-${b:tl}-blocksize=${${b}_BLOCKSIZE}
.endif
.endfor

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MOPENMP}
.if ${CHOSEN_COMPILER_TYPE} == clang
IGNORE=		clang does not support OPENMP, use THREADS instead
.endif
OPENMP_CFLAGS ?=	-fopenmp
CFLAGS+=		${OPENMP_CFLAGS}
LDFLAGS+=		${OPENMP_CFLAGS}
CONFIGURE_ARGS+=	--enable-multithreading=openmp
.elif ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-multithreading=pthreads
.elif ${PORT_OPTIONS:MNONE}
CONFIGURE_ARGS+=	--enable-multithreading=no
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200060
IGNORE=			requires a newer linker such as lld
.endif

.if !(defined(USE_GCC) || !empty(CC:M*gcc4*))
CONFIGURE_ARGS+=	--disable-autodetect-f77-ldflags \
			--disable-autodetect-f77-name-mangling
.endif

#post-install:
#	@${MKDIR} ${STAGEDIR}${PREFIX}/include/libflame
#	${INSTALL_DATA} ${WRKSRC}/include_local/* ${STAGEDIR}/${PREFIX}/include/libflame/

.include <bsd.port.mk>
