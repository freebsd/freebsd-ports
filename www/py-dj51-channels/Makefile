PORTNAME=	channels
PORTVERSION=	4.3.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj51-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Brings async, event-driven capabilities to Django
WWW=		https://channels.readthedocs.io/en/latest/ \
		https://github.com/django/channels

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asgiref>=3.9.0<4:www/py-asgiref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django51>=4.2:www/py-django51@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

.include <bsd.port.mk>
