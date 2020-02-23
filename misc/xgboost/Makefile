# $FreeBSD$

PORTNAME=	xgboost
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable, Portable and Distributed Gradient Boosting (GBDT, GBRT, GBM)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdmlc.so:devel/dmlc-core

USES=		cmake compiler:c++11-lang localbase
USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
GH_TUPLE=	dmlc:rabit:2f25347:rabit/rabit \
		NVlabs:cub:b20808b:cub/cub
USE_LDCONFIG=	yes

LDFLAGS+=	${LOCALBASE}/lib/libdmlc.so -lexecinfo

OPTIONS_DEFINE=		OPENMP

OPENMP_CMAKE_BOOL=	USE_OPENMP
OPENMP_LIB_DEPENDS=	libomp.so:devel/openmp
OPENMP_BROKEN=		error: unsupported argument 'libomp  -I/usr/local/include -L/usr/local/lib' to option 'fopenmp='

post-patch: # https://github.com/dmlc/rabit/issues/131
	@${FIND} ${WRKSRC} -name "*.h" -o -name "*.cc" | ${XARGS} ${REINPLACE_CMD} -i '' -e 's| _assert(| _xassert(|; s| _assert)| _xassert)|'

.include <bsd.port.mk>
