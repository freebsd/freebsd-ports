# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-annoying
PORTVERSION=	0.10.3
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Eliminate annoying things in the Django framework

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:www/py-django18@${FLAVOR}

USE_GITHUB=	yes

GH_ACCOUNT=	skorokithakis
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
