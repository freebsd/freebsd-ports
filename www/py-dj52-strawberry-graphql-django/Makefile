PORTNAME=	strawberry-graphql-django
DISTVERSION=	0.65.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj52-
DISTNAME=	strawberry_graphql_django-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Strawberry GraphQL Django extension
WWW=		https://github.com/strawberry-graphql/strawberry-django

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=4.2:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asgiref>=3.8:www/py-asgiref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-strawberry-graphql>=0.276.2:devel/py-dj52-strawberry-graphql@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

OPTIONS_DEFINE=		DEBUG-TOOLBAR ENUM
OPTIONS_DEFAULT=	DEBUG-TOOLBAR ENUM

DEBUG-TOOLBAR_DESC=	Debug support
ENUM_DESC=		Integration for Django's TextChoices/IntegerChoices enumerations

DEBUG-TOOLBAR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj52-django-debug-toolbar>=3.4:www/py-dj52-django-debug-toolbar@${PY_FLAVOR}
ENUM_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}dj52-django-choices-field>=2.2.2:www/py-dj52-django-choices-field@${PY_FLAVOR}

.include <bsd.port.mk>
