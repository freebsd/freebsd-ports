PORTNAME=	drf-spectacular-sidecar
DISTVERSION=	2025.3.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj50-
DISTNAME=	drf_spectacular_sidecar-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Serve self-contained Swagger UI/Redoc distribution builds with Django
WWW=		https://github.com/tfranzel/drf-spectacular

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Extended support of Django 5.0 ends April 2025, upgrade to the Django 5.1+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=2025-05-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django50>=2.2:www/py-django50@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

.include <bsd.port.mk>
