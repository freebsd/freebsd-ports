PORTNAME=	pastix
PORTVERSION=	6.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	PaStiX: a sparse direct solver

LICENSE=	LGPL3

BUILD_DEPENDS=	bash:shells/bash	\
		${PYNUMPY}
LIB_DEPENDS=	libcblas.so:math/cblas	\
		libmetis.so:math/metis	\
		libscotch.so:cad/scotch	\
		liblapacke.so:math/lapacke	\
		libhwloc.so:devel/hwloc2
RUN_DEPENDS=	bash:shells/bash	\
		${PYNUMPY}

USES=		cmake blaslapack:openblas fortran pkgconfig python

USE_GITLAB=	yes
GL_SITE=	https://gitlab.inria.fr/
GL_ACCOUNT=	solverstack
GL_PROJECT=	pastix spm:s morse_cmake:m
GL_COMMIT=	071d5ae165c744ec3e62f5bdd246b12f8fa90662	\
		ebbd88ff3808c50e04119d0b42faf055c6eada2a:s	\
		31cd2bbb0d76f2b9fd83011d8f079d97540b0ba8:m
GL_SUBDIR=	spm:s cmake_modules/morse_cmake:m

CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON	\
		-DPASTIX_ORDERING_METIS:BOOL=ON
USE_LDCONFIG=	yes
TEST_TARGET=	test

OPTIONS_DEFINE=	EXAMPLES
EX2FIX=		example spm/examples spm/wrappers/fortran90 spm/wrappers/python	\
		wrappers/fortran90 wrappers/python example/old

pre-configure:
.for ex in ${EX2FIX}
	${REINPLACE_CMD} -e 's|DESTINATION examples|DESTINATION ${EXAMPLESDIR}/${ex:C/examples//:C/example//}|'	\
		${WRKSRC}/${ex}/CMakeLists.txt
.endfor

.include <bsd.port.mk>
