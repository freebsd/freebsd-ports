# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	falcon
PORTVERSION=	1.4.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lichray@gmail.com
COMMENT=	High-performance Python framework for building cloud APIs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mimeparse>=1.5.2:devel/py-mimeparse@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist cython

do-test:
		@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYTHON_VER})

.include <bsd.port.mk>
