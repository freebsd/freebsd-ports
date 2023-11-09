PORTNAME=	mcpl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.2
CATEGORIES=	science # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Monte Carlo Particle Lists library
WWW=		https://mctools.github.io/mcpl/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake python shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mctools

SHEBANG_FILES=	src/python/pymcpltool \
		cmake/mcpl-config.in

.include <bsd.port.mk>
