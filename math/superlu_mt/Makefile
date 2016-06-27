# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	superlu_mt
PORTVERSION=	2.0.20080115
PORTREVISION=	7
CATEGORIES=	math
MASTER_SITES=	http://crd.lbl.gov/~xiaoye/SuperLU/ \
		http://crd.lbl.gov/~xiaoye/:doc
DISTNAME=	${PORTNAME}_2.0
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} simax97.ps.gz:doc
DIST_SUBDIR=	superlu2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Routines for performing multithreaded sparse factorization

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

.if ${ARCH} == "sparc64"
BROKEN=		Does not link on sparc64
.endif

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/SuperLU_MT_2.0
WRKSRC_SHARED=	${WRKDIR}/SuperLU_MT_2.0_shared
ALL_TARGET=	lib
SVERSION=	1

ARCH2FIX=	CBLAS/Makefile MAKE_INC/make.openmp MAKE_INC/make.exemplar \
		MAKE_INC/make.pthreads TESTING/MATGEN/Makefile	\
		make.inc SRC/Makefile

post-patch:
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
	${RM} -rf ${WRKDIR}/tmp_static
	${MKDIR} ${WRKDIR}/tmp_static
	cd ${WRKDIR}/tmp_static
	${FIND} ${WRKSRC} -name "*\.a" -exec ${CP} {} ${WRKDIR}/tmp_static \;
	${RM} -rf ${WRKDIR}/tmp_shared
	${MKDIR} ${WRKDIR}/tmp_shared
	${FIND} ${WRKSRC_SHARED} -name "*\.a" -exec ${CP} {} ${WRKDIR}/tmp_shared \;
	@cd ${WRKDIR}/tmp_shared ; for i in `ls *.a | ${SED}  's/\.a//' `; do \
	${RM} -f $${i}.so.* $${i}.so ; \
	${FC} ${CFLAGS} ${FPIC} ${LDFLAGS} -shared -o $${i}.so.${SVERSION} \
	-Wl,-soname,$${i}.so.${SVERSION} -Wl,--allow-multiple-definition \
	-Wl,--whole-archive $${i}.a -Wl,--no-whole-archive -Wl,--as-needed; \
		${LN} -s $${i}.so.${SVERSION} $${i}.so ;\
	done

do-install:
	${INSTALL_DATA} ${WRKDIR}/tmp_static/libsuperlu_mt.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKDIR}/tmp_shared/libsuperlu_mt.so.${SVERSION} ${STAGEDIR}${PREFIX}/lib
	cd ${STAGEDIR}${PREFIX}/lib && ${LN} -s -f libsuperlu_mt.so.${SVERSION} libsuperlu_mt.so
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/SRC/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
#	${INSTALL_DATA} ${WRKSRC}/INSTALL/*.ps ${STAGEDIR}${DOCSDIR}
#	${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/*.ps
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/simax97.ps.gz ${STAGEDIR}${DOCSDIR}
.endif

regression-test: do-build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} testing)
	@(cd ${WRKSRC_SHARED} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} testing)

.include <bsd.port.post.mk>
