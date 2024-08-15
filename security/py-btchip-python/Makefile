PORTNAME=	btchip-python
DISTVERSION=	0.1.32
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Python communication library for Ledger Hardware Wallet
WWW=		https://github.com/LedgerHQ/btchip-python

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mnemonic>=0:security/py-mnemonic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyscard>=1.6.12.4.b1:security/py-pyscard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecdsa>=0.9:security/py-ecdsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hidapi>=0.7.99:comms/py-hidapi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
