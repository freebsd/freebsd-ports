# $FreeBSD$

PORTNAME=	potr
PORTVERSION=	1.0.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Pure Python Off-The-Record encryption

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${FLAVOR}

USES=		python zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
