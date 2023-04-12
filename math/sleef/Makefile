PORTNAME=	sleef
DISTVERSION=	3.5.1-62
DISTVERSIONSUFFIX=	-g85440a5
CATEGORIES=	math

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	SIMD Library for Evaluating Elementary Functions, vectorized libm
WWW=		https://sleef.org

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c11 pathfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	shibatch

CMAKE_OFF=	BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*} || ${ARCH:Marmv?}
PLIST_SUB+=	GNUABI="@comment "
.else
PLIST_SUB+=	GNUABI=""
.endif

.include <bsd.port.mk>
