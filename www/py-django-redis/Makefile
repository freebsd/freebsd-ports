PORTNAME=	django-redis
PORTVERSION=	5.0.0
CATEGORIES=	www databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Full featured Redis cache/session backend for Django

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=2.2:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=3.0.0:databases/py-redis@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hiredis>=0:databases/py-hiredis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0:devel/py-msgpack@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}dj31-django-redis

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC}/tests && ${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
