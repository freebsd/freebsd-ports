PORTNAME=	django-bleach
PORTVERSION=	3.0.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easily use bleach with Django models and templates
WWW=		https://github.com/marksweb/django-bleach

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bleach>=5<6:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django32>=3.2:www/py-django32@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
