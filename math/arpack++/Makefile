PORTNAME=	arpack++
PORTVERSION=	2.4.0
PORTREVISION=	13
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-oriented version of the ARPACK package
WWW=		https://www.ime.unicamp.br/~chico/arpack++/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		libsuperlu.so:math/superlu \
		libcholmod.so:math/suitesparse-cholmod \
		libumfpack.so:math/suitesparse-umfpack

USES=		cmake:testing compiler:c++17-lang fortran
USE_CXXSTD=	c++17

USE_GITHUB=	yes
GH_ACCOUNT=	m-reuter
GH_PROJECT=	arpackpp

CMAKE_ARGS=	-DENABLE_FORTRAN:BOOL=ON	\
		-DENABLE_SUPERLU:BOOL=ON	\
		-DENABLE_UMFPACK:BOOL=ON	\
		-DENABLE_CHOLMOD:BOOL=ON	\
		-DENABLE_SUITESPARSE_STATIC:BOOL=OFF

NO_ARCH=	yes

REINPLACE_ARGS=	-i ""

DOCS=		README.md doc/README doc/arpackpp.pdf doc/structure.txt

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_RADIO=		BLAS
OPTIONS_RADIO_BLAS=	ATLAS NETLIB OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS

EXAMPLES_CMAKE_ON=	-DENABLE_TESTS:BOOL=ON
EXAMPLES_CMAKE_OFF=	-DENABLE_TESTS:BOOL=OFF
EXAMPLES_VARS_OFF=	NO_BUILD=yes

ATLAS_USES=	blaslapack:atlas
NETLIB_USES=	blaslapack:netlib
OPENBLAS_USES=	blaslapack:openblas

PORTDOCS=	*
PORTEXAMPLES=	*

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."

.include <bsd.port.mk>
