# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	urllib3
PORTVERSION=	1.25.6
PORTEPOCH=	1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	HTTP library with thread-safe connection pooling, file post, and more

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=0:www/py-tornado@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	BROTLI SOCKS SSL
OPTIONS_DEFAULT=SOCKS SSL

BROTLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotlipy>=0.6.0:archivers/py-brotlipy@${PY_FLAVOR}
SOCKS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysocks>=1.5.6:net/py-pysocks@${PY_FLAVOR}
SSL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}idna>=2.0:dns/py-idna@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}cryptography>=1.3.4:security/py-cryptography@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}openssl>=0.14:security/py-openssl@${PY_FLAVOR} \
			${PY_IPADDRESS}

# Test 'test_ssl_read_timeout' fails with FreeBSD >= 12.0. That was already the
# case with earlier versions of net/py-urllib3.
do-test:
	@cd ${WRKSRC} && ${SETENV} LC_ALL=en_US.UTF-8 ${PYTHON_CMD} -m pytest -v -rs -k 'not test_ssl_read_timeout'

.include <bsd.port.mk>
