PORTNAME=	djangorestframework
PORTVERSION=	3.12.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj31-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Django REST framework

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

DEPRECATED=	Extended support of Django 3.1 ends December 2021, upgrade to the Django 3.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=	2021-12-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django31>=2.2:www/py-django31@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}djangorestframework3* \
			${PYTHON_PKGNAMEPREFIX}djangorestframework \
			${PYTHON_PKGNAMEPREFIX}dj32-djangorestframework
NO_ARCH=		yes

.include <bsd.port.mk>
