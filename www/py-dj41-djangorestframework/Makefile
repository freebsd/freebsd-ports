PORTNAME=	djangorestframework
PORTVERSION=	3.14.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj41-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Django REST framework
WWW=		https://www.django-rest-framework.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

DEPRECATED=	Extended support of Django 4.1 ends December 2023, upgrade to the Django 4.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=	2023-12-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django41>=3.0:www/py-django41@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}
NO_ARCH=		yes

.include <bsd.port.mk>
