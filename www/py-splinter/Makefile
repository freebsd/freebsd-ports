# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	splinter
PORTVERSION=	0.7.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Browser abstraction for web acceptance testing

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}selenium>=2.47:www/py-selenium@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.testbrowser>=4.0.4:devel/py-zope.testbrowser@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssselect>0:www/py-cssselect@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
