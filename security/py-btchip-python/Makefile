# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	btchip-python
PORTVERSION=	0.1.30
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Python communication library for Ledger Hardware Wallet

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mnemonic>=0:security/py-mnemonic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyscard>=1.6.12.4.b1:security/py-pyscard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecdsa>=0.9:security/py-ecdsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hidapi>=0.7.99:comms/py-hidapi@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

GH_ACCOUNT=	LedgerHQ

.include <bsd.port.mk>
