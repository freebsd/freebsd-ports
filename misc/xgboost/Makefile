# $FreeBSD$

PORTNAME=	xgboost
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable, Portable and Distributed Gradient Boosting (GBDT, GBRT, GBM)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_12_powerpc64=	fails to build: /usr/local/include/dmlc/serializer.h:63:16: 'Write' is not a member of 'dmlc::serializer::UndefinedSerializerFor<xgboost::DataType>'
BROKEN_FreeBSD_13_powerpc64=	fails to build: /usr/local/include/dmlc/./serializer.h:63:11: no member named 'Write' in 'dmlc::serializer::UndefinedSerializerFor<xgboost::DataType>'

LIB_DEPENDS=	libdmlc.so:devel/dmlc-core

USES=		cmake compiler:c++11-lang localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
GH_TUPLE=	\
		dmlc:rabit:4fb34a008db6437c84d1877635064e09a55c8553:dmlc_rabit/rabit \
		NVlabs:cub:c3cceac115c072fb63df1836ff46d8c60d9eb304:NVlabs_cub/cub
USE_LDCONFIG=	yes

LDFLAGS+=	${LOCALBASE}/lib/libdmlc.so -lexecinfo

OPTIONS_DEFINE=		OPENMP

OPENMP_CMAKE_BOOL=	USE_OPENMP

post-patch: # https://github.com/dmlc/rabit/issues/131
	@${FIND} ${WRKSRC} -name "*.h" -o -name "*.cc" | ${XARGS} ${REINPLACE_CMD} -i '' -e 's| _assert(| _xassert(|; s| _assert)| _xassert)|'

.include <bsd.port.mk>
