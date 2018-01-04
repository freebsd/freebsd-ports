# $FreeBSD$

PORTNAME=	cec
PORTVERSION=	0.2.6
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Python bindings for libcec

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcec.so:multimedia/libcec

USES=		python:2.7
USE_PYTHON=	distutils autoplist

CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
