# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>

PORTNAME=	requests
PORTVERSION=	2.25.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python HTTP for Humans

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=2017.4.17:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=3.0.2,1<5,1:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=2.5<4:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.21.1,1<1.27,1:net/py-urllib3@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysocks>=1.5.6:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=3,1:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-httpbin>=0.0.7:devel/py-pytest-httpbin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0,1:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		cpe python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CPE_VENDOR=	python

OPTIONS_DEFINE=	SECURITY SOCKS
OPTIONS_DEFAULT=SECURITY SOCKS
SECURITY_DESC=	Extra security functionalities
SOCKS_DESC=	Extra socks functionalities

SECURITY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=1.3.4:security/py-cryptography@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}openssl>=0.14:security/py-openssl@${PY_FLAVOR}
SOCKS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysocks>=1.5.6:net/py-pysocks@${PY_FLAVOR}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
