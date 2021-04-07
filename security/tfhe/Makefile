PORTNAME=	tfhe
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1-30
DISTVERSIONSUFFIX=	-ga085efe
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast Fully Homomorphic Encryption (FHE) library over the Torus

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 # because of arch-specific assembly

BUILD_DEPENDS=	cmake:devel/cmake
TEST_DEPENDS=	fftw3>0:math/fftw3 \
		googletest>0:devel/googletest

USES=		compiler:c++11-lang gmake localbase:ldflags
USE_GITHUB=	yes
USE_LDCONFIG=	yes

BINARY_ALIAS=	make=${GMAKE}

TEST_TARGET=	test # -avx and -fma will fail where no such hardware optimization is available

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so

.include <bsd.port.mk>
