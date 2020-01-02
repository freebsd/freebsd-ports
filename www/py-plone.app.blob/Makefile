# $FreeBSD$

PORTNAME=	plone.app.blob
PORTVERSION=	1.5.17
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	ZODB blob support for Plone

DEPRECATED=	Outdated version of plone 4.3 (legacy), uses EOLed python27
EXPIRATION_DATE=	2020-02-03

LICENSE=	GPLv2

RUN_DEPENDS=	zodb${PYTHON_PKGNAMESUFFIX}>=3.8.1:databases/zodb3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.proxy>=3.4:net/py-zope.proxy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}archetypes.schemaextender>=1.6:devel/py-archetypes.schemaextender@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.imaging>1.0:www/py-plone.app.imaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.scale>=0:www/py-plone.scale@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
