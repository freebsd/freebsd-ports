# Created by: Kevin Golding <ports@caomhin.org>

PORTNAME=	django-happenings-update
PORTVERSION=	0.4.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Event calendar app for Django

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream no longer maintained, not compatible with newer versions of Django
EXPIRATION_DATE=	2022-06-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.11:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9<2.0:devel/py-six@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-happenings

.include <bsd.port.mk>
