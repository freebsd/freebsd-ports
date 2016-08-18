# $FreeBSD$

PORTNAME=	cec
PORTVERSION=	0.2.5
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Python bindings for libcec

LICENSE=	GPLv2

LIB_DEPENDS=	libcec.so:multimedia/libcec

USES=		python
USE_PYTHON=	distutils autoplist

CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
