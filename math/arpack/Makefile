# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	arpack
PORTVERSION=	96
PORTREVISION=	13
CATEGORIES=	math
MASTER_SITES=	http://www.caam.rice.edu/software/ARPACK/SRC/
DISTFILES=	${PORTNAME}${PORTVERSION}.tar.gz patch.tar.gz
DIST_SUBDIR=	arpack
EXTRACT_ONLY=	${PORTNAME}${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Argand Library: large eigenvalue subroutines (serial version)

BUILD_DEPENDS=	tradcpp:devel/tradcpp

CONFLICTS=	arpack-ng-[0-9]*
CPP=		tradcpp
FFLAGS+=	-ffixed-line-length-none
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes
USES=		fortran
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/ARPACK

# The following lapack symbols in arpack are renamed to avoid conflicts with other
# lapack libraries:
RENAMED_SYMBOLS=	cgbtf2 cgbtrf cgbtrs cgeqr2 cgttrf cgttrs clacgv \
			clacon clacpy cladiv clahqr clange clanhs clarf \
			clarfg clarnv clartg clascl claset classq claswp \
			clatrs cmach crot ctrevc ctrexc ctrsen ctrsyl cunm2r \
			dgbtf2 dgbtrf dgbtrs dgeqr2 dgttrf dgttrs dlabad \
			dlacon dlacpy dladiv dlae2 dlaev2 dlaexc dlagtm \
			dlahqr dlaln2 dlamc1 dlamc2 dlamc3 dlamc4 dlamc5 \
			dlamch dlange dlanhs dlanst dlanv2 dlaptm dlapy2 \
			dlapy3 dlaran dlarf dlarfg dlarfx dlarnd dlarnv \
			dlartg dlaruv dlascl dlaset dlasr dlasrt dlassq \
			dlaswp dlasy2 dorm2r dpttrf dpttrs dsteqr dtrevc \
			dtrexc dtrsen dtrsyl dzsum1 icmax1 ilaenv izmax1 \
			lsame lsamen scsum1 second sgbtf2 sgbtrf sgbtrs \
			sgeqr2 sgttrf sgttrs slabad slacon slacpy sladiv \
			slae2 slaev2 slaexc slagtm slahqr slaln2 slamc1 \
			slamc2 slamc3 slamc4 slamc5 slamch slange slanhs \
			slanst slanv2 slaptm slapy2 slapy3 slaran slarf \
			slarfg slarfx slarnd slarnv slartg slaruv slascl \
			slaset slasr slasrt slassq slaswp slasy2 sorm2r \
			spttrf spttrs ssteqr strevc strexc strsen strsyl \
			xerbla xlaenv zgbtf2 zgbtrf zgbtrs zgeqr2 zgttrf \
			zgttrs zlacgv zlacon zlacpy zladiv zlahqr zlange \
			zlanhs zlarf zlarfg zlarnv zlartg zlascl zlaset \
			zlassq zlaswp zlatrs zmach zrot ztrevc ztrexc ztrsen \
			ztrsyl zunm2r

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

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	ug.ps.gz
.endif

.if exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

.if ${WITH_BLAS} == atlas
LIB_DEPENDS+=		libatlas.so:math/atlas
BLAS?=			-lf77blas
.else
LIB_DEPENDS+=		libblas.so:math/blas
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
		-e '/^(home|AR|FC|LDFLAGS|MAKE|PLAT|RANLIB|SHELL)[[:blank:]]+=/d' \
		-e '/^ARPACKLIB[[:blank:]]+=/s/_\$$\(PLAT\)//' \
		-e '\|^BLASLIB[[:blank:]]+=|s|=.*|= ${LDFLAGS} ${BLAS}|' \
		-e '/^DIRS[[:blank:]]+=/s/\$$\(BLASdir\)//' \
		-e '\|^FFLAGS[[:blank:]]+=|s|=.*|= ${FFLAGS} $${PICFLAG}|' \
			${WRKSRC}/ARmake.inc
	@${CP} -R ${WRKSRC} ${WRKSRC}_SHARED
	@${ECHO_CMD} ${RENAMED_SYMBOLS} | ${AWK} \
		'BEGIN { printf "%s\n\n%s\t%s\n%s\t%s\n\n", \
			"/* arpack symbol renaming preprocessor macros, C interface */", \
			"#ifndef", "_ARPACK_COMPAT_C_H_", \
			"#define", "_ARPACK_COMPAT_C_H_" \
			> "${WRKDIR}/arpack_compat_c.h" ; \
			printf "%s\n\n%s\t%s\n%s\t%s\n\n", \
			"/* arpack symbol renaming preprocessor macros, FORTRAN interface */", \
			"#ifndef", "_ARPACK_COMPAT_F_H_", \
			"#define", "_ARPACK_COMPAT_F_H_" \
			> "${WRKDIR}/arpack_compat_f.h" } ; \
		{ for (i = 1; i <= NF; i++) { \
			printf  "%s\t%s%s\t%s%s%s\n", "#define", $$i, "_", \
			"arpack_", $$i, "_" > "${WRKDIR}/arpack_compat_c.h" ; \
			printf  "%s\t%s\t%s%s\n%s\t%s\t%s%s\n", "#define", \
			toupper($$i), "ARPACK_", toupper($$i), "#define", $$i, \
			"ARPACK_", toupper($$i) \
			> "${WRKDIR}/arpack_compat_f.h" } } ; \
		END { print "\n#endif" >  "${WRKDIR}/arpack_compat_c.h" ; \
		print "\n#endif" >  "${WRKDIR}/arpack_compat_f.h" }' -

pre-build:
	@${ECHO_CMD} "Renaming LAPACK functions ..."
	@for f in `${FIND} ${WRKDIR} -type f -mindepth 2 -name '*.f'` ; do \
		${MV} $${f} $${f}.unproc ; \
		${CPP} -C -I${WRKDIR} -imacros arpack_compat_f.h \
			$${f}.unproc $${f} ; done

do-build:
	@cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} \
		PICFLAG= home="${WRKSRC}" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}
	@cd ${WRKSRC}_SHARED ; ${SETENV} ${MAKE_ENV} \
		PICFLAG=${PICFLAG}  home="${WRKSRC}_SHARED" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET} ; \
		${FC} ${FFLAGS} ${PICFLAG} ${LDFLAGS} -shared \
		-o libarpack.so.1 -Wl,-x -Wl,-soname,libarpack.so.1 \
		-Wl,--whole-archive libarpack.a -Wl,--no-whole-archive

