PORTNAME=	django-stubs-ext
PORTVERSION=	5.2.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX?=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_stubs_ext-${PORTVERSION}

MAINTAINER?=	sunpoet@FreeBSD.org
COMMENT=	Monkey-patching and extensions for django-stubs
WWW=		https://github.com/typeddjango/django-stubs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django${DJANGO_VERSION}>=0:www/py-django${DJANGO_VERSION}@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CONFLICTS_INSTALL?=	www/py-dj52-django-stubs-ext

DJANGO_VERSION?=	42

.include <bsd.port.mk>
