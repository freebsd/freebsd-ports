PORTNAME=	mctc-lib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Computation tool chain library to work with molecular structure data
WWW=		https://grimme-lab.github.io/mctc-lib/ \
		https://github.com/grimme-lab/mctc-lib/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing fortran
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	grimme-lab

CMAKE_ON=	BUILD_SHARED_LIBS

TESTING_UNSAFE=	yes

post-patch: # same as https://github.com/grimme-lab/mctc-lib/pull/55
	@${REINPLACE_CMD} -e 's|$${CMAKE_Fortran_COMPILER_ID}-$${CMAKE_Fortran_COMPILER_VERSION}||' \
		${WRKSRC}/config/CMakeLists.txt

# tests as of 0.5.0: 97% tests passed, 1 tests failed out of 32
# The following tests FAILED:
#          4 - mctc-lib/ncoord (Failed)

.include <bsd.port.mk>
