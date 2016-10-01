# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyfst
PORTVERSION=	0.2.3
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Python interface for the OpenFST library

LICENSE=	APACHE20

LIB_DEPENDS=	libfst.so:math/openfst

BROKEN=	does not build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-11-01

USES=		compiler:c++11-lib python
USE_PYTHON=	distutils autoplist
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
