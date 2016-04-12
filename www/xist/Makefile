# Created by: ijliao
# $FreeBSD$

PORTNAME=	xist
PORTVERSION=	5.15.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://ftp.livinglogic.de/xist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ll-${PORTNAME}-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	XML-based extensible HTML generator

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssutils>=1.0:www/py-cssutils \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.4:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}pillow>=2.6:graphics/py-pillow

USES=		python:3 tar:bzip2
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) && ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=		you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>
