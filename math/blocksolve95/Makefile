# New ports collection makefile for:  blocksolve95
# Date created:               03 October 2004
# Whom:                       Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	blocksolve95
PORTVERSION=	3.0
CATEGORIES=	math parallel
MASTER_SITES=	ftp://info.mcs.anl.gov/pub/BlockSolve95/	\
		ftp://ftp.irisa.fr/pub/mirrors/BlockSolve95/
DISTNAME=	BlockSolve95
EXTRACT_SUFX=	.tar.Z
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sofware for the efficient solution of large, sparse linear systems

LIB_DEPENDS=	f77blas.1:${PORTSDIR}/math/atlas
BUILD_DEPENDS=	${MPIDIR}/lib/libmpich.a:${PORTSDIR}/net/mpich
RUN_DEPENDS=	${MPIDIR}/bin/mpirun:${PORTSDIR}/net/mpich

USE_XLIB=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ARGS=	GMAKE=${GMAKE} PETSC_ARCH=${PETSC_ARCH} BOPT=${BOPT}

MPIDIR=		${LOCALBASE}/mpich
PETSC_ARCH=	freebsd
BOPT?=		O

FFLAGS?=	-O2

INCLUDES=	BMmsg.h BSdepend.h BSlog.h BSmy_blas.h BSprivate.h BSsparse.h
PORTDOCS=	manual.ps

.include <bsd.port.pre.mk>

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
test:	build
	@(cd ${BUILD_WRKSRC}/examples;	\
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} bsrunexamples clean)
.endif

.include "${FILESDIR}/BSman3.inc"
.include <bsd.port.post.mk>
