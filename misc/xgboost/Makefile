PORTNAME=	xgboost
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.4
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable, Portable and Distributed Gradient Boosting (GBDT, GBRT, GBM)
WWW=		https://xgboost.ai \
		https://xgboost.readthedocs.io/en/stable/ \
		https://github.com/dmlc/xgboost

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails: non-constant-expression cannot be narrowed from type 'unsigned long long' to 'size_t', see https://github.com/dmlc/xgboost/issues/8489
BROKEN_i386=	compilation fails: non-constant-expression cannot be narrowed from type 'unsigned long long' to 'size_t', see https://github.com/dmlc/xgboost/issues/8489
BROKEN_powerpc=	compilation fails: non-constant-expression cannot be narrowed from type 'unsigned long long' to 'size_t', see https://github.com/dmlc/xgboost/issues/8489

LIB_DEPENDS=	libdmlc.so:devel/dmlc-core
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
GH_TUPLE=	\
		NVlabs:cub:af39ee2:NVlabs_cub/cub \
		rapidsai:gputreeshap:acb5be3:rapidsai_gputreeshap/gputreeshap

LDFLAGS+=	${LOCALBASE}/lib/libdmlc.so -lexecinfo

CMAKE_TESTING_ON=	GOOGLE_TEST

OPTIONS_DEFINE=		OPENMP

OPENMP_CMAKE_BOOL=	USE_OPENMP

# tests as of 2.1.4: 100% tests passed, 0 tests failed out of 1 (failures when machine is loaded, see https://github.com/dmlc/xgboost/issues/11214)

.include <bsd.port.mk>
