PORTNAME=	django-timezone-field
DISTVERSION=	4.2.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj32-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Provides database and form fields for pytz timezone objects for Django

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=2.2:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}dj31-django-timezone-field \
			${PYTHON_PKGNAMEPREFIX}django-timezone-field

NO_ARCH=		yes

OPTIONS_DEFINE=		REST
OPTIONS_DEFAULT=	REST

REST_DESC=	Support for field serialization via REST

REST_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj32-djangorestframework>=3.0.0:www/py-dj32-djangorestframework@${PY_FLAVOR}

.include <bsd.port.mk>
