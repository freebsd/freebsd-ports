PORTNAME=	xgboost
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.6
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable, Portable and Distributed Gradient Boosting (GBDT, GBRT, GBM)
WWW=		https://xgboost.ai/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core
LIB_DEPENDS=	libdmlc.so:devel/dmlc-core \
		libxgboost.so:misc/xgboost
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${PY_FLAVOR}

USES=		compiler:c11 python:3.5+ localbase:ldflags
USE_PYTHON=	distutils pytest # Python tests are broken because py-scikit-learn is missing the py-threadpoolctl dependency which is also currently broken
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dmlc

WRKSRC_SUBDIR=	python-package

PYDISTUTILS_INSTALLARGS=	--use-system-libxgboost # this is ignored so that setup.py has to be patched, see https://github.com/dmlc/xgboost/issues/6879

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/../tests/python

post-install:
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
