# $FreeBSD$

PORTNAME=	xgboost
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
PORTREVISION=	1
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

USES=		compiler:c11 python:3.5+ localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
USE_PYTHON=	distutils autoplist
USE_LDCONFIG=	yes
GH_TUPLE=	\
		dmlc:rabit:4acdd7c6f68debe1c39ae07ca75466d74d194dd1:dmlc_rabit/../rabit

WRKSRC_SUBDIR=	python-package

LDFLAGS+=	-lexecinfo

POST_PLIST=	fix-plist

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1300060
BROKEN_i386=	undefined symbol: __atomic_load (on 11 and 12, but not on 13)
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/lib/libxgboost.so

fix-plist: # https://github.com/dmlc/xgboost/issues/5705
	@${REINPLACE_CMD} 's|/libxgboost${PYTHON_EXT_SUFFIX}.so$$|/xgboost/lib/libxgboost.so|' ${TMPPLIST}

.include <bsd.port.post.mk>
