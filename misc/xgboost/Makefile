PORTNAME=	xgboost
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable, Portable and Distributed Gradient Boosting (GBDT, GBRT, GBM)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdmlc.so:devel/dmlc-core

USES=		cmake:testing compiler:c++11-lang localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
GH_TUPLE=	\
		NVlabs:cub:af39ee2:NVlabs_cub/cub \
		rapidsai:gputreeshap:5bba198:rapidsai_gputreeshap/gputreeshap

LDFLAGS+=	${LOCALBASE}/lib/libdmlc.so -lexecinfo

CMAKE_TESTING_ON=	GOOGLE_TEST

OPTIONS_DEFINE=		OPENMP

OPENMP_CMAKE_BOOL=	USE_OPENMP

.include <bsd.port.mk>
