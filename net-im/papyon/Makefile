# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	papyon
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.freedesktop.org/software/${PORTNAME}/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Fork of pymsn to support the telepathy MSN connection manager

BUILD_DEPENDS=	py*-openssl>0:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/Crypto/Hash/SHA.py:${PORTSDIR}/security/py-pycrypto \
		${LOCALBASE}/lib/gstreamer-0.10/libgstpython.so:${PORTSDIR}/multimedia/py-gstreamer \
		${PYTHON_SITELIBDIR}/farsight.so:${PORTSDIR}/net-im/farsight2
RUN_DEPENDS=	py*-openssl>0:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/Crypto/Hash/SHA.py:${PORTSDIR}/security/py-pycrypto \
		${LOCALBASE}/lib/gstreamer-0.10/libgstpython.so:${PORTSDIR}/multimedia/py-gstreamer \
		${PYTHON_SITELIBDIR}/farsight.so:${PORTSDIR}/net-im/farsight2

USE_GNOME=	pygobject
USES=		python
USE_PYTHON=	distutils

.include <bsd.port.mk>
