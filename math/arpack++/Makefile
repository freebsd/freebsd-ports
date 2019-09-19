# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	arpack++
PORTVERSION=	2.3.0
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ARPACK++ is an object-oriented version of the ARPACK package

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		libsuperlu.so:math/superlu \
		libumfpack.so:math/suitesparse

.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	libatlas.so:math/atlas
BLAS=		-lf77blas
LAPACK=		-lalapack -lcblas
.else
LIB_DEPENDS+=	liblapack.so:math/lapack
LIB_DEPENDS+=	libblas.so:math/blas
BLAS=		-lblas
LAPACK=		-llapack
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	m-reuter
GH_PROJECT=	arpackpp

USES=		fortran gmake localbase

NO_BUILD=	yes
REINPLACE_ARGS=	-i ""

DOCS=		README.md doc/README doc/arpackpp.pdf doc/structure.txt

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-configure:
	${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g"	\
		-e "s|%%BLAS%%|${BLAS}|"			\
		-e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/Makefile.inc
	${FIND} ${WRKSRC}/examples -name Makefile |	\
	${XARGS} ${REINPLACE_CMD} -e 's|$$(ARPACKPP_DIR)/examples|${EXAMPLESDIR}|'

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/ARPACK++
	for inc in `${LS} ${WRKSRC}/include` ; do \
		${INSTALL_DATA} ${WRKSRC}/include/$$inc ${STAGEDIR}${PREFIX}/include/ARPACK++; \
	done
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Makefile.inc ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."

.if defined(MAINTAINER_MODE)
test:	install
	for sample in `${FIND} ${WRKSRC}/examples -name Makefile` ; do \
		(cd `dirname $$sample` ; \
		${ECHO_MSG} "============" ; \
		${ECHO_MSG} "*** Entering `pwd`" ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} \
		|| ${TRUE}) ; \
	done
	@${ECHO_MSG} "============"
	@${ECHO_MSG} "Failures expected in umfpack/complex, umfpack/nonsym & umfpack/sym"
	@${ECHO_MSG} "(UM*2FA -> umfpack_*_numeric)."
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
