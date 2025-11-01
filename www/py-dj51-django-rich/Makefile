PORTNAME=	django-rich
DISTVERSION=	2.2.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj51-
DISTNAME=	django_rich-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Extensions for using Rich with Django
WWW=		https://github.com/adamchainz/django-rich

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Extended support of Django 5.1 ends December 2025, upgrade to the Django 5.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=2025-12-31

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django51>=4.2:www/py-django51@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=10.0.0:textproc/py-rich@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

.include <bsd.port.mk>
