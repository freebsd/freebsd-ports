PORTNAME=	flashlight
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0-16
DISTVERSIONSUFFIX=	-gafcd364e
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Standalone C++ library for machine learning
WWW=		https://github.com/flashlight/flashlight

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cereal>0:devel/cereal
LIB_DEPENDS=	libdnnl.so:math/onednn252

USES=		cmake:testing compiler:c++17-lang localbase pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_OFF=	FL_USE_ARRAYFIRE \
		FL_BUILD_TESTS FL_BUILD_EXAMPLES
CMAKE_OFF+=	FL_BUILD_DISTRIBUTED # need to add MPI options
CMAKE_ON=	BUILD_SHARED_LIBS \
		FL_USE_CPU
CMAKE_ON+=	FL_USE_ONEDNN # needs to have oneDNN enabled because it needs a working tensor backend

post-patch: # workaround for https://github.com/flashlight/flashlight/issues/1086
	@${RM} ${WRKSRC}/cmake/Findcereal.cmake

.include <bsd.port.mk>
