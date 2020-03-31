# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	BRiAl
PORTVERSION=	1.2.8
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python implementation of BRiAl

LICENSE=	GPLv2

LIB_DEPENDS=	libbrial.so:math/brial

USE_GITHUB=	yes
GH_ACCOUNT=	BRiAl

USES=		python:3.6+

WRKSRC_SUBDIR=	sage-brial
USE_PYTHON=	distutils

.include <bsd.port.mk>
