# Based on the graphics/ilmbase port that was done by: nork@FreeBSD.org

PORTNAME=	Imath
PORTVERSION=	3.2.0
CATEGORIES=	math devel graphics
MASTER_SITES=	https://github.com/AcademySoftwareFoundation/${PORTNAME}/releases/download/v${PORTVERSION}/ \
		LOCAL/mandree/
# to verify: 'make makesum' and download .sigstore.json to working directory, then:
# sigstore verify github --cert-identity \
# https://github.com/AcademySoftwareFoundation/Imath/.github/workflows/release-sign.yml@refs/tags/v3.2.0 \
# /usr/ports/distfiles/Imath-3.2.0.tar.gz --bundle Imath-3.2.0.tar.gz.sigstore.json

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	C++/Python lib of 2D/3D vector, matrix, math ops for computer graphics
WWW=		https://github.com/AcademySoftwareFoundation/Imath/

LICENSE=	BSD3CLAUSE

USES=		cmake compiler:c++14-lang pathfix pkgconfig

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_DEBUG_POSTFIX= \
		-DCMAKE_INSTALL_PREFIX=${PREFIX}

PATCH_STRIP=	-p1

PLIST_SUB=	MAJORVER=${_MAJORVER} \
		MINVER=${_MINVER} \
		PLVER=${_PLVER} \
		VER=${_VER} \
		PYVER=${PYTHON_VER:S/./_/}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS LARGE_STACK PYTHON
OPTIONS_SUB=	yes

LARGE_STACK_DESC=	Enable sys-dependent large stack optimizations
LARGE_STACK_CMAKE_BOOL=	IMATH_ENABLE_LARGE_STACK

PYTHON_BUILD_DEPENDS=	${PYNUMPY}
PYTHON_LIB_DEPENDS=	${PY_BOOST}
PYTHON_RUN_DEPENDS=	${PYNUMPY}
PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	PYTHON

_MAJORVER=	3_2
_VER=		30
_MINVER=	3
_PLVER=		2.0

post-install:
.for l in libImath
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${l}-${_MAJORVER}.so
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${BUILD_WRKSRC} && ctest -j ${MAKE_JOBS_NUMBER}

.include <bsd.port.mk>
