# $FreeBSD$

PORTNAME=	Products.MailHost
PORTVERSION=	2.13.2
CATEGORIES=	mail python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope.sendmail integration for Zope 2

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>0:security/py-AccessControl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Acquisition>0:devel/py-Acquisition@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}DateTime>0:devel/py-DateTime@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}DocumentTemplate>0:devel/py-DocumentTemplate@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Persistence>0:devel/py-Persistence@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.deferredimport>0:devel/py-zope.deferredimport@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.sendmail>0:mail/py-zope.sendmail@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
