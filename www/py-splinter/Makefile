# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	splinter
PORTVERSION=	0.7.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Browser abstraction for web acceptance testing

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}selenium>=2.47:www/py-selenium \
		${PYTHON_PKGNAMEPREFIX}zope.testbrowser>=4.0.4:devel/py-zope.testbrowser \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}cssselect>0:www/py-cssselect \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
