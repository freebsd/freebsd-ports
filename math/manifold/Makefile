PORTNAME=	manifold
DISTVERSIONPREFIX=v
DISTVERSION=	3.0.1
PORTREVISION=	2
CATEGORIES=	math cad

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Geometry library for topological robustness
WWW=		https://github.com/elalish/manifold

LICENSE=	APACHE20

BUILD_DEPENDS=	glm>0:math/glm	\
		googletest>0:devel/googletest
LIB_DEPENDS=	libtbb.so:devel/onetbb	\
		libClipper2.so:cad/Clipper2	\
		libassimp.so:multimedia/assimp

USES=		cmake compiler:c++17-lang pathfix

USE_GITHUB=	yes
GH_ACCOUNT=	elalish

CMAKE_ARGS=	-DMANIFOLD_FLAGS="${CFLAGS}"	\
		-DMANIFOLD_PAR:STRING="NONE"
CMAKE_ON=	BUILD_SHARED_LIBS	\
		MANIFOLD_EXPORT		\
		MANIFOLD_TEST
CMAKE_OFF=	MANIFOLD_DOWNLOADS		\
		MANIFOLD_JSBIND			\
		MANIFOLD_CBIND			\
		MANIFOLD_PYBIND			\
		MANIFOLD_FUZZ			\
		TRACY_ENABLE

USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

pre-configure:
.if ${ARCH} == "i386" || ${ARCH} == "armv7"
	${REINPLACE_CMD} -e 's|-Werror|-Wno-format|' ${WRKSRC}/CMakeLists.txt
.endif

do-test:
	(cd ${BUILD_WRKSRC}/test && ./manifold_test)

.include <bsd.port.mk>
