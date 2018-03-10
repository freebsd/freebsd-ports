# Created by: batman <batman@udel.edu>
# $FreeBSD$

PORTNAME=	mpqc
PORTVERSION=	2.3.1
PORTREVISION=	33
CATEGORIES=	science parallel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Massively Parallel Quantum Chemistry Program

LIB_DEPENDS=	libint.so:science/libint

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-production \
		--enable-shared \
		--with-cc-optflags="${CFLAGS}" \
		--with-cxx-optflags="${CXXFLAGS}" \
		--with-sc-datadir=${DATADIR}
LIBS+=		-Wl,--as-needed -lexecinfo -Wl,--no-as-needed
ALL_TARGET=	default
INSTALL_TARGET=	install install_devel
DESTDIRNAME=	installroot
USES=		fortran gmake libtool localbase perl5 shebangfix tar:bzip2
SHEBANG_FILES=	src/bin/mpqc/ccarunproc src/bin/mpqc/mpqcrunproc
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		ATLAS DOXYGEN EXAMPLES ICC MPICH OPTIFLAGS
OPTIONS_DEFAULT=	DOXYGEN
OPTIONS_SUB=		yes

ICC_DESC=		Build with ICC compiler instead
ATLAS_DESC=		Link with ATLAS instead of BLAS
MPICH_DESC=		Parallel processing support via MPICH
OPTIFLAGS_DESC=		Build with optimized flags

ATLAS_USES=		blaslapack:atlas
ATLAS_USES_OFF=		blaslapack:netlib
DOXYGEN_CONFIGURE_ENABLE=doxygen-man
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
ICC_BUILD_DEPENDS=	${LOCALBASE}/intel_cc_80/bin/icc:lang/icc
MPICH_CONFIGURE_ENABLE=	parallel
MPICH_LIB_DEPENDS=	libmpi.so.12:net/mpich
OPTIFLAGS_CFLAGS=	-ffast-math
OPTIFLAGS_CXXFLAGS=	-ffast-math

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICC}
CC=		${LOCALBASE}/intel_cc_80/bin/icc
CXX=		${LOCALBASE}/intel_cc_80/bin/icpc
CFLAGS=		-O3 -tpp7 -xMKW -Vaxlib
CXXFLAGS=	-O3 -tpp7 -xMKW -Vaxlib
LIBS+=		-lsvml
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's/-lblas/${BLASLIB}/' -e 's/-llapack/${LAPACKLIB}/' \
		-e 's/pthread_join(0,0)/pthread_create(0,0,0,0)/' \
		${WRKSRC}/configure

do-build-DOXYGEN-on:
	@(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS})
	${RM} ${WRKSRC}/doc/man/man1/_* ${WRKSRC}/doc/man/man3/_*

do-install-DOXYGEN-on:
	@(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} \
		install install_man)
	${MV} ${STAGEDIR}${PREFIX}/html ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} \
		install_samples)
	${MV} ${STAGEDIR}${PREFIX}/examples/mp2 ${STAGEDIR}${EXAMPLESDIR}
	${RMDIR} ${STAGEDIR}${PREFIX}/examples

post-install:
	(cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} scpr molrender mpqc scls)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

validate:
	(cd ${WRKSRC}/src/bin/mpqc/validate && \
		${MAKE_CMD} check0 && \
		${MAKE_CMD} check0_run && \
		${MAKE_CMD} check0_chk)

.include <bsd.port.mk>
