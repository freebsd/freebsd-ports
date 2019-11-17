# $FreeBSD$

PORTNAME=	cec
PORTVERSION=	0.2.7
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for libcec

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcec.so:multimedia/libcec

USES=		compiler:c++11-lang localbase python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
