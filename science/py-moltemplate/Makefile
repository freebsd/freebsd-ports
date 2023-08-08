PORTNAME=	moltemplate
DISTVERSIONPREFIX=	v
DISTVERSION=	2.20.20
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool to prepare simulations of molecules, complex molecular assemblies
WWW=		https://www.moltemplate.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		bash:shells/bash
TEST_DEPENDS=	shunit2>0:devel/shunit2

USES=		python shebangfix
USE_PYTHON=	distutils concurrent autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	jewettaij

SHEBANG_FILES=	moltemplate/scripts/molc.sh #shunit2/shunit2

NO_ARCH=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} PATH=${STAGEDIR}${LOCALBASE}/bin:${PATH}

do-test: # testsuite instructions: https://github.com/jewettaij/moltemplate/issues/65#issuecomment-1022740972
	@cd ${WRKSRC} && \
		([ -e shunit2 ] || (${MKDIR} tests/shunit2 && ${RM} tests/shunit2/shunit2 && ${LN} -s ${LOCALBASE}/bin/shunit2 tests/shunit2/shunit2)) && \
		${SETENV} ${TEST_ENV} bash tests/test_read_coords_pdb.sh && \
		${SETENV} ${TEST_ENV} bash tests/test_ltemplify.sh && \
		${SETENV} ${TEST_ENV} bash tests/test_oplsaa.sh && \
		${SETENV} ${TEST_ENV} bash tests/test_compass.sh && \
		${SETENV} ${TEST_ENV} python3 tests/test_genpoly_lt.py

.include <bsd.port.mk>
