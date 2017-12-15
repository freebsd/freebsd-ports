# Created by: Axel Rau <axel.rau@chaos1.de>
# $FreeBSD$

PORTNAME=	service_identity
PORTVERSION=	17.0.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	axel.rau@chaos1.de
COMMENT=	Service identity verification for pyOpenSSL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=15.2:devel/py-attrs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.15:security/py-openssl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.9:devel/py-pyasn1@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0.0.8:devel/py-pyasn1-modules@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}characteristic>=14.1:devel/py-characteristic@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