do-install:
	@${INSTALL_DATA} ${FILESDIR}/arpack.h ${WRKDIR}/arpack_compat_c.h \
		${WRKDIR}/arpack_compat_f.h ${STAGEDIR}${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/libarpack.a ${STAGEDIR}${PREFIX}/lib
	@${INSTALL_DATA} -s ${WRKSRC}_SHARED/libarpack.so.1 ${STAGEDIR}${PREFIX}/lib
	@${LN} -sf libarpack.so.1 ${STAGEDIR}${PREFIX}/lib/libarpack.so
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/DOCUMENTS/ex-*.doc.gz ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/ug.ps.gz ${STAGEDIR}${DOCSDIR}
.endif

.if defined(MAINTAINER_MODE)
check regression-test test: simpletest
.endif

simpletest: build
	@cd ${WRKSRC}/EXAMPLES/SIMPLE ; ${SETENV} ${MAKE_ENV} \
		PICFLAG= home="${WRKSRC}" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} simple ; \
		${SIMPLETESTS:S|^|./|:S|$| ; |}
	@cd ${WRKSRC}_SHARED/EXAMPLES/SIMPLE ; ${SETENV} ${MAKE_ENV} \
		PICFLAG=${PICFLAG}  home="${WRKSRC}_SHARED" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} simple ; \
		${SIMPLETESTS:S|^|./|:S|$| ; |}

fulltest: fulltest-static fulltest-shared

fulltest-static: lapack-drivers-static
.for d in BAND COMPLEX NONSYM SVD SYM
	@cd ${WRKSRC}/EXAMPLES/${d} ; ${SETENV} ${MAKE_ENV} \
		PICFLAG= home="${WRKSRC}" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} ${${d}TESTS} ; \
		${${d}TESTS:S|^|./|:S|$| ; |}
.endfor

fulltest-shared: lapack-drivers-shared
.for d in BAND COMPLEX NONSYM SIMPLE SVD SYM
	@cd ${WRKSRC}_SHARED/EXAMPLES/${d} ; ${SETENV} ${MAKE_ENV} \
		PICFLAG=${PICFLAG}  home="${WRKSRC}_SHARED" \
		${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} ${${d}TESTS} ; \
		${${d}TESTS:S|^|./|:S|$| ; |}
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
