# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rsa
PORTVERSION=	3.1.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Pure-Python RSA implementation

LICENSE=	AL2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1>=0.1.3:${PORTSDIR}/devel/py-asn1

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
