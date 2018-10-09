# $FreeBSD$

PORTNAME=	primme
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Iterative eigensolver for symmetric and hermitian matrices

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack
TEST_DEPENDS=	gfortran${GCC_DEFAULT}:lang/gcc${GCC_DEFAULT}

USES=		gmake localbase:ldflags
USE_GITHUB=	yes
MAKEFILE=	makefile
ALL_TARGET=	solib
USE_LDCONFIG=	yes

BINARY_ALIAS=	make=${GMAKE}

CFLAGS+=	-fPIC
LDFLAGS+=	${LOCALBASE}/lib/liblapack.so ${LOCALBASE}/lib/libblas.so

TEST_ENV=	${MAKE_ENV} F77=gfortran${GCC_DEFAULT} FLDR=gfortran${GCC_DEFAULT} \
		LDFLAGS="-lm -Wl,-rpath=${LOCALBASE}/lib/gcc${GCC_DEFAULT} ${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so" \
		USE_MPI=no USE_PETSC=no PETSC_DIR=${LOCALBASE}
TEST_TARGET=	all_tests test

PLIST_FILES=	include/primme.h \
		include/primme_eigs.h \
		include/primme_eigs_f77.h \
		include/primme_f77.h \
		include/primme_svds.h \
		include/primme_svds_f77.h \
		lib/libprimme.so

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} include ${STAGEDIR}${PREFIX}
	${INSTALL_LIB} ${WRKSRC}/lib/lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
