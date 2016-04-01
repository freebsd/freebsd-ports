# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	vertex
PORTVERSION=	0.3.1
CATEGORIES=	net-p2p python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Vertex-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vertex is an implementation of the Q2Q protocol

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/epsilon/__init__.py:devel/py-epsilon \
		${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:security/py-openssl
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/epsilon/__init__.py:devel/py-epsilon \
		${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:security/py-openssl

LICENSE=	MIT

USES=		python twisted
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
