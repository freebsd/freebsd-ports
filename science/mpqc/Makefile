# Created by: batman <batman@udel.edu>
# $FreeBSD$

PORTNAME=	mpqc
PORTVERSION=	2.3.1
PORTREVISION=	27
CATEGORIES=	science parallel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Massively Parallel Quantum Computing library and program

LIB_DEPENDS=	libint.so:science/libint

GNU_CONFIGURE=	yes
USES=		fortran gmake libtool perl5 shebangfix tar:bzip2
SHEBANG_FILES=	src/bin/mpqc/ccarunproc src/bin/mpqc/mpqcrunproc
USE_AUTOTOOLS=	autoconf
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--with-cc=${CC} \
		--with-cxx=${CXX} \
		--with-f77=${FC} \
		--with-include="-I${LOCALBASE}/include" \
		--with-libdirs="-L${LOCALBASE}/lib ${LDFLAGS}" \
		--with-blas="${BLAS}" \
		--with-lapack="${LAPACK}" \
		--with-coptflags="${CFLAGS}" \
		--with-cxxoptflags="${CXXFLAGS}" \
		--with-f77optflags="${FFLAGS}" \
		--enable-shared \
		--with-sc-datadir=${PREFIX}/share/mpqc/${PORTVERSION}

OPTIONS_DEFINE=		DOCS ATLAS ICC MPICH OPTIFLAGS
OPTIONS_SUB=		yes

ICC_DESC=		Build with ICC compiler instead
ATLAS_DESC=		Link with ATLAS instead of BLAS
DOCS_DESC=		Generate html docs and manpages (heavy dependencies)
MPICH_DESC=		Message-Passing Interface support
OPTIFLAGS_DESC=		Build with optimized flags

ICC_BUILD_DEPENDS=	${LOCALBASE}/intel_cc_80/bin/icc:lang/icc
MPICH_LIB_DEPENDS=	libmpich.so:net/mpich2
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz \
			${LOCALBASE}/bin/gsed:textproc/gsed
DOCS_USES=		execinfo
DOCS_USE=		TEX=latex:build

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=	libatlas.so:math/atlas
BLAS=		-lf77blas
LAPACK=		-lalapack -lcblas
.else
LIB_DEPENDS+=	libblas.so:math/blas
LIB_DEPENDS+=	liblapack.so:math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

.if ${PORT_OPTIONS:MICC}
CC=		${LOCALBASE}/intel_cc_80/bin/icc
CXX=		${LOCALBASE}/intel_cc_80/bin/icpc
CFLAGS=		-O3 -tpp7 -xMKW -Vaxlib
CXXFLAGS=	-O3 -tpp7 -xMKW -Vaxlib
CONFIGURE_ARGS+=--with-libs="-lsvml"
.endif

.if ${PORT_OPTIONS:MMPICH}
CONFIGURE_ARGS+=--enable-always-use-mpi
CONFIGURE_ENV+=	PTHREAD_LIBS=-lpthread
.endif

.if ${PORT_OPTIONS:MOPTIFLAGS}
CFLAGS+=	-O2 -ffast-math
CXXFLAGS+=	-O2 -ffast-math
.endif

do-build:
	(cd ${WRKSRC} && ${MAKE_CMD})

do-build-DOCS-on:
	(cd ${WRKSRC}/doc && ${MAKE_CMD})
	${RM} ${WRKSRC}/doc/man/man1/_*
	${RM} ${WRKSRC}/doc/man/man3/_*

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/mpqc/validate
	(cd ${WRKSRC} && ${MAKE_CMD} install installroot=${STAGEDIR:Q})
	(cd ${WRKSRC} && ${MAKE_CMD} install_devel installroot=${STAGEDIR:Q})
	(cd ${WRKSRC}/src/bin/mpqc/validate && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/mpqc/validate)
	(cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} scpr molrender mpqc scls)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so
	cd ${STAGEDIR}${PREFIX}; ${FIND} share/mpqc \
	   \( -type f -or -type l \) | ${SORT} >> ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX}; ${FIND} share/mpqc -type d -empty | ${SORT} -r | \
	   ${SED} -e 's/^/@dir /g' >> ${TMPPLIST}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/man/man3 && \
		${INSTALL_MAN} *3 ${STAGEDIR}${MANPREFIX}/man/man3)
	(cd ${WRKSRC}/doc/man/man1 && \
		${INSTALL_MAN} *1 ${STAGEDIR}${MANPREFIX}/man/man1)
	(cd ${WRKSRC}/doc/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	cd ${STAGEDIR}${PREFIX}; ${FIND} share/doc/mpqc \
	   \( -type f -or -type l \) | ${SORT} >> ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX}; ${FIND} share/doc/mpqc -type d -empty | \
	   ${SORT} -r | ${SED} -e 's/^/@dir /g' >> ${TMPPLIST}

validate:
	(cd ${WRKSRC}/src/bin/mpqc/validate && \
		${MAKE_CMD} check0 && \
		${MAKE_CMD} check0_run && \
		${MAKE_CMD} check0_chk)

.include <bsd.port.mk>
