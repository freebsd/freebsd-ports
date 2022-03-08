# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	wsaccel
PORTVERSION=	0.6.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	WebSocket Accelerator for ws4py and AutobahnPython

LICENSE=	APACHE20

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/utf8validator*.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/xormask*.so

.include <bsd.port.mk>
