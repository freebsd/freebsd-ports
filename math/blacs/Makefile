# New ports collection makefile for:    blacs
# Date created:                 5 May 2003
# Whom:                         NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	blacs
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/blacs/
DISTNAME=	BLACS
DISTFILES=	mpiblacs.tgz blacstester.tgz mpiblacs-patch03.tgz
.if !defined(NOPORTDOCS)
DISTFILES+=     blacs_install.ps f77blacsqref.ps lawn94.ps \
		cblacsqref.ps  mpi_prop.ps mpiblacs_issues.ps
.endif
DIST_SUBDIR=	blacs
EXTRACT_ONLY=	mpiblacs.tgz blacstester.tgz mpiblacs-patch03.tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	The BLACS (Basic Linear Algebra Communication Subprograms)

LIB_DEPENDS=	lapack:${PORTSDIR}/math/lapack \
		atlas:${PORTSDIR}/math/atlas
BUILD_DEPENDS=	${LOCALBASE}/mpich/lib/libmpich.a:${PORTSDIR}/net/mpich

.include <bsd.port.pre.mk>

pre-fetch:
	@${ECHO} "If you want to use compiler other than f77,"
	@${ECHO} "plase set NO_GNUF77=yes"

F77?=	f77
.if !defined(NO_GNUF77)
F77EXTRAFLAGS=  -w -fno-globals -fugly-complex
.endif
USE_REINPLACE=  yes
DEBUG_LEVEL=	0

pre-patch:
	(${CP} ${WRKSRC}/BMAKES/Bmake.MPI-LINUX ${WRKSRC}/Bmake.inc)
post-patch:
	(${REINPLACE_CMD} -e 's,@WRKSRC@,${WRKSRC},g ; s,@DEBUG_LEVEL@,${DEBUG_LEVEL},g ; s,@PREFIX@,${PREFIX},g ; s,@CC@,${CC},g ; s,@CFLAGS@,${CFLAGS},g ; s,@F77@,${F77},g ; s,@FFLAGS@,${FFLAGS},g ; s,@F77EXTRAFLAGS@,${F77EXTRAFLAGS},g'  ${WRKSRC}/Bmake.inc)

do-build:
	(cd ${WRKSRC}; make mpi; make tester)

do-install:
	${INSTALL_DATA} ${WRKSRC}/LIB/blacsCinit_MPI-FreeBSD-${DEBUG_LEVEL}.a ${PREFIX}/lib/libblacsc.a
	${INSTALL_DATA} ${WRKSRC}/LIB/blacsF77init_MPI-FreeBSD-${DEBUG_LEVEL}.a ${PREFIX}/lib/libblacsf77.a
	${INSTALL_DATA} ${WRKSRC}/LIB/blacs_MPI-FreeBSD-${DEBUG_LEVEL}.a ${PREFIX}/lib/libblacs.a
	${MKDIR} ${PREFIX}/share/BLACS/TESTING
	( cd ${WRKSRC}/TESTING/EXE ; \
	  ${INSTALL_PROGRAM} xCbtest_MPI-FreeBSD-${DEBUG_LEVEL} ${PREFIX}/share/BLACS/TESTING/xCbtest_MPI-FreeBSD; \
	  ${INSTALL_PROGRAM} xFbtest_MPI-FreeBSD-${DEBUG_LEVEL} ${PREFIX}/share/BLACS/TESTING/xFbtest_MPI-FreeBSD; \
	  ${INSTALL_DATA}  bsbr.dat   ${PREFIX}/share/BLACS/TESTING; \
	  ${INSTALL_DATA}  bt.dat     ${PREFIX}/share/BLACS/TESTING; \
	  ${INSTALL_DATA}  comb.dat   ${PREFIX}/share/BLACS/TESTING; \
	  ${INSTALL_DATA}  sdrv.dat   ${PREFIX}/share/BLACS/TESTING)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/blacs_install.ps   | ${GZIP_CMD} > ${DOCSDIR}/blacs_install.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/cblacsqref.ps      | ${GZIP_CMD} > ${DOCSDIR}/cblacsqref.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/f77blacsqref.ps    | ${GZIP_CMD} > ${DOCSDIR}/f77blacsqref.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/lawn94.ps          | ${GZIP_CMD} > ${DOCSDIR}/lawn94.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/mpi_prop.ps        | ${GZIP_CMD} > ${DOCSDIR}/mpi_prop.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/mpiblacs_issues.ps | ${GZIP_CMD} > ${DOCSDIR}/mpiblacs_issues.ps.gz
.endif

post-install:
	@${SED} -e 's,/usr/local,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
