PORTNAME=	manifold
DISTVERSION=	3.3.2
CATEGORIES=	math cad graphics
MASTER_SITES=	https://github.com/elalish/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Geometry library for topological robustness
WWW=		https://github.com/elalish/manifold

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang
USE_LDCONFIG=	yes

EXTRACT_AFTER_ARGS=	--exclude ${PORTNAME}-${DISTVERSION}/samples \
			--no-same-owner --no-same-permissions
.if make(test)
EXTRACT_AFTER_ARGS=	--include ${PORTNAME}-${DISTVERSION}/samples \
			--no-same-owner --no-same-permissions
.endif

PLIST_SUB+=	VERS=${DISTVERSION}

CMAKE_TESTING_ON=	MANIFOLD_TEST

CMAKE_OFF=	MANIFOLD_DOWNLOADS \
		MANIFOLD_FUZZ \
		MANIFOLD_JSBIND \
		MANIFOLD_TEST \
		TRACY_ENABLE
CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=		CBIND CROSS PARA PYBIND TEST_EXPORT
OPTIONS_DEFAULT=	CBIND CROSS PARA
OPTIONS_SUB=		yes

CBIND_DESC=		Enable C FFI binding
CROSS_DESC=		Enable CrossSection for 2D support
PARA_DESC=		Enable multi-thread parallelization
PYBIND_DESC=		Enable python binding
TEST_EXPORT_DESC=	Enable export of models from tests

CBIND_IMPLIES=		CROSS
CBIND_CMAKE_BOOL=	MANIFOLD_CBIND

CROSS_LIB_DEPENDS=	libClipper2.so:cad/Clipper2
CROSS_CMAKE_BOOL=	MANIFOLD_CROSS_SECTION

PARA_LIB_DEPENDS=	libtbb.so:devel/onetbb
PARA_CMAKE_BOOL=	MANIFOLD_PAR

PYBIND_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nanobind>0:devel/py-nanobind@${PY_FLAVOR}
PYBIND_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nanobind>0:devel/py-nanobind@${PY_FLAVOR}
PYBIND_USES=		python
PYBIND_CMAKE_BOOL=	MANIFOLD_PYBIND
PYBIND_IMPLIES=		CROSS

TEST_EXPORT_LIB_DEPENDS=libassimp.so:multimedia/assimp
TEST_EXPORT_CMAKE_BOOL=	MANIFOLD_EXPORT

pre-test:
	@if [ ! -d ${WRKDIR}/samples ]; then \
		(${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTFILES} -C ${EXTRACT_WRKDIR} ${EXTRACT_AFTER_ARGS}) ;\
	fi

.include <bsd.port.mk>
