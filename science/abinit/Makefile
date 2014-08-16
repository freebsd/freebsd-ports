# Created by: NAKATA Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abinit
PORTVERSION=	5.7.3
PORTREVISION=	15
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.abinit.org/pub/abinitio/ABINIT_v${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abinit calculates electronic structure of systems

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PYTHON_SITELIBDIR}/numarray/__init__.py:${PORTSDIR}/math/py-numarray
LIB_DEPENDS=	libnetcdff.so:${PORTSDIR}/science/netcdf-fortran \
		libgsl.so:${PORTSDIR}/math/gsl

USES=		fortran gmake perl5
USE_PYTHON=	yes
USE_PERL5=	build
USE_AUTOTOOLS=	autoconf automake
CONFIGURE_ENV=	WGET=${TRUE}
CONFIGURE_ARGS=	--disable-wannier90 --disable-bigdft --disable-etsf-io	\
		--with-plugins-tardir=/dev/null				\
		--with-netcdf-includes="-I${LOCALBASE}/include"		\
		--enable-bindings --enable-gsl				\
		--with-netcdf-libs="-L${LOCALBASE}/lib -lnetcdff -lnetcdf"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	latex:build dvipsk:build
BUILD_DEPENDS+= gm4:${PORTSDIR}/devel/m4		\
		markdown:${PORTSDIR}/textproc/markdown
USE_GHOSTSCRIPT_BUILD=	yes
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
MANUAL_PACKAGE_BUILD=	takes a tremendous amount of time to build on pointyhat nodes
.endif

.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
BLAS=		-lf77blas
LAPACK=		-lalapack -lcblas
.else
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas
LIB_DEPENDS+=	liblapack.so:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

pre-configure:
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/^abinit_top_subdirs =/s| doc||' ${WRKSRC}/config/specs/other.cf
.endif
.if ! ${PORT_OPTIONS:MEXAMPLES}
	${REINPLACE_CMD} -e '/^abinit_top_subdirs =/s| tests||' ${WRKSRC}/config/specs/other.cf
.endif
	(cd ${WRKSRC} && ./config/scripts/makemake)
	${CHMOD} a+x ${WRKSRC}/bindings/parser/*.py

post-build:
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} libabinit)

post-install:
	${MKDIR} ${PREFIX}/include ${PREFIX}/lib
.for lf in libabinip.a libabinis.a
	${INSTALL_DATA} ${WRKSRC}/${lf} ${PREFIX}/lib
.endfor
.for lf in ab_dtset_c.h dtset_c.h dtset_c.static.h dtset_f90.inc dtset_py.h	\
	ab_dtset_f90_get.f90
	${INSTALL_DATA} ${WRKSRC}/bindings/parser/${lf} ${PREFIX}/include
.endfor

regression-test:
	cd ${WRKSRC}/tests ; ${MAKE_CMD} tests_min

.include <bsd.port.mk>
