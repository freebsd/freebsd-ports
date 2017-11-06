# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	trezor
PORTVERSION=	0.7.16
DISTVERSIONPREFIX=	v
CATEGORIES=	security
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Client side implementation for TREZOR Bitcoin hardware wallets

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mnemonic>=0:security/py-mnemonic \
		${PYTHON_PKGNAMEPREFIX}hidapi>=0:comms/py-hidapi \
		${PYTHON_PKGNAMEPREFIX}ecdsa>0:security/py-ecdsa \
		${PYTHON_PKGNAMEPREFIX}protobuf>=2.5.0:devel/py-protobuf

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_PROJECT=	python-trezor

.include <bsd.port.mk>
