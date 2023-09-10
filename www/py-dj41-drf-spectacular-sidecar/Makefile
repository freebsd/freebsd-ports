PORTNAME=	drf-spectacular-sidecar
DISTVERSION=	2023.8.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj41-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Serve self-contained Swagger UI/Redoc distribution builds with Django
WWW=		https://github.com/tfranzel/drf-spectacular

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Extended support of Django 4.1 ends December 2023, upgrade to the Django 4.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=	2023-12-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django41>=2.2:www/py-django41@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

.include <bsd.port.mk>
