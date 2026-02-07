PORTNAME=	mopac
DISTVERSIONPREFIX=	v
DISTVERSION=	23.2.2
PORTEPOCH=	1
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Semi-empirical (MNDO, etc.) molecular orbital calculation
WWW=		http://openmopac.net \
		https://github.com/openmopac/mopac

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYNUMPY}

USES=		blaslapack:openblas cmake:testing fortran python:test
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	openmopac

CMAKE_OFF=	TESTS
CMAKE_TESTING_ON=	TESTS # all tests pass
CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD} #-DPython3_NumPy_INCLUDE_DIRS=${PYTHONPREFIX_SITELIBDIR}/numpy/core/include

PLIST_FILES=	bin/mopac \
		bin/mopac-makpol \
		bin/mopac-param \
		include/mopac.h \
		lib/libmopac.so \
		lib/libmopac.so.2

# tests as of 23.1.2: 100% tests passed, 0 tests failed out of 125
# tests as of 23.2.2: 99% tests passed, 1 tests failed out of 125, see https://github.com/openmopac/mopac/issues/302

.include <bsd.port.mk>
