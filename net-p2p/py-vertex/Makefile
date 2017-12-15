# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	vertex
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	net-p2p python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Vertex-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Vertex is an implementation of the Q2Q protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}epsilon>=0:devel/py-epsilon@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python

.include <bsd.port.mk>
