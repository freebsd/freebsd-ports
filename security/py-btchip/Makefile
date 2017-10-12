# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	btchip
PORTVERSION=	0.1.21
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Python communication library for Ledger Hardware Wallet

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mnemonic>=0:security/py-mnemonic \
		${PYTHON_PKGNAMEPREFIX}pyscard>0:security/py-pyscard \
		${PYTHON_PKGNAMEPREFIX}ecdsa>0:security/py-ecdsa \
		${PYTHON_PKGNAMEPREFIX}hidapi>=0:comms/py-hidapi

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	LedgerHQ
GH_PROJECT=	btchip-python

.include <bsd.port.mk>
