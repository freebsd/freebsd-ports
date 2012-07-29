# New ports collection makefile for:  blocksolve95
# Date created:               03 October 2004
# Whom:                       Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	blocksolve95
PORTVERSION=	3.0
PORTREVISION=	10
CATEGORIES=	math parallel
MASTER_SITES=	ftp://ftp.mcs.anl.gov/pub/BlockSolve95/ \
		http://ftp.mcs.anl.gov/pub/BlockSolve95/
DISTNAME=	BlockSolve95
EXTRACT_SUFX=	.tar.Z
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Software for the efficient solution of large, sparse linear systems

BUILD_DEPENDS=	${MPIDIR}/lib/libmpich.a:${PORTSDIR}/net/mpich2
LIB_DEPENDS=	f2c.2:${PORTSDIR}/lang/f2c
RUN_DEPENDS=	${MPIDIR}/bin/mpirun:${PORTSDIR}/net/mpich2

USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ARGS=	GMAKE=${GMAKE} PETSC_ARCH=${PETSC_ARCH} BOPT=${BOPT}	\
		BLAS_LIB="${BLAS_LIB}" LAPACK_LIB="${LAPACK_LIB}"

MPIDIR=		${LOCALBASE}
PETSC_ARCH=	freebsd
BOPT?=		O

USE_FORTRAN=	yes
FFLAGS+=	-O2

INCLUDES=	BMmsg.h BSdepend.h BSlog.h BSmy_blas.h BSprivate.h BSsparse.h
PORTDOCS=	manual.ps

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS_LIB=	-lf77blas
LAPACK_LIB=	-L${LOCALBASE}/lib -lalapack -lcblas
.else
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS_LIB=	-lblas
LAPACK_LIB=	-L${LOCALBASE}/lib -llapack
.endif

do-install:
	${INSTALL_DATA}	${WRKSRC}/lib/lib${BOPT}/${PETSC_ARCH}/libBS95.a	\
		${PREFIX}/lib
	${INSTALL_DATA}	${INCLUDES:S|^|${WRKSRC}/include/|} ${PREFIX}/include
	${INSTALL_MAN} ${MAN3:S|^|${WRKSRC}/doc/man/man3/|} ${MANPREFIX}/man/man3
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${PORTDOCS:S|^|${WRKSRC}/doc/manual/|} ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${RM} ${EXAMPLESDIR}/makefile.orig
.endif

.if defined(MAINTAINER_MODE)
regression-test:	build
. if !exists(${HOME}/.mpd.conf)
	@${ECHO_CMD} "MPD_SECRETWORD=change_on_install" > ${HOME}/.mpd.conf
	${CHMOD} go-r ${HOME}/.mpd.conf
	@${ECHO_MSG} "${HOME}/.mpd.conf has been generated - please change the secret word!"
. endif
	${LOCALBASE}/bin/mpd &
	@(cd ${BUILD_WRKSRC}/examples;	\
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} bsrunexamples clean)
	${LOCALBASE}/bin/mpdallexit
.endif

.include "${FILESDIR}/BSman3.inc"
.include <bsd.port.post.mk>
