# Based on the graphics/ilmbase port that was done by: nork@FreeBSD.org

PORTNAME=	Imath
PORTVERSION=	3.0.1
CATEGORIES=	math devel graphics

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	C++/Python lib of 2D/3D vector, matrix, math ops for computer graphics

LICENSE=	BSD3CLAUSE

USES=		cmake compiler:c++14-lang pkgconfig

USE_GITHUB=	yes
GH_TUPLE=	AcademySoftwareFoundation:Imath:v${PORTVERSION}
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_DEBUG_POSTFIX= \
		-DCMAKE_INSTALL_PREFIX=${PREFIX}

PLIST_SUB=	MAJORVER=${_MAJORVER} \
		MINVER=${_MINVER} \
		PLVER=${_PLVER} \
		VER=${_VER}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS LARGE_STACK PYTHON
OPTIONS_SUB=	yes

LARGE_STACK_DESC=	Enable sys-dependent large stack optimizations
LARGE_STACK_CMAKE_BOOL=	IMATH_ENABLE_LARGE_STACK

PYTHON_LIB_DEPENDS=	${PY_BOOST}
PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	PYTHON

_MAJORVER=	3_0
_VER=		27
_MINVER=	0
_PLVER=		0

post-install:
.for l in libImath
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${l}-${_MAJORVER}.so
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${BUILD_WRKSRC} && ctest

.include <bsd.port.mk>
