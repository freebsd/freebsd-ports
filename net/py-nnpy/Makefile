# $FreeBSD$

PORTNAME=	nnpy
PORTVERSION=	1.3
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	cffi-based Python bindings for nanomsg

LICENSE=	MIT

LIB_DEPENDS=	libnanomsg.so:net/nanomsg
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
