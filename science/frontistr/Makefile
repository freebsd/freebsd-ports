# Created by: Thierry Thomas <thierry@pompo.net>

PORTNAME=	FrontISTR
PORTVERSION=	5.2
DISTVERSIONPREFIX=	v
CATEGORIES=	science cad

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Large-Scale Parallel FEM Program for Nonlinear Structural Analysis

LICENSE=	MIT

LIB_DEPENDS=	libmetis.so:math/metis		\
		libscotch.so:cad/scotch		\
		libcmumps.so.5:math/mumps	\
		libscalapack.so:math/scalapack
TEST_DEPENDS=	bash:shells/bash	\
		gawk:lang/gawk

USE_GITLAB=	yes
GL_ACCOUNT=	${PORTNAME}-Commons
GL_COMMIT=	c66bdc397de319ca59a0565b3f3b1a3b33f0c50c

USES=		blaslapack:openblas cmake:testing fortran mpi shebangfix
SHEBANG_GLOB=	*.sh
FFLAGS+=	-fallow-argument-mismatch
ALL_TARGET=	all

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_USES=		python:build
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen	\
			dot:graphics/graphviz	\
			${PYTHON_PKGNAMEPREFIX}mkdocs>0:textproc/py-mkdocs@${PY_FLAVOR}
DOCS_CMAKE_BOOL=	WITH_DOC
DOCS_ALL_TARGET=	doc

PORTDOCS=	*
PORTEXAMPLES=	*

pre-configure:
	${REINPLACE_CMD} -e 's/awk/gawk/' ${WRKSRC}/tests/test.sh

do-install-DOCS-on:
	${FIND} ${BUILD_WRKSRC}/doc/html -type d -empty -delete
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${BUILD_WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

do-test:
	(cd ${TEST_WRKSRC} && ctest)

.include <bsd.port.mk>
