# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	arpack++
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	http://www.ime.unicamp.br/%7echico/arpack++/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

PATCH_SITES=	http://reuter.mit.edu/blue/software/ \
		http://www.gdv.uni-hannover.de/~reuter/software/
PATCHFILES=	arpack++1.2.patch.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	bf@FreeBSD.org
COMMENT=	ARPACK++ is an object-oriented version of the ARPACK package

RUN_DEPENDS=	${LOCALBASE}/lib/libsuperlu.a:${PORTSDIR}/math/superlu
LIB_DEPENDS=	arpack.1:${PORTSDIR}/math/arpack \
		umfpack.1:${PORTSDIR}/math/suitesparse

.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas
LAPACK=		-lalapack -lcblas
.else
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS=		-lblas
LAPACK=		-llapack
.endif

USE_GCC=4.2+

NO_BUILD=	yes
REINPLACE_ARGS=	-i ""
USE_GMAKE=	yes

DOCS=		README doc/arpackpp.ps.gz doc/bugs.txt doc/structure.txt

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC}/include -name "*.orig" -delete
	@${FIND} ${WRKSRC}/examples -name "*.orig" -delete
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g"	\
		-e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/Makefile.inc
	@${FIND} ${WRKSRC}/examples -name Makefile |	\
	${XARGS} ${REINPLACE_CMD} -e "s|../../../Makefile.inc|../../Makefile.inc|" \
				-e 's|$$(ARPACKPP_DIR)/examples|${EXAMPLESDIR}|'
.endif

do-install:
	@${MKDIR} ${PREFIX}/include/ARPACK++
	@for inc in `${LS} ${WRKSRC}/include` ; do \
		${INSTALL_DATA} ${WRKSRC}/include/$$inc ${PREFIX}/include/ARPACK++; \
	done
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
	@${GUNZIP_CMD} ${DOCSDIR}/arpackpp.ps.gz
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Makefile.inc ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.if defined(MAINTAINER_MODE)
test:	install
	for sample in `${FIND} ${EXAMPLESDIR} -name Makefile` ; do \
		(cd `dirname $$sample` ; \
		${ECHO_MSG} "============" ; \
		${ECHO_MSG} "*** Entering `pwd`" ; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} \
		|| ${TRUE}) ; \
	done
	@${ECHO_MSG} "============"
	@${ECHO_MSG} "Failures expected in umfpack/complex, umfpack/nonsym & umfpack/sym"
	@${ECHO_MSG} "(UM*2FA -> umfpack_*_numeric)."
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
