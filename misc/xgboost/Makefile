PORTNAME=	xgboost
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
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
		NVlabs:cub:af39ee2:NVlabs_cub/cub \
		rapidsai:gputreeshap:3310a30:rapidsai_gputreeshap/gputreeshap

LDFLAGS+=	${LOCALBASE}/lib/libdmlc.so -lexecinfo

OPTIONS_DEFINE=		OPENMP

OPENMP_CMAKE_BOOL=	USE_OPENMP

.include <bsd.port.mk>
