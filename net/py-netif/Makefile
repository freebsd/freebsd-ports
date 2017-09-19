# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD: head/net/py-netif/Makefile 430454 2017-01-03 11:01:05Z mat $

PORTNAME=	netif
PORTVERSION=	1.0.20170713
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python network configuration library for FreeBSD

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	cython>0:lang/cython
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsd>0:devel/py-bsd

USE_GITHUB=     yes
GH_ACCOUNT=	freenas
GH_PROJECT=	py-netif
GH_TAGNAME=	c132291f

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>0:devel/py-enum34
.endif

.include <bsd.port.post.mk>
