PORTNAME=	requests-ratelimiter
PORTVERSION=	0.10.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	requests_ratelimiter-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rate-limiting for the requests library
WWW=		https://requests-ratelimiter.readthedocs.io/en/stable/ \
		https://github.com/JWCook/requests-ratelimiter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyrate-limiter>=4.1<5:devel/py-pyrate-limiter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
