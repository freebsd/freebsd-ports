# New ports collection makefile for:   abinit
# Date Created:                18 March 2004
# Whom:                        NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abinit
PORTVERSION=	4.3.3
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.abinit.org/pub/abinitio/ABINIT_v${PORTVERSION}/
DISTFILES=	src_tests_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Abinit calculates electronic structure of systems

BUILD_DEPENDS=	${LOCALBASE}/intel_fc_80/bin/ifort:${PORTSDIR}/lang/ifc

.if defined(WITHOUT_ATLAS)
LIB_DEPENDS+=   lapack.1:${PORTSDIR}/math/lapack
.else
LIB_DEPENDS+=   atlas.1:${PORTSDIR}/math/atlas
.endif

ALL_TARGET=	allseq
USE_REINPLACE=	yes

.if defined(WITHOUT_ATLAS)
BLAS=		${LOCALBASE}/lib/libblas.a
LAPACK=		${LOCALBASE}/lib/liblapack.a
.else
BLAS=		${LOCALBASE}/lib/libatlas.a
LAPACK=		${LOCALBASE}/lib/libalapack.a ${LOCALBASE}/lib/libf77blas.a ${LOCALBASE}/lib/libcblas.a -lg2c -lm
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${ECHO} ${WRKSRC}
.for file in ${DISTFILES}
	@${TAR} xfz ${DISTDIR}/${DISTFILES} -C ${WRKSRC}
.endfor

#Flags for programs written in Fortran 77
FFLAGS_LIBS+=	-w ${FFLAGS}
#Flags for programs written in Fortran 90/95
FFLAGS+=	-w -FR

.if defined(WITH_OPTIMIZED_FLAGS)
FFLAGS+=	-O3 -tpp7 -axW
FFLAGS_LIBS+=	-O3 -tpp7 -axW
CFLAGS+=	-O2 -ffast-math
.endif

post-extract:
	@${CP} ${FILESDIR}/makefile_macros ${WRKSRC}/
	@${REINPLACE_CMD} -e 's+%%FFLAGS%%+${FFLAGS}+g' \
		-e 's+%%FC%%+${LOCALBASE}/intel_fc_80/bin/ifort+g' \
		-e 's+%%FFLAGS%%+${FFLAGS}+g' \
		-e 's+%%FFLAGS_LIBS%%+${FFLAG_LIBS}+g' \
		-e 's+%%CPP%%+${CPP}+g' \
		-e 's+%%CC%%+${CC}+g' \
		-e 's|%%CFLAGS%%|${CFLAGS}|g' \
		-e 's+%%PERL%%+${PERL}+g' \
		-e 's+%%BLAS%%+${BLAS}+g' \
		-e 's+%%LAPACK%%+${LAPACK}+g' ${WRKSRC}/makefile_macros

test:
	cd ${WRKSRC} ; ${MAKE} test1
	cd ${WRKSRC} ; ${MAKE} test2
	cd ${WRKSRC} ; ${MAKE} test3
	cd ${WRKSRC} ; ${MAKE} test4

do-install:
	@cd ${WRKSRC} ; ${INSTALL_PROGRAM} abinis   ${PREFIX}/bin
	@cd ${WRKSRC} ; ${INSTALL_PROGRAM} aim      ${PREFIX}/bin
	@cd ${WRKSRC} ; ${INSTALL_PROGRAM} anaddb   ${PREFIX}/bin
	@cd ${WRKSRC} ; ${INSTALL_PROGRAM} band2eps ${PREFIX}/bin
	@cd ${WRKSRC} ; ${INSTALL_PROGRAM} conducti ${PREFIX}/bin
	@cd ${WRKSRC} ; ${INSTALL_PROGRAM} cut3d    ${PREFIX}/bin
	@cd ${WRKSRC} ; ${INSTALL_PROGRAM} lwf      ${PREFIX}/bin
	@cd ${WRKSRC} ; ${INSTALL_PROGRAM} newsp    ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/Infos
	@${MKDIR} ${DOCSDIR}/Tutorial
	@${TAR} -cf - -C ${WRKSRC}/Infos    . | ${TAR} xf - -C ${DOCSDIR}/Infos
	@${TAR} -cf - -C ${WRKSRC}/Tutorial . | ${TAR} xf - -C ${DOCSDIR}/Tutorial
.endif

.include <bsd.port.mk>
