# Created by: Peter Haight <peterh@sapros.com>
# $FreeBSD$

PORTNAME=	m2crypto
PORTVERSION=	0.37.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	M2Crypto-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Crypto and SSL toolkit for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	swig>=2.0.4:devel/swig
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}parameterized>=0:devel/py-parameterized@${PY_FLAVOR} \
		${PY_TYPING}

USES=		python:3.6+ ssl
USE_PYTHON=	autoplist concurrent distutils

PYDISTUTILS_BUILDARGS=	build_ext --openssl=${OPENSSLBASE} --swig=${LOCALBASE}/bin/swig

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/M2Crypto/_m2crypto*.so

.include <bsd.port.mk>
