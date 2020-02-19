# $FreeBSD$

PORTNAME=	zope.app.locales
PORTVERSION=	3.7.5
CATEGORIES=	textproc python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope locale extraction and management utilities

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Old, uses EOLed python27
EXPIRATION_DATE=	2020-03-18

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>0:textproc/py-zope.i18nmessageid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.tal>=0:textproc/py-zope.tal@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
