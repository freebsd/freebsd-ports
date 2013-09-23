# $FreeBSD$

PORTNAME=	plone.z3cform
PORTVERSION=	0.8.0
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Library that allows use of z3c.form with Zope 2 and the CMF

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.batching>0:${PORTSDIR}/www/py-plone.batching \
		${PYTHON_PKGNAMEPREFIX}z3c.form>=0:${PORTSDIR}/devel/py-z3c.form \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=3.4:${PORTSDIR}/devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.browserpage>0:${PORTSDIR}/devel/py-zope.browserpage \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes
USE_ZOPE=	yes

NO_STAGE=	yes

.include <bsd.port.mk>
