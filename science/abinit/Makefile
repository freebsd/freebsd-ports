# New ports collection makefile for:	abinit
# Date Created:				18 March 2004
# Whom:					NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abinit
PORTVERSION=	5.7.3
PORTREVISION=	7
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.abinit.org/pub/abinitio/ABINIT_v${PORTVERSION}/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Abinit calculates electronic structure of systems

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numarray/__init__.py:${PORTSDIR}/math/py-numarray
LIB_DEPENDS=	netcdff.4:${PORTSDIR}/science/netcdf3-ftn	\
		gsl.15:${PORTSDIR}/math/gsl

USE_FORTRAN=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_PERL5_BUILD=yes
USE_AUTOTOOLS=	autoconf:262 automake:110
CONFIGURE_ENV=	WGET=${TRUE}
CONFIGURE_ARGS=	--disable-wannier90 --disable-bigdft --disable-etsf-io	\
		--with-plugins-tardir=/dev/null				\
		--with-netcdf-includes="-I${LOCALBASE}/include"		\
		--enable-bindings --enable-gsl				\
		--with-netcdf-libs="-L${LOCALBASE}/lib -lnetcdff -lnetcdf"
ALL_TARGET=	all libabinit

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX-base	\
		dvips:${PORTSDIR}/print/dvipsk-tetex	\
		gm4:${PORTSDIR}/devel/m4		\
		markdown:${PORTSDIR}/textproc/markdown
USE_GHOSTSCRIPT_BUILD=	yes
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
MANUAL_PACKAGE_BUILD=	takes a tremendous amount of time to build on pointyhat nodes
.endif

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
LAPACK=		-lalapack
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

pre-configure:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/^abinit_top_subdirs =/s| doc||' ${WRKSRC}/config/specs/other.cf
.endif
.if defined(NOPORTEXAMPLES)
	${REINPLACE_CMD} -e '/^abinit_top_subdirs =/s| tests||' ${WRKSRC}/config/specs/other.cf
.endif
	(cd ${WRKSRC} && ./config/scripts/makemake)
	${CHMOD} a+x ${WRKSRC}/bindings/parser/*.py

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
	cd ${WRKSRC}/tests ; ${GMAKE} tests_min

.include <bsd.port.post.mk>
