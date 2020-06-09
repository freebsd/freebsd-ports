# $FreeBSD$

PORTNAME=	xgboost
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable, Portable and Distributed Gradient Boosting (GBDT, GBRT, GBM)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS=	libdmlc.so:devel/dmlc-core \
		librabit.so:misc/xgboost
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python:3.5+ localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
USE_PYTHON=	distutils autoplist
USE_LDCONFIG=	yes
GH_TUPLE=	\
		dmlc:rabit:4fb34a008db6437c84d1877635064e09a55c8553:dmlc_rabit/../rabit

WRKSRC_SUBDIR=	python-package

MAKE_ENV+=	FREEBSD_LIBRARY_PATH=${LOCALBASE}/lib

LDFLAGS+=	-lexecinfo

POST_PLIST=	fix-plist

fix-plist: # https://github.com/dmlc/xgboost/issues/5705
	@${REINPLACE_CMD} 's|/libxgboost.so$$|/xgboost/lib/libxgboost.so|' ${TMPPLIST}

.include <bsd.port.mk>
