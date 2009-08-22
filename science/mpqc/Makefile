# New ports collection makefile for:	mpqc
# Date created:				27 April 2001
# Whom:					batman <batman@udel.edu>
#
# $FreeBSD$
#

PORTNAME=	mpqc
PORTVERSION=	2.3.1
PORTREVISION=	6
CATEGORIES=	science parallel
MASTER_SITES=	SF

MAINTAINER=	maho@FreeBSD.org
COMMENT=	The massively parallel quantum computing library and program

USE_PERL5=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_ICC)
BUILD_DEPENDS+=  ${LOCALBASE}/intel_cc_80/bin/icc:${PORTSDIR}/lang/icc
.endif
.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas -lcblas
LAPACK=		-lalapack
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
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262

USE_FORTRAN=	yes

.if defined(WITH_ICC)
CC=		${LOCALBASE}/intel_cc_80/bin/icc
CXX=		${LOCALBASE}/intel_cc_80/bin/icpc
CFLAGS=		-O3 -tpp7 -xMKW -Vaxlib
CXXFLAGS=	-O3 -tpp7 -xMKW -Vaxlib
.endif

CONFIGURE_ARGS+=--with-cc=${CC} \
		--with-cxx=${CXX} \
		--with-f77=${FC} \
		--with-libdirs=-L${LOCALBASE}/lib \
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
CONFIGURE_ARGS+=--with-libdirs="-L${LOCALBASE}/lib -L${LOCALBASE}/mpich2/lib"\
		--enable-always-use-mpi
.endif
.if defined(WITH_MPICH)
CONFIGURE_ARGS+=--with-include="-I${LOCALBASE}/mpich2/include -I${WRKDIR} -I${LOCALBASE}/include"
.else
CONFIGURE_ARGS+=--with-include="-I${WRKDIR} -I${LOCALBASE}/include"
.endif

MPQC_COMMAND=	${PREFIX}/bin/mpqc

.if !defined(NOPORTDOCS)
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
.if !defined(NOPORTDOCS)
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

post-install:
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/doc/man/man3 ; ${INSTALL_MAN} * ${PREFIX}/man/man3)
	(cd ${WRKSRC}/doc/man/man1 ; ${INSTALL_MAN} * ${PREFIX}/man/man1)
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

