PORTNAME=	django-filter
DISTVERSION=	25.2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj52-
DISTNAME=	django_filter-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Dynamic filtering for querysets with Django
WWW=		https://github.com/carltongibson/django-filter

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=5.2:www/py-django52@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

OPTIONS_DEFINE=		DRF
OPTIONS_DEFAULT=	DRF

DRF_DESC=	Support for Django REST framework

DRF_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj52-djangorestframework>0:www/py-dj52-djangorestframework@${PY_FLAVOR}

.include <bsd.port.mk>
