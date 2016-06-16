# Created by: Peter Haight <peterh@sapros.com>
# $FreeBSD$

PORTNAME=	m2crypto
PORTVERSION=	0.24.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	M2Crypto-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Crypto and SSL toolkit for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	swig3.0:devel/swig30

PYDISTUTILS_BUILDARGS=	build_ext --openssl=${OPENSSLBASE} --swig=${LOCALBASE}/bin/swig3.0
USE_OPENSSL=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/M2Crypto/_m2crypto.py \
		%%PYTHON_SITELIBDIR%%/M2Crypto/${PYCACHE_DIR}${PYCACHE_FILE}.pyc \
		%%PYTHON_SITELIBDIR%%/M2Crypto/${PYCACHE_DIR}${PYCACHE_FILE}.${PYOEXTENSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000 && ${SSL_DEFAULT} == base
IGNORE=		py-m2crypto requires OpenSSL 1.0.1e+
.endif

.if ${PYTHON_REL} < 3200
PYCACHE_DIR=	# empty
PYCACHE_FILE=	_${PORTNAME}
.else
PYCACHE_DIR=	__pycache__/
PYCACHE_FILE=	_${PORTNAME}.cpython-${PYTHON_SUFFIX}
.endif

.if ${PYTHON_REL} < 3500
PYOEXTENSION=	pyo
.else
PYOEXTENSION=	opt-1.pyc
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/M2Crypto/__m2crypto.so

.include <bsd.port.post.mk>
