PORTNAME=	django-configurator
DISTVERSION=	1.3.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_configurator-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Django class based settings and setting object types with validation
WWW=		https://github.com/UhuruTechnology/django-configurator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.1:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-configurations

NO_ARCH=		yes

# There are also options CACHE, EMAIL, and SEARCH, but they have been omitted
# for now because they require ports that are not currently present in the
# ports tree.
OPTIONS_DEFINE=		DATABASE

DATABASE_DESC=	Support for database URLs

DATABASE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj-database-url>0:www/py-dj-database-url@${PY_FLAVOR}

.include <bsd.port.mk>
