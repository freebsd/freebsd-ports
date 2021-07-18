PORTNAME=	xgboost
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable, Portable and Distributed Gradient Boosting (GBDT, GBRT, GBM)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS=	libdmlc.so:devel/dmlc-core \
		libxgboost.so:misc/xgboost
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \

USES=		compiler:c11 python:3.5+ localbase:ldflags
USE_PYTHON=	distutils autoplist
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dmlc

WRKSRC_SUBDIR=	python-package

PYDISTUTILS_INSTALLARGS=	--use-system-libxgboost # this is ignored so that setup.py has to be patched, see https://github.com/dmlc/xgboost/issues/6879

NO_ARCH=	yes

POST_PLIST=	fix-plist

fix-plist: # https://github.com/dmlc/xgboost/issues/5705
	@${REINPLACE_CMD} 's|.*libxgboost${PYTHON_EXT_SUFFIX}.so$$||' ${TMPPLIST}

do-test: # tests fail w/out CUDA: https://github.com/dmlc/xgboost/issues/6881
	@cd ${WRKSRC}/.. && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
