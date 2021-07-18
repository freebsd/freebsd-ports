# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	eccodes
PORTVERSION=	1.3.3
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to the ecCodes BUFR and GRIB de/encoder

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libeccodes.so:science/eccodes
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}findlibs>=0:devel/py-findlibs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1<1.20,1:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flakes>=0:devel/py-pytest-flakes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

do-test:
	cd ${WRKSRC} && ${SETENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
