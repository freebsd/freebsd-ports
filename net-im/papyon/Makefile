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

BUILD_DEPENDS=	py*-openssl>0:security/py-openssl \
		${PYTHON_SITELIBDIR}/Crypto/Hash/SHA.py:security/py-pycrypto \
		${LOCALBASE}/lib/gstreamer-0.10/libgstpython.so:multimedia/py-gstreamer \
		${PYTHON_SITELIBDIR}/farsight.so:net-im/farsight2
RUN_DEPENDS=	py*-openssl>0:security/py-openssl \
		${PYTHON_SITELIBDIR}/Crypto/Hash/SHA.py:security/py-pycrypto \
		${LOCALBASE}/lib/gstreamer-0.10/libgstpython.so:multimedia/py-gstreamer \
		${PYTHON_SITELIBDIR}/farsight.so:net-im/farsight2

USE_GNOME=	pygobject
USES=		python
USE_PYTHON=	distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3400
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>0:devel/py-enum34
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enum34>0:devel/py-enum34
.endif

.include <bsd.port.post.mk>
