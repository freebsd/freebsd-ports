# $FreeBSD$

PORTNAME=	yubioath-desktop
PORTVERSION=	3.1.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	GUI for displaying OATH codes with a Yubikey

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyscard>0:security/py-pyscard@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${FLAVOR} \
		pyside${PYTHON_PKGNAMESUFFIX}>0:devel/pyside@${FLAVOR} \
		pcsc-spy:devel/pcsc-lite \
		${LOCALBASE}/lib/pcsc/drivers/ifd-ccid.bundle/Contents/${OPSYS}/libccid.so:devel/libccid

USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
