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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>0:security/py-AccessControl \
		${PYTHON_PKGNAMEPREFIX}Acquisition>0:devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>0:devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}DocumentTemplate>0:devel/py-DocumentTemplate \
		${PYTHON_PKGNAMEPREFIX}Persistence>0:devel/py-Persistence \
		${PYTHON_PKGNAMEPREFIX}zope.deferredimport>0:devel/py-zope.deferredimport \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.sendmail>0:mail/py-zope.sendmail

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
