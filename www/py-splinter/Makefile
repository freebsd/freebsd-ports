# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	splinter
PORTVERSION=	0.5.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Browser abstraction for web acceptance testing

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}selenium>=2.33:${PORTSDIR}/www/py-selenium \
		${PYTHON_PKGNAMEPREFIX}zope.testbrowser>=4.0.2:${PORTSDIR}/devel/py-zope.testbrowser \
		${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}cssselect>0:${PORTSDIR}/www/py-cssselect

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
