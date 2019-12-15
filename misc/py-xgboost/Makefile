# $FreeBSD$

PORTNAME=	xgboost
DISTVERSIONPREFIX=	v
DISTVERSION=	0.90-235
DISTVERSIONSUFFIX=	-gad4a1c73
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable, Portable and Distributed Gradient Boosting (GBDT, GBRT, GBM)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libdmlc.so:devel/dmlc-core \
		librabit.so:misc/xgboost
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
USE_PYTHON=	distutils autoplist
USE_LDCONFIG=	yes

WRKSRC_SUBDIR=	python-package

MAKE_ENV+=	FREEBSD_LIBRARY_PATH=${LOCALBASE}/lib

NO_ARCH=	yes

POST_PLIST=	fix-plist

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/xgboost/libxgboost.so
	@${RMDIR} ${STAGEDIR}${PREFIX}/xgboost

fix-plist: # https://github.com/dmlc/xgboost/issues/5118
	@${REINPLACE_CMD} '/^xgboost\/libxgboost.so$$/d' ${TMPPLIST}

.include <bsd.port.mk>
