PORTNAME=	openbrokerapi
PORTVERSION=	4.6.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Package for the V2 CF Service Broker API and Open Broker API
WWW=		https://pypi.org/project/openbrokerapi/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=2.2.3:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>0:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>0:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itsdangerous>0:security/py-itsdangerous@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>0:www/py-werkzeug@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
