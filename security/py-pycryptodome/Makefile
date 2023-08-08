PORTNAME=	pycryptodome
DISTVERSION=	3.18.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@saltant.com
COMMENT=	Cryptographic library for Python
WWW=		https://www.pycryptodome.org/

LICENSE=	APACHE20 BSD2CLAUSE PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycryptodome-test-vectors>=0:security/py-pycryptodome-test-vectors@${PY_FLAVOR}

# Officially: 2.7, 3.5-3.11
USES=		cpe python
CPE_VENDOR=	python
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}pycrypto

NAMESPACE?=	Crypto

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${NAMESPACE}/Cipher/*.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${NAMESPACE}/Hash/*.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${NAMESPACE}/Math/*.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${NAMESPACE}/Protocol/*.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${NAMESPACE}/PublicKey/*.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${NAMESPACE}/Util/*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m ${NAMESPACE}.SelfTest

.include <bsd.port.mk>
