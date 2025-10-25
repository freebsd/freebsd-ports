PORTNAME=	django-filter
DISTVERSION=	25.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj51-
DISTNAME=	django_filter-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Dynamic filtering for querysets with Django
WWW=		https://github.com/carltongibson/django-filter

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Extended support of Django 5.1 ends December 2025, upgrade to the Django 5.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=2025-12-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django51>=4.2:www/py-django51@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

# Release 25.2 dropped support for Django < 5.2
PORTSCOUT=	ignore:1

.include <bsd.port.mk>
