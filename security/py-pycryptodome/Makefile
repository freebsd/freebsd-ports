# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	pycryptodome
DISTVERSION=	3.5.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cryptographic library for Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}pycrypto

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Crypto/Cipher/*.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Crypto/Hash/*.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Crypto/Math/*.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Crypto/Protocol/*.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Crypto/Util/*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
