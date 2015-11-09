# Created by: Peter Haight <peterh@sapros.com>
# $FreeBSD$

PORTNAME=	m2crypto
PORTVERSION=	0.22.5
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	M2Crypto-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Crypto and SSL toolkit for Python

LICENSE=	MIT

BUILD_DEPENDS=	swig3.0:${PORTSDIR}/devel/swig30

PYDISTUTILS_BUILDARGS=	build_ext --openssl=${OPENSSLBASE} --swig=${LOCALBASE}/bin/swig3.0
USE_OPENSSL=	yes
USE_PYTHON=	autoplist distutils
USES=		python:2

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/M2Crypto/_m2crypto.py \
		%%PYTHON_SITELIBDIR%%/M2Crypto/_m2crypto.pyc \
		%%PYTHON_SITELIBDIR%%/M2Crypto/_m2crypto.pyo

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/M2Crypto/__m2crypto.so

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000 && !defined(WITH_OPENSSL_PORT)
IGNORE=		py-m2crypto requires OpenSSL 1.0.1e+
.endif

.include <bsd.port.post.mk>
