# $FreeBSD$

PORTNAME=	yubikey-manager
PORTVERSION=	0.6.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Python library and command line tool for configuring a YubiKey

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyscard>0:security/py-pyscard@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}usb>0:devel/py-usb@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${FLAVOR} \
		pcsc-spy:devel/pcsc-lite \
		${LOCALBASE}/lib/pcsc/drivers/ifd-ccid.bundle/Contents/${OPSYS}/libccid.so:devel/libccid \
		u2f-host:security/libu2f-host \
		ykpers>0:security/ykpers

USES=		python:3.4+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
