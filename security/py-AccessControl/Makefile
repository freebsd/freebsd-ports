# $FreeBSD$

PORTNAME=	AccessControl
PORTVERSION=	3.0.13
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Security framework for Zope2

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:devel/py-DateTime@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:devel/py-ExtensionClass@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Persistence>=0:devel/py-Persistence@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Record>=0:devel/py-Record@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}RestrictedPython>=0:security/py-RestrictedPython@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zExceptions>=0:devel/py-zExceptions@${FLAVOR} \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.deferredimport>=0:devel/py-zope.deferredimport@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:devel/py-zope.testing@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/AccessControl/cAccessControl.so

.include <bsd.port.mk>
