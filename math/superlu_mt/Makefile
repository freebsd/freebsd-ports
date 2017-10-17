# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	superlu_mt
PORTVERSION=	3.1.20160319
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://crd.lbl.gov/~xiaoye/SuperLU/ \
		http://crd.lbl.gov/~xiaoye/:doc
DISTNAME=	${PORTNAME}_3.1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} simax97.ps.gz:doc
DIST_SUBDIR=	superlu2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Routines for performing multithreaded sparse factorization

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

BROKEN_aarch64=		fails to build: undefined reference to sbrk
BROKEN_sparc64=		Does not link on sparc64

USES=		fortran gmake

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libgoto2.so)
WITH_BLAS?=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

.if ${WITH_BLAS} == reference
LIB_DEPENDS+=	libblas.so:math/blas
BLAS=	-lblas
.elif ${WITH_BLAS} == gotoblas
LIB_DEPENDS+=	libgoto2.so:math/gotoblas
BLAS=	-lgoto2p
BROKEN=	Build stops while testing
.elif ${WITH_BLAS} == atlas
LIB_DEPENDS+=	libatlas.so:math/atlas
BLAS=	-lptf77blas
.endif

.if ${ARCH} == "sparc64" || ${ARCH} == "amd64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/SuperLU_MT_3.1
WRKSRC_SHARED=	${WRKDIR}/SuperLU_MT_3.1_shared
ALL_TARGET=	lib
SVERSION=	3

ARCH2FIX=	CBLAS/Makefile MAKE_INC/make.openmp MAKE_INC/make.exemplar \
		make.inc SRC/Makefile TESTING/MATGEN/Makefile

do-configure:
.for fmk in ${ARCH2FIX}
	@${REINPLACE_CMD} -e 's|^ARCH *.= ar|ARCMD = ar| ; \
		s|\$$(ARCH)|$$(ARCMD)|' ${WRKSRC}/${fmk}
.endfor
	${CP} -r ${WRKSRC} ${WRKSRC_SHARED}
	@${REINPLACE_CMD} -e 's+%%BLAS%%+-L${LOCALBASE}/lib ${BLAS}+ ; \
			s+%%CC%%+${CC}+; s+%%FC%%+${FC}+; \
			s+%%CPPFLAGS%%+${CPPFLAGS}+; \
			s+%%CFLAGS%%+${CFLAGS}+; \
			s+%%FFLAGS%%+${FFLAGS}+; \
			s+%%LDFLAGS%%+${LDFLAGS}+; \
			s+%%FPIC%%++ ' \
		${WRKSRC}/make.inc

	@${REINPLACE_CMD} -e 's+%%BLAS%%+-L${LOCALBASE}/lib ${BLAS}+ ; \
			s+%%CC%%+${CC}+; s+%%FC%%+${FC}+; \
			s+%%CPPFLAGS%%+${CPPFLAGS}+; \
			s+%%CFLAGS%%+${CFLAGS} ${FPIC}+; \
			s+%%FFLAGS%%+${FFLAGS} ${FPIC}+; \
			s+%%LDFLAGS%%+${LDFLAGS}+; \
			s+%%FPIC%%+${FPIC}+ ' \
		${WRKSRC_SHARED}/make.inc

do-build:
	cd ${WRKSRC} ; ${MAKE_CMD} LDFLAGS="${LDFLAGS}"
	cd ${WRKSRC_SHARED} ; ${MAKE_CMD} LDFLAGS="${LDFLAGS}"
	${RM} -r ${WRKDIR}/tmp_static
	${MKDIR} ${WRKDIR}/tmp_static
	cd ${WRKDIR}/tmp_static
	${FIND} ${WRKSRC} -name "*\.a" -exec ${CP} {} ${WRKDIR}/tmp_static \;
	${RM} -r ${WRKDIR}/tmp_shared
	${MKDIR} ${WRKDIR}/tmp_shared
	${FIND} ${WRKSRC_SHARED} -name "*\.a" -exec ${CP} {} ${WRKDIR}/tmp_shared \;
	@cd ${WRKDIR}/tmp_shared ; for i in `ls *.a | ${SED}  's/\.a//' `; do \
	${RM} $${i}.so.* $${i}.so ; \
	${FC} ${CFLAGS} ${FPIC} ${LDFLAGS} -shared -o $${i}.so.${SVERSION} \
	-Wl,-soname,$${i}.so.${SVERSION} -Wl,--allow-multiple-definition \
	-Wl,--whole-archive $${i}.a -Wl,--no-whole-archive -Wl,--as-needed; \
		${LN} -s $${i}.so.${SVERSION} $${i}.so ;\
	done

do-install:
	${INSTALL_DATA} ${WRKDIR}/tmp_static/libsuperlu_mt_*.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKDIR}/tmp_shared/libsuperlu_mt_*.so.${SVERSION} ${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/libsuperlu_mt_PTHREAD.so.${SVERSION} \
		${STAGEDIR}${PREFIX}/lib/libsuperlu_mt_PTHREAD.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/libsuperlu_mt_PTHREAD.so.${SVERSION} \
		${STAGEDIR}${PREFIX}/lib/libsuperlu_mt.so
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/SRC/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOC/*.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/simax97.ps.gz ${STAGEDIR}${DOCSDIR}
.endif

.ifdef MAINTAINER_MODE
regression-test: do-build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} testing)
	@(cd ${WRKSRC_SHARED} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} testing)
.endif

.include <bsd.port.post.mk>
