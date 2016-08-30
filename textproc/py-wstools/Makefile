# $FreeBSD$

PORTNAME=	wstools
PORTVERSION=	0.4.4
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	WSDL parsing services for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/docs/license.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six

NO_ARCH=	yes
USES=		python:2.7+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
