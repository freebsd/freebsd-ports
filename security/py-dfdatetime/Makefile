PORTNAME=	dfdatetime
PORTVERSION=	20240504
CATEGORIES=	security devel python
MASTER_SITES=	PYPI \
		https://github.com/log2timeline/dfdatetime/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Digital Forensics Date and Time
WWW=		https://github.com/log2timeline/dfdatetime

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD}
TEST_TARGET=	run_tests.py

NO_ARCH=	yes

.include <bsd.port.mk>
