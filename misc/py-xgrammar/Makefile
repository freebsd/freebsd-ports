PORTNAME=	xgrammar
DISTVERSION=	0.1.33
PORTREVISION=	1
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Efficient, flexible and portable structured generation
WWW=		https://xgrammar.mlc.ai/ \
		https://github.com/mlc-ai/xgrammar

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.10.0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nanobind>=2.5.0:devel/py-nanobind@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=1.10.0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=4.38.0:misc/py-transformers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.9.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		cmake:indirect python pytest
USE_PYTHON=	pep517 autoplist

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

# tests as of 0.1.33: 260 failed, 971 passed, 57 skipped, 9 warnings, 1098 errors in 538.64s (0:08:58)
# ... many failures are due to unauthorized access to gated HF models, which is expected and not a problem for the port, see https://github.com/mlc-ai/xgrammar/issues/584

.include <bsd.port.mk>
