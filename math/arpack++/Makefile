# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	arpack++
PORTVERSION=	1.2
PORTREVISION=	11
CATEGORIES=	math
MASTER_SITES=	http://www.ime.unicamp.br/%7echico/arpack++/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

PATCH_SITES=	http://reuter.mit.edu/blue/software/ \
		http://www.gdv.uni-hannover.de/~reuter/software/
PATCHFILES=	arpack++1.2.patch.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ARPACK++ is an object-oriented version of the ARPACK package

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

NO_BUILD=	yes
REINPLACE_ARGS=	-i ""
USES=		gmake

DOCS=		README doc/arpackpp.ps.gz doc/bugs.txt doc/structure.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC}/include -name "*.orig" -delete
	@${FIND} ${WRKSRC}/examples -name "*.orig" -delete
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g"	\
		-e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/Makefile.inc
	@${FIND} ${WRKSRC}/examples -name Makefile |	\
	${XARGS} ${REINPLACE_CMD} -e "s|../../../Makefile.inc|../../Makefile.inc|" \
				-e 's|$$(ARPACKPP_DIR)/examples|${EXAMPLESDIR}|'

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/ARPACK++
	@for inc in `${LS} ${WRKSRC}/include` ; do \
		${INSTALL_DATA} ${WRKSRC}/include/$$inc ${STAGEDIR}${PREFIX}/include/ARPACK++; \
	done
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
	@${GUNZIP_CMD} ${STAGEDIR}${DOCSDIR}/arpackpp.ps.gz
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Makefile.inc ${STAGEDIR}${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."

.if defined(MAINTAINER_MODE)
test:	install
	for sample in `${FIND} ${EXAMPLESDIR} -name Makefile` ; do \
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
