# $FreeBSD$

PORTNAME=	zope.principalregistry
PORTVERSION=	3.7.1
PORTREVISION=	1
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Global principal registry component for Zope3

LICENSE=	ZPL21

DEPRECATED=	Old, uses EOLed python27
EXPIRATION_DATE=	2020-02-20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.authentication>=0:security/py-zope.authentication@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.password>=0:security/py-zope.password@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
