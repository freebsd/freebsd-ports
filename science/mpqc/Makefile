# Created by: batman <batman@udel.edu>
# $FreeBSD$

PORTNAME=	mpqc
PORTVERSION=	2.3.1
PORTREVISION=	19
CATEGORIES=	science parallel
MASTER_SITES=	SF

MAINTAINER=	maho@FreeBSD.org
COMMENT=	The massively parallel quantum computing library and program

GNU_CONFIGURE=	yes
USES=		fortran gmake perl5
USE_AUTOTOOLS=	autoconf
USE_BZIP2=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if defined(WITH_ICC)
BUILD_DEPENDS+=	${LOCALBASE}/intel_cc_80/bin/icc:${PORTSDIR}/lang/icc
.endif
.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas
LAPACK=		-lalapack -lcblas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif
.if defined(WITH_MPICH)
LIB_DEPENDS+=	mpich:${PORTSDIR}/net/mpich2
.endif
LIB_DEPENDS+=	int.1:${PORTSDIR}/science/libint
.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	latex:build
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
BUILD_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
BUILD_DEPENDS+=	${LOCALBASE}/bin/gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS+=	execinfo.1:${PORTSDIR}/devel/libexecinfo
.endif

.if defined(WITH_ICC)
CC=		${LOCALBASE}/intel_cc_80/bin/icc
CXX=		${LOCALBASE}/intel_cc_80/bin/icpc
CFLAGS=		-O3 -tpp7 -xMKW -Vaxlib
CXXFLAGS=	-O3 -tpp7 -xMKW -Vaxlib
.endif

CONFIGURE_ARGS+=--with-cc=${CC} \
		--with-cxx=${CXX} \
		--with-f77=${FC} \
		--with-include="-I${WRKDIR} -I${LOCALBASE}/include" \
		--with-libdirs="-L${LOCALBASE}/lib ${LDFLAGS}" \
		--with-blas="${BLAS}" \
		--with-lapack="${LAPACK}" \
		--with-coptflags="${CFLAGS}" \
		--with-cxxoptflags="${CXXFLAGS}" \
		--with-f77optflags="${FFLAGS}" \
		--enable-shared \
		--with-sc-datadir=${PREFIX}/share/mpqc/${PORTVERSION}
.if defined(WITH_ICC)
CONFIGURE_ARGS+=--with-libs="-lsvml"
.endif
.if defined(WITH_MPICH)
CONFIGURE_ARGS+=--enable-always-use-mpi
CONFIGURE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"
.endif

MPQC_COMMAND=	${PREFIX}/bin/mpqc

.if ${PORT_OPTIONS:MDOCS}
.include "${FILESDIR}/manpages"
.endif

.if defined(WITH_OPTIMIZED_FLAGS)
CFLAGS+=	-O2 -ffast-math
CXXFLAGS+=	-O2 -ffast-math
.endif

pre-configure:
	@${ECHO} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."

do-build:
	@cd ${WRKSRC} ; ${GMAKE}
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/doc ; ${GMAKE}
.endif

do-install:
	(cd ${WRKSRC} ; ${GMAKE} install)
	(cd ${WRKSRC} ; ${GMAKE} install_devel)
	${MKDIR} ${PREFIX}/share/mpqc/validate
	cd ${WRKSRC}/src/bin/mpqc/validate/ ; ${TAR} -chf - . | \
		${TAR} -xf - -C ${PREFIX}/share/mpqc/validate
	${FIND} ${PREFIX}/share/mpqc/validate | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${PREFIX}/share/mpqc/validate -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.if ${PORT_OPTIONS:MDOCS}
	rm -f ${WRKSRC}/doc/man/man1/_*mpqc_*.1
	rm -f ${WRKSRC}/doc/man/man3/_*mpqc_*.3
	rm -f ${WRKSRC}/doc/man/man3/sc_PsiCCSD_T.3* #somehow this file is not generated in tinderbox
	(cd ${WRKSRC}/doc/man/man3 ; ${INSTALL_MAN} *3 ${PREFIX}/man/man3)
	(cd ${WRKSRC}/doc/man/man1 ; ${INSTALL_MAN} *1 ${PREFIX}/man/man1)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc/html ; ${TAR} -chf - . | ${TAR} -xf - -C ${DOCSDIR}
	${FIND} ${DOCSDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	cd ${PREFIX} ; ${FIND} -s share/doc/${PORTNAME} -type f  >> ${TMPPLIST}
	cd ${PREFIX} ; ${FIND} -s share/doc/${PORTNAME} -type l  >> ${TMPPLIST}
	${ECHO_CMD} "@dirrm share/doc/${PORTNAME}" >> ${TMPPLIST}
.endif
	cd ${PREFIX} ; ${FIND} -s share/mpqc -type f  >> ${TMPPLIST}
	cd ${PREFIX} ; ${FIND} -s share/mpqc -type l  >> ${TMPPLIST}
	cd ${PREFIX} ; ${FIND} -s share/mpqc -type d > ${WRKDIR}/dir.tmp
	${SORT} -r ${WRKDIR}/dir.tmp | ${XARGS} -n 1 ${ECHO_CMD} @dirrm >> ${TMPPLIST}

validate:
	cd ${WRKSRC}/src/bin/mpqc/validate ; ${GMAKE} check0 ; ${GMAKE} check0_run ; ${GMAKE} check0_chk

.include <bsd.port.post.mk>
