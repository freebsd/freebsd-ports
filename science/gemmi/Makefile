PORTNAME=	gemmi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.3
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Macromolecular crystallography library and utilities
WWW=		https://gemmi.readthedocs.io/en/latest/ \
		https://github.com/project-gemmi/gemmi

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++20-lang # tests don't run, see https://github.com/project-gemmi/gemmi/issues/231

USE_GITHUB=	yes
GH_ACCOUNT=	project-gemmi

CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_ARGS=		-DCMAKE_CXX_VISIBILITY_PRESET=default # for the Python extension science/py-gemmi to see all symbols
CMAKE_TESTING_TARGET=	check

OPTIONS_DEFINE=		FORTRAN

FORTRAN_USES=		fortran
FORTRAN_CMAKE_BOOL=	USE_FORTRAN
FORTRAN_BROKEN=		project option doesn't do anything, see https://github.com/project-gemmi/gemmi/issues/232

# tests as of 0.7.3 (run work/.build/cpptest):
# [doctest] test cases:  14 |  14 passed | 0 failed | 0 skipped
# [doctest] assertions: 129 | 129 passed | 0 failed |
# [doctest] Status: SUCCESS!

.include <bsd.port.mk>
