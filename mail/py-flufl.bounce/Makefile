# $FreeBSD$

PORTNAME=	flufl.bounce
PORTVERSION=	3.0
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	API for detecting the original bouncing email addresses from a bounce message

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atpublic>=0:devel/py-atpublic \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface

USES=		python:3.4+
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) && !defined(PACKAGE_BUILDING_FLAVORS) && \
    ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>
