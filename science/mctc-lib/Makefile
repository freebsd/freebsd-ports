PORTNAME=	mctc-lib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
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

# tests as of 0.5.1: 100% tests passed, 0 tests failed out of 32

.include <bsd.port.mk>
