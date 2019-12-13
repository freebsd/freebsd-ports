# $FreeBSD$

PORTNAME=	django-timezone-field
DISTVERSION=	3.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Provides database and form fields for pytz timezone objects for Django

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=1.11:www/py-django111@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=		yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}dj21-django-timezone-field \
			${PYTHON_PKGNAMEPREFIX}dj22-django-timezone-field

# The 4.0 release dropped support for Django 1.11, 2.0, 2.1 and Python 2.7
PORTSCOUT=	limit:^3\.

.include <bsd.port.mk>
