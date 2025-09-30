PORTNAME=	drf-writable-nested
PORTVERSION=	0.7.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj51-

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Writable nested model serializer for Django REST framework
WWW=		https://github.com/beda-software/drf-writable-nested

LICENSE=	BSD2CLAUSE

DEPRECATED=	Extended support of Django 5.1 ends December 2025, upgrade to the Django 5.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=2025-12-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django51>=5.1:www/py-django51@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-djangorestframework>0:www/py-dj51-djangorestframework@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	beda-software
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

.include <bsd.port.mk>
