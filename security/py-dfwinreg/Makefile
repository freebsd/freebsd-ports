PORTNAME=	dfwinreg
PORTVERSION=	20240316
CATEGORIES=	security devel python
MASTER_SITES=	https://github.com/log2timeline/dfwinreg/releases/download/${PORTVERSION}/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Digital Forensics Windows Registry
WWW=		https://github.com/log2timeline/dfwinreg

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	libcreg>=e:devel/libcreg \
		libregf>=a:devel/libregf \
		${PYTHON_PKGNAMEPREFIX}dtfabric>=0:devel/py-dtfabric@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dfdatetime>=0:security/py-dfdatetime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.10:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD}
TEST_TARGET=	run_tests.py

NO_ARCH=	yes

.include <bsd.port.mk>
