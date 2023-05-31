PORTNAME=	wagtail-bakery
PORTVERSION=	0.8.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of helpers for baking your Django Wagtail site out as flat files
WWW=		https://github.com/wagtail/wagtail-bakery

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-bakery>=0.12.7<0.14:www/py-django-bakery@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wagtail>=4.1:www/py-wagtail@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
