# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openssl-proxy
PORTVERSION=	0.1
CATEGORIES=	www security python
MASTER_SITES=	CENKES
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyOpenSSLProxy-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTPS proxy support

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>0:${PORTSDIR}/security/py-openssl

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
