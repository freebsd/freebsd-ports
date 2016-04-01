# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	colormath
PORTVERSION=	2.1.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Module that spares the user from directly dealing with color math

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.9.2:math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}networkx>=1.9.1:math/py-networkx

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
