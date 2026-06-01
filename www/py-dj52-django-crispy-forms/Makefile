PORTNAME=	django-crispy-forms
PORTVERSION=	2.6
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj52-
DISTNAME=	django_crispy_forms-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Best way to have Django DRY forms
WWW=		https://django-crispy-forms.readthedocs.io/en/latest/ \
		https://github.com/django-crispy-forms/django-crispy-forms

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Obsolete, please use www/py-django-crispy-forms instead
EXPIRATION_DATE=2026-06-30

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=5.2:www/py-django52@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
