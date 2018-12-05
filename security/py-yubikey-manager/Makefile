# $FreeBSD$

PORTNAME=	yubikey-manager
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Python library and command line tool for configuring a YubiKey

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fido2>0:security/py-fido2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyscard>0:security/py-pyscard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}usb>0:devel/py-usb@${PY_FLAVOR} \
		${LOCALBASE}/lib/pcsc/drivers/ifd-ccid.bundle/Contents/${OPSYS}/libccid.so:devel/libccid \
		pcsc-spy:devel/pcsc-lite \
		u2f-host:security/libu2f-host \
		ykpers>0:security/ykpers

USES=		python:3.4+
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
