PORTNAME=	django-stubs-ext
PORTVERSION=	6.0.9
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj60-
DISTNAME=	django_stubs_ext-${PORTVERSION}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Monkey-patching and extensions for django-stubs
WWW=		https://github.com/typeddjango/django-stubs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

DEPRECATED=	6.0.9 is supposed to be the last 6.0.x release, migrate to www/py-dj61-django-stubs-ext
EXPIRATION_DATE=	2026-10-03

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django60>=0:www/py-django60@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
