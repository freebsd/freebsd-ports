# New ports collection makefile for:	abinit
# Date Created:				18 March 2004
# Whom:					NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abinit
PORTVERSION=	5.6.5
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.abinit.org/pub/abinitio/ABINIT_v${PORTVERSION}/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Abinit calculates electronic structure of systems

LIB_DEPENDS=	netcdff.4:${PORTSDIR}/science/netcdf-ftn

USE_FORTRAN=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WGET=${TRUE}
CONFIGURE_ARGS=	--disable-wannier90 --disable-bigdft --disable-etsf-io	\
		--with-plugins-tardir=/dev/null				\
		--with-netcdf-includes="-I${LOCALBASE}/include"		\
		--with-netcdf-libs="-L${LOCALBASE}/lib -lnetcdff -lnetcdf"
ALL_TARGET=	all libabinit

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX-base	\
		dvips:${PORTSDIR}/print/dvipsk-tetex	\
		markdown:${PORTSDIR}/textproc/markdown
USE_GHOSTSCRIPT_BUILD=	yes
.endif

.include <bsd.port.pre.mk>

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
	${REINPLACE_CMD} -e '/^SUBDIRS =/s| doc||' ${WRKSRC}/Makefile.in
.endif
.if defined(NOPORTEXAMPLES)
	${REINPLACE_CMD} -e '/^SUBDIRS =/s| tests||' ${WRKSRC}/Makefile.in
.endif

post-install:
	${MKDIR} ${PREFIX}/lib
.for lf in libabinip.a libabinis.a
	${INSTALL_DATA} ${WRKSRC}/${lf} ${PREFIX}/lib
.endfor

regression-test:
	cd ${WRKSRC}/tests ; ${GMAKE} tests_min

.include <bsd.port.post.mk>
