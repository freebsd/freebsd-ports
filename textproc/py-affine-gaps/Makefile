PORTNAME=	affine-gaps
DISTVERSION=	0.2.4
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	affine_gaps-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	JIT-compiled string edit-distances
WWW=		https://github.com/ashvardanian/affine-gaps

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>0:devel/py-numba@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-repeat>0:devel/py-pytest-repeat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stringzilla>0:devel/py-stringzilla@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_repeat

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest test.py

# tests as of 0.2.4: 13992 passed

.include <bsd.port.mk>
