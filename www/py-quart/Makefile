PORTNAME=	quart
PORTVERSION=	0.20.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python ASGI web framework with the same API as Flask
WWW=		https://quart.palletsprojects.com/en/latest/ \
		https://github.com/pallets/quart

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=0<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiofiles>=0:devel/py-aiofiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>=1.6:devel/py-blinker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=3.0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypercorn>=0.11.2:www/py-hypercorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itsdangerous>=0:security/py-itsdangerous@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=3.0:www/py-werkzeug@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
