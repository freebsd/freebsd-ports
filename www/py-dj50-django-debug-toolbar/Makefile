PORTNAME=	django-debug-toolbar
PORTVERSION=	4.3.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj50-
DISTNAME=	django_debug_toolbar-${PORTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Configurable set of panels to display debug information
WWW=		https://github.com/jazzband/django-debug-toolbar

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django50>=3.2.4:www/py-django50@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.2.0:databases/py-sqlparse@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

# Newer versions of py-django-debug-toolbar have an issue with DNS resolving
PORTSCOUT=	ignore:1

.include <bsd.port.mk>
