# $FreeBSD$

PORTNAME=	elemental
DISTVERSIONPREFIX=	v
DISTVERSION=	0.87.7
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dense and sparse linear algebra, conic optimization, lattice reduction

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmetis.so:math/metis \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libmpi_cxx.so:net/openmpi \
		libopenblas.so:math/openblas \
		libqd.so:math/qd

USES=		cmake compiler:c++11-lang fortran
USE_GITHUB=	yes
GH_PROJECT=	Elemental
USE_LDCONFIG=	yes

CMAKE_ON=	EL_DISABLE_PARMETIS
CMAKE_ARGS=	-DGFORTRAN_LIB:STRING=${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgfortran.so \
		-DFREEBSD_GCC_LIB:STRING=${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so

DOCSDIR=	${PREFIX}/share/doc/Elemental

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${MV} CMake lib/cmake && \
		${RM} -r ${STAGEDIR}${PREFIX}/python && \
		${RM} -r ${STAGEDIR}${PREFIX}/conf

.include <bsd.port.mk>
