PORTNAME=	mgis
PORTVERSION=	3.0.1
CATEGORIES=	science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	MFront Generic Interface Support
WWW=		https://thelfer.github.io/mgis/web/index.html

LICENSE=	LGPL3

LIB_DEPENDS=	${PY_BOOST}	\
		libTFELMFront.so.5.0.1:science/tfel-edf	\
		libboost_thread.so:devel/boost-libs
BUILD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		cmake compiler:c++20-lang fortran localbase python

#GH_ACCOUNT=	thelfer
GH_PROJECT=	MFrontGenericInterfaceSupport

TAGNAME=	c1f11c1b2b3cd7d3e4ec6ce28b13f2e74fbe97e6

OPTIONS_DEFINE=		DOCS

DOCS_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc	\
			jupyter-nbconvert:devel/py-nbconvert@${PY_FLAVOR}
DOCS_CMAKE_BOOL=	enable-website

WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_PROJECT}-${PORTVERSION}-${TAGNAME}
CMAKE_ON=	enable-c-bindings enable-fortran-bindings enable-python-bindings
CMAKE_ARGS+=	-DCOMPILER_CXXFLAGS="${CXXFLAGS}" -DCOMPILER_FLAGS="${CFLAGS}"
PLIST_SUB=	VER=${PORTVERSION}
USE_LDCONFIG=	yes

.ifdef PACKAGE_BUILDING
CMAKE_ON+=	enable-portable-build
.endif

TEST_TARGET=	check

post-stage:
	cd ${STAGEDIR}${PREFIX}/lib && ( \
		for l in `${FIND} . -type f -name "lib*.so" `; do \
			${MV} $$l $${l}.${PORTVERSION}; \
			${LN} -sf $${l}.${PORTVERSION} $${l}.${PORTVERSION:R:R}; \
			${LN} -sf $${l}.${PORTVERSION} $${l}; \
		done; \
	)

post-install:
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
