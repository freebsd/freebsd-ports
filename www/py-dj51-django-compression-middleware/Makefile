PORTNAME=	django-compression-middleware
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj51-

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Django middleware to compress responses using several algorithms
WWW=		https://github.com/friedelwolff/django-compression-middleware

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Extended support of Django 5.1 ends December 2025, upgrade to the Django 5.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=2025-12-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django51>=5.1:www/py-django51@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zstandard>=0.22.0:archivers/py-zstandard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotli>=1.1.0:archivers/py-brotli@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

.include <bsd.port.mk>
