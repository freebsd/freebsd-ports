# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	falcon
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lichray@gmail.com
COMMENT=	High-performance Python framework for building cloud APIs

LICENSE=	APACHE20

BUILD_DEPENDS=	cython>=0.11.2:lang/cython
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}testtools>=0:devel/py-testtools \
		${PYTHON_PKGNAMEPREFIX}six>=1.1.0:devel/py-six

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
