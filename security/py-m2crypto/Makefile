# Created by: Peter Haight <peterh@sapros.com>
# $FreeBSD$

PORTNAME=	m2crypto
PORTVERSION=	0.25.1
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
USE_PYTHON=	autoplist concurrent distutils
USES=		python ssl

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000 && ${SSL_DEFAULT} == base
IGNORE=		py-m2crypto requires OpenSSL 1.0.1e+
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/M2Crypto/__m2crypto.so

.include <bsd.port.post.mk>
