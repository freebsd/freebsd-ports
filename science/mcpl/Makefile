PORTNAME=	mcpl
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	science # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Monte Carlo Particle Lists library
WWW=		https://mctools.github.io/mcpl/ \
		https://github.com/mctools/mcpl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails, see https://github.com/mctools/mcpl/issues/88

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mctools

CMAKE_OFF=	MCPL_ENABLE_TESTING
CMAKE_TESTING_ON=	MCPL_ENABLE_TESTING

# tests as of 2.0.0: 100% tests passed, 0 tests failed out of 27

.include <bsd.port.mk>
