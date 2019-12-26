# $FreeBSD$

PORTNAME=	cec
PORTVERSION=	0.2.7
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for libcec

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcec.so:multimedia/libcec

USES=		compiler:c++11-lang localbase python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
