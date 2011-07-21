# New ports collection makefile for:	arpack
# Date created:         31 Jan 2003
# Whom:			Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	arpack
PORTVERSION=	96
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=	http://www.caam.rice.edu/software/ARPACK/SRC/
DISTFILES=	${PORTNAME}${PORTVERSION}.tar.gz patch.tar.gz
.ifndef NOPORTDOCS
DISTFILES+=	ug.ps.gz
.endif
DIST_SUBDIR=	arpack
EXTRACT_ONLY=	${PORTNAME}${PORTVERSION}.tar.gz

PATCH_SITES=	http://mathema.tician.de/news.tiker.net/files/
PATCHFILES=	arpack-arscnd-3.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Argand Library: large eigenvalue subroutines (serial version)

LDFLAGS+=	-L${LOCALBASE}/lib
USE_FORTRAN=	yes
USE_LDCONFIG=	yes
WRKSRC =	${WRKDIR}/ARPACK

BANDTESTS=	ssbdr1 ssbdr2 ssbdr3 ssbdr4 ssbdr5 ssbdr6 \
		dsbdr1 dsbdr2 dsbdr3 dsbdr4 dsbdr5 dsbdr6 \
		snbdr1 snbdr2 snbdr3 snbdr4 snbdr5 snbdr6 \
		dnbdr1 dnbdr2 dnbdr3 dnbdr4 dnbdr5 dnbdr6 \
		cnbdr1 cnbdr2 cnbdr3 cnbdr4 \
		znbdr1 znbdr2 znbdr3 znbdr4
COMPLEXTESTS=	cndrv1 cndrv2 cndrv3 cndrv4 \
		zndrv1 zndrv2 zndrv3 zndrv4
NONSYMTESTS=	sndrv1 sndrv2 sndrv3 sndrv4 sndrv5 sndrv6 \
		dndrv1 dndrv2 dndrv3 dndrv4 dndrv5 dndrv6
SIMPLETESTS=	sssimp dssimp snsimp dnsimp cnsimp znsimp
SVDTESTS=	ssvd dsvd
SYMTESTS=	ssdrv1 ssdrv2 ssdrv3 ssdrv4 ssdrv5 ssdrv6 \
		dsdrv1 dsdrv2 dsdrv3 dsdrv4 dsdrv5 dsdrv6

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

.if ${WITH_BLAS} == atlas
LIB_DEPENDS+=		atlas.2:${PORTSDIR}/math/atlas
BLAS?=			-lf77blas -latlas
.else
LIB_DEPENDS+=		blas.2:${PORTSDIR}/math/blas
BLAS?=			-lblas
.endif

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

post-extract:
	@${TAR} -C ${WRKDIR} -xzf ${_DISTDIR}/patch.tar.gz
	@${GZIP_CMD} ${WRKSRC}/DOCUMENTS/ex-*.doc

post-patch:
	@${REINPLACE_CMD} -E \
		-e '/^(home|AR|FC|LDFLAGS|MAKE|PLAT|RANLIB|SHELL)[[:space:]]+=/d' \
		-e '/^ARPACKLIB[[:space:]]+=/s/_\$$\(PLAT\)//' \
		-e '\|^BLASLIB[[:space:]]+=|s|=.*|= ${LDFLAGS} ${BLAS}|' \
		-e '/^DIRS[[:space:]]+=/s/\$$\(BLASdir\)//' \
		-e '\|^FFLAGS[[:space:]]+=|s|=.*|= ${FFLAGS} $${PICFLAG}|' \
			${WRKSRC}/ARmake.inc
	@${CP} -R ${WRKSRC} ${WRKSRC}_SHARED

do-build:
	@cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} \
		PICFLAG= home="${WRKSRC}" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}
	@cd ${WRKSRC}_SHARED ; ${SETENV} ${MAKE_ENV} \
		PICFLAG=${PICFLAG}  home="${WRKSRC}_SHARED" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET} ; \
		${LD} -Bshareable -o libarpack.so.1 -x -soname libarpack.so.1 --whole-archive libarpack.a

do-install:
	@${INSTALL_DATA} ${FILESDIR}/arpack.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/libarpack.a ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}_SHARED/libarpack.so.1 ${PREFIX}/lib
	@${LN} -sf libarpack.so.1 ${PREFIX}/lib/libarpack.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/DOCUMENTS/ex-*.doc.gz ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/ug.ps.gz ${DOCSDIR}
.endif

.if defined(MAINTAINER_MODE)
check regression-test test: simpletest
.endif

simpletest: build
	@cd ${WRKSRC}/EXAMPLES/SIMPLE ; ${SETENV} ${MAKE_ENV} \
		PICFLAG= home="${WRKSRC}" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} simple ; ${SIMPLETESTS:S|^|./|:S|$| ; |}
	@cd ${WRKSRC}_SHARED/EXAMPLES/SIMPLE ; ${SETENV} ${MAKE_ENV} \
		PICFLAG=${PICFLAG}  home="${WRKSRC}_SHARED" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} simple ; ${SIMPLETESTS:S|^|./|:S|$| ; |}

fulltest: fulltest-static fulltest-shared

fulltest-static: lapack-drivers-static
.for d in BAND COMPLEX NONSYM SVD SYM
	@cd ${WRKSRC}/EXAMPLES/${d} ; ${SETENV} ${MAKE_ENV} \
		PICFLAG= home="${WRKSRC}" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} ${${d}TESTS} ; ${${d}TESTS:S|^|./|:S|$| ; |}
.endfor

fulltest-shared: lapack-drivers-shared
.for d in BAND COMPLEX NONSYM SIMPLE SVD SYM
	@cd ${WRKSRC}_SHARED/EXAMPLES/${d} ; ${SETENV} ${MAKE_ENV} \
		PICFLAG=${PICFLAG}  home="${WRKSRC}_SHARED" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} ${${d}TESTS} ; ${${d}TESTS:S|^|./|:S|$| ; |}
.endfor

lapack-drivers-static: build
	@cd ${WRKSRC}/LAPACK ; ${SETENV} ${MAKE_ENV} \
		PICFLAG= home="${WRKSRC}" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} sdrv ddrv cdrv zdrv

lapack-drivers-shared: build
	@cd ${WRKSRC}_SHARED/LAPACK ; ${SETENV} ${MAKE_ENV} \
		PICFLAG=${PICFLAG}  home="${WRKSRC}_SHARED" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} sdrv ddrv cdrv zdrv

.include <bsd.port.post.mk>
