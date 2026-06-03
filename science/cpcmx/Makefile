PORTNAME=	cpcmx
DISTVERSION=	1.1.0
CATEGORIES=	science # chemistry
MASTER_SITES=	https://github.com/grimme-lab/CPCM-X/releases/download/v${DISTVERSION}/
DISTNAME=	cpx-${DISTVERSION}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Extended conductor-like polarizable continuum solvation model
WWW=		https://github.com/grimme-lab/CPCM-X/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmctc-lib.so:science/mctc-lib \
		libnumsa.so:science/numsa \
		libtoml-f.so:textproc/toml-f
TEST_DEPENDS=	test-drive>0:devel/test-drive

USES=		blaslapack cmake fortran tar:xz
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

TEST_TARGET=	test

# Remove bundled libraries
post-extract:
	${RM} -r ${WRKSRC}/subprojects

post-patch: # same as https://github.com/grimme-lab/mctc-lib/pull/55
	@${REINPLACE_CMD} -e 's|$${CMAKE_Fortran_COMPILER_ID}-$${CMAKE_Fortran_COMPILER_VERSION}||' \
		${WRKSRC}/config/CMakeLists.txt

.include <bsd.port.mk>
