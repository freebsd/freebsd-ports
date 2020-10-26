# $FreeBSD$

PORTNAME=	xgboost
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable, Portable and Distributed Gradient Boosting (GBDT, GBRT, GBM)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdmlc.so:devel/dmlc-core

USES=		cmake compiler:c++11-lang localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
GH_TUPLE=	\
		dmlc:rabit:4fb34a008db6437c84d1877635064e09a55c8553:dmlc_rabit/rabit \
		rapidsai:gputreeshap:5f33132d75482338f78cfba562791d8445e157f6:rapidsai_gputreeshap/gputreeshap \
		NVlabs:cub:c3cceac115c072fb63df1836ff46d8c60d9eb304:NVlabs_cub/cub

LDFLAGS+=	${LOCALBASE}/lib/libdmlc.so -lexecinfo

OPTIONS_DEFINE=		OPENMP

OPENMP_CMAKE_BOOL=	USE_OPENMP

post-patch: # https://github.com/dmlc/rabit/issues/131
	@${FIND} ${WRKSRC} -name "*.h" -o -name "*.cc" | ${XARGS} ${REINPLACE_CMD} -i '' -e 's| _assert(| _xassert(|; s| _assert)| _xassert)|'

.include <bsd.port.mk>
