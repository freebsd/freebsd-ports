PORTNAME=	django-cacheops
PORTVERSION=	6.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj31-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Slick ORM cache with automatic granular event-driven invalidation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Extended support of Django 3.1 ends December 2021, upgrade to the Django 3.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=	2021-12-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django31>=2.1:www/py-django31@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=3.0.0:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}funcy>=1.8<2.0:devel/py-funcy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-cacheops \
			${PYTHON_PKGNAMEPREFIX}dj32-django-cacheops

NO_ARCH=		yes

.include <bsd.port.mk>
