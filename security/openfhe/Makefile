PORTNAME=	openfhe
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	security math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open-source Fully Homomorphic Encryption library
WWW=		https://github.com/openfheorg/openfhe-development

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	autoconf:devel/autoconf # possibly a mistake in the project

USES=		cmake:noninja,testing compiler:c++17-lang # cmake refuses to work with ninja
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	openfheorg
GH_PROJECT=	openfhe-development
GH_TUPLE=	openfheorg:cereal:984e3f1:cereal/third-party/cereal \
		google:googletest:8b4817e:google_test/third-party/google-test

LDFLAGS+=	-pthread

CMAKE_OFF=	BUILD_UNITTESTS BUILD_EXAMPLES BUILD_BENCHMARKS
CMAKE_TESTING_ON=	BUILD_UNITTESTS
CMAKE_TESTING_TARGET=	testall

BINARY_ALIAS=	git=false

.include <bsd.port.mk>
