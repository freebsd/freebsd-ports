# $FreeBSD$

PORTNAME=	wstools
PORTVERSION=	0.4.3
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	WSDL parsing services for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/docs/license.txt

NO_ARCH=	yes
USES=		python:2
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e "s|'docutils'||g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
