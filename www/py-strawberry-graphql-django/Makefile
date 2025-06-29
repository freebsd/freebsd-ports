PORTNAME=	strawberry-graphql-django
DISTVERSION=	0.60.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	strawberry_graphql_django-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Strawberry GraphQL Django extension
WWW=		https://github.com/strawberry-graphql/strawberry-django

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asgiref>=3.8:www/py-asgiref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}strawberry-graphql>=0.264.0:devel/py-strawberry-graphql@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

OPTIONS_DEFINE=		DEBUG-TOOLBAR ENUM
OPTIONS_DEFAULT=	DEBUG-TOOLBAR ENUM

DEBUG-TOOLBAR_DESC=	Debug support
ENUM_DESC=		Integration for Django's TextChoices/IntegerChoices enumerations

DEBUG-TOOLBAR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-debug-toolbar>=3.4:www/py-django-debug-toolbar@${PY_FLAVOR}
ENUM_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}django-choices-field>=2.2.2:www/py-django-choices-field@${PY_FLAVOR}

.include <bsd.port.mk>
