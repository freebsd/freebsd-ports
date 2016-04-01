# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	blocksolve95
PORTVERSION=	3.0
PORTREVISION=	16
CATEGORIES=	math parallel
MASTER_SITES=	ftp://ftp.mcs.anl.gov/pub/BlockSolve95/ \
		http://ftp.mcs.anl.gov/pub/BlockSolve95/
DISTNAME=	BlockSolve95
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software for the efficient solution of large, sparse linear systems

LICENSE=	AS-IS
LICENSE_NAME=	AS-IS
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libf2c.so:lang/f2c	\
		libmpich.so:net/mpich2

USES=		fortran gmake tar:Z

OPTIONS_RADIO=	BLAS
OPTIONS_RADIO_BLAS=	REFERENCE ATLAS
OPTIONS_DEFAULT=	REFERENCE

REFERENCE_DESC=	Blas / Lapack
REFERENCE_USES=	blaslapack:netlib

ATLAS_DESC=	ATLAS
ATLAS_USES=	blaslapack:atlas

MAKEFILE=	makefile
MAKE_ARGS=	GMAKE=${MAKE_CMD} PETSC_ARCH=${PETSC_ARCH} BOPT=${BOPT}	\
		BLAS_LIB="${BLASLIB}" LAPACK_LIB="-L${LOCALBASE}/lib ${LAPACKLIB}"

MPIDIR=		${LOCALBASE}
PETSC_ARCH=	freebsd
BOPT?=		O

FFLAGS+=	-O2

INCLUDES=	BMmsg.h BSdepend.h BSlog.h BSmy_blas.h BSprivate.h BSsparse.h
PORTDOCS=	manual.ps

.include <bsd.port.options.mk>

do-install:
	${INSTALL_DATA}	${WRKSRC}/lib/lib${BOPT}/${PETSC_ARCH}/libBS95.a	\
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA}	${INCLUDES:S|^|${WRKSRC}/include/|} ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/* ${STAGEDIR}${MANPREFIX}/man/man3
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA}	${PORTDOCS:S|^|${WRKSRC}/doc/manual/|} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	@${RM} ${STAGEDIR}${EXAMPLESDIR}/makefile.orig
.endif

.if defined(MAINTAINER_MODE)
regression-test:	build
. if !exists(${HOME}/.mpd.conf)
	@${ECHO_CMD} "MPD_SECRETWORD=change_on_install" > ${HOME}/.mpd.conf
	${CHMOD} go-r ${HOME}/.mpd.conf
	@${ECHO_MSG} "${HOME}/.mpd.conf has been generated - please change the secret word!"
. endif
	${LOCALBASE}/bin/mpd &
	(cd ${BUILD_WRKSRC}/examples &&	\
	${SETENV} ${MAKE_ENV:C|HOME=|wHOME=|} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} bsrunexamples clean)
	${LOCALBASE}/bin/mpdallexit
.endif

.include <bsd.port.mk>
