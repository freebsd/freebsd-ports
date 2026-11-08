PORTNAME=	xgboost
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.2
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

LDFLAGS+=	${LOCALBASE}/lib/libdmlc.so -lexecinfo

CMAKE_ARGS+=	-DBUILD_WITH_SYSTEM_DMLC=ON

CMAKE_TESTING_ON=	GOOGLE_TEST

OPTIONS_DEFINE=		OPENMP

OPENMP_CMAKE_BOOL=	USE_OPENMP

# tests as of 3.4.2: 100% tests passed out of 1

.include <bsd.port.mk>
