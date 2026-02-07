PORTNAME=	numsa
DISTVERSION=	0.2.0
CATEGORIES=	science # chemistry
MASTER_SITES=	https://github.com/grimme-lab/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Solvent accessible surface area calculation
WWW=		https://github.com/grimme-lab/numsa/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libmctc-lib.so:science/mctc-lib
TEST_DEPENDS=	test-drive>0:devel/test-drive

USES=		blaslapack cmake fortran tar:xz
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

TEST_TARGET=	test

post-patch: # same as https://github.com/grimme-lab/mctc-lib/pull/55
	@${REINPLACE_CMD} -e 's|$${CMAKE_Fortran_COMPILER_ID}-$${CMAKE_Fortran_COMPILER_VERSION}||' \
		${WRKSRC}/config/CMakeLists.txt

.include <bsd.port.mk>
