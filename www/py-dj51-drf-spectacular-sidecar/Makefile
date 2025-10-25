PORTNAME=	drf-spectacular-sidecar
DISTVERSION=	2025.10.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj51-
DISTNAME=	drf_spectacular_sidecar-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Serve self-contained Swagger UI/Redoc distribution builds with Django
WWW=		https://github.com/tfranzel/drf-spectacular

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Extended support of Django 5.1 ends December 2025, upgrade to the Django 5.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=2025-12-31

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django51>=2.2:www/py-django51@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

.include <bsd.port.mk>
