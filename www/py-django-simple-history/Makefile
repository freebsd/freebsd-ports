# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	django-simple-history
PORTVERSION=	1.8.1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Store model history and view/revert changes from admin site

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:www/py-django18 # >= 1.8

USE_GITHUB=	yes

GH_ACCOUNT=	treyhunner
USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
