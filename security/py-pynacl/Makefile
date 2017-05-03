# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	pynacl
PORTVERSION=	1.1.2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyNaCl-${PORTVERSION}

MAINTAINER=	yuri@rawbw.com
COMMENT=	PyNaCl is a Python binding to the Networking and Cryptography library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six
BUILD_DEPENDS=	${RUN_DEPENDS}
BUNDLED_NACL_LIB_DEPENDS_OFF=	libsodium.so:security/libsodium
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest

USES=		python localbase
USE_PYTHON=	autoplist distutils
BUNDLED_NACL_MAKE_ENV_OFF+=	SODIUM_INSTALL=system

OPTIONS_DEFINE=	BUNDLED_NACL
BUNDLED_NACL_DESC=	Use bundled NaCl version

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/nacl/_sodium.so

do-test:
	@cd ${WRKSRC} && ${SETENV} PYTHONPATH=../src ${PYTHON_CMD} -m pytest -rs tests

.include <bsd.port.mk>
