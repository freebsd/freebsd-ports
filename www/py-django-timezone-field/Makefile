PORTNAME=	django-timezone-field
DISTVERSION=	4.2.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Provides database and form fields for pytz timezone objects for Django

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=2.2:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

NO_ARCH=		yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}dj31-django-timezone-field \
			${PYTHON_PKGNAMEPREFIX}dj32-django-timezone-field

OPTIONS_DEFINE=		REST
OPTIONS_DEFAULT=	REST

REST_DESC=	Support for field serialization via REST

REST_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}djangorestframework>=3.0.0,1:www/py-djangorestframework@${PY_FLAVOR}

.include <bsd.port.mk>
