PORTNAME=	quart-trio
PORTVERSION=	0.12.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	quart_trio-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Quart extension to provide trio support
WWW=		https://github.com/pgjones/quart-trio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PY_EXCEPTIONGROUP} \
		${PYTHON_PKGNAMEPREFIX}hypercorn>=0.12.0:www/py-hypercorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}quart>=0.19:www/py-quart@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio>=0.19.0:net/py-trio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
