PORTNAME=	dimod
DISTVERSION=	0.12.21
CATEGORIES=	science python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Shared API for QUBO/Ising samplers
WWW=		https://github.com/dwavesystems/dimod

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	catch>0:devel/catch

USES=		compiler:c++11-lang pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

NO_BUILD=	yes
NO_ARCH=	yes

BINARY_ALIAS=	g++=${CXX} git=true

do-install:
	cd ${WRKSRC}/dimod/include && \
		${COPYTREE_SHARE} dimod ${STAGEDIR}${PREFIX}/include

do-test:
	@cd ${WRKSRC}/testscpp && ${SETENV} ${MAKE_ENV} ${MAKE}

# tests as of 0.12.21: All tests passed (104295 assertions in 35 test cases)

.include <bsd.port.mk>
