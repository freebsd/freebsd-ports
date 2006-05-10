# New ports collection makefile for:    scalapack
# Date created:                         5 Feb 2003
# Whom:                                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scalapack
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/scalapack/
DISTNAME=	SCALAPACK
DISTFILES=	scalapack.tgz manpages.tgz
.if !defined(NOPORTDOCS)
DISTFILES+=	scalapack_install.ps scalapackqref.ps  \
		lawn100.ps pblasqref.ps manual.ps design.ps \
		pumma_refmanual.ps trans.ps
.endif
DIST_SUBDIR=	scalapack
EXTRACT_ONLY=	scalapack.tgz manpages.tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	The ScaLAPACK Scalable LAPACK library

BUILD_DEPENDS=	${LOCALBASE}/mpich/lib/libmpich.a:${PORTSDIR}/net/mpich \
		${LOCALBASE}/lib/libblacs.a:${PORTSDIR}/math/blacs \
		${LOCALBASE}/bin/f2c:${PORTSDIR}/lang/f2c
LIB_DEPENDS=	lapack:${PORTSDIR}/math/lapack \
		atlas:${PORTSDIR}/math/atlas

CONFLICTS=	elmer-mathlibs-1*

F77?=	f77

ARCH2FIX=	PBLAS/SRC PBLAS/SRC/PBBLAS PBLAS/SRC/PTOOLS PBLAS/SRC/PTZBLAS \
		REDIST/SRC SRC TOOLS TOOLS/LAPACK

DATADIR=	${PREFIX}/share/${PORTNAME:U}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME:U}
PKGMESSAGE=	${WRKDIR}/pkg-message

.include "files/manpages"

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_FLAGS)
.if ${ARCH} == "amd64"
FFLAGS+=	-pipe -O3 -ffast-math -funroll-all-loops -fpeel-loops -ftracer -funswitch-loops -funit-at-a-time
CFLAGS+=	-pipe -O3 -ffast-math -funroll-all-loops -fpeel-loops -ftracer -funswitch-loops -funit-at-a-time
.elif ${ARCH} == "i386"
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double -mcpu=i686 -march=i686 -mfancy-math-387 -mpreferred-stack-boundary=3
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double -mcpu=i686 -march=i686 -mfancy-math-387 -mpreferred-stack-boundary=3
.else
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -Wno-multichar
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -Wno-multichar
.endif
.endif
post-patch:
	${REINPLACE_CMD} -e 's,@WRKSRC@,${WRKSRC},g ; s,@PREFIX@,${PREFIX},g ; s,@CC@,${CC},g ; s,@CFLAGS@,${CFLAGS},g ; s,@F77@,${F77},g ; s,@FFLAGS@,${FFLAGS},g ; s,@F77EXTRAFLAGS@,${F77EXTRAFLAGS},g ; s,^ARCH *.= ar,ARCMD = ar,' ${WRKSRC}/SLmake.inc
.for mkf in ${ARCH2FIX}
	${REINPLACE_CMD} -e 's|\$$(ARCH)|$$(ARCMD)|' ${WRKSRC}/${mkf}/Makefile
.endfor

do-build:
	(cd ${WRKSRC}; make ; make exe)
	(cd ${WRKSRC}; ${PATCH} < ${FILESDIR}/PBtools.h.patch )
	(${MKDIR} ${WRKSRC}/include ;\
	  cd ${WRKSRC}/include ;\
	  f2c -C++ -P  ${WRKSRC}/SRC/*.f ;\
	  f2c -C++ -P  ${WRKSRC}/TOOLS/*.f ;\
 	  ${CAT} *.P | ${GREP} -v :ref: > scalapack.h)

do-install:
	${INSTALL_DATA} ${WRKSRC}/libscalapack.a ${PREFIX}/lib/libscalapack.a
	${INSTALL_MAN}  ${WRKDIR}/MANPAGES/man/manl/*.l ${PREFIX}/man/manl
	${MKDIR} ${PREFIX}/share/SCALAPACK/TESTING
	(cd ${WRKSRC}/TESTING/ ;\
	${INSTALL_PROGRAM} x* ${PREFIX}/share/SCALAPACK/TESTING ;\
	${INSTALL_DATA} *.dat ${PREFIX}/share/SCALAPACK/TESTING)
	${INSTALL_DATA} ${WRKSRC}/include/scalapack.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/PBLAS/SRC/*.h ${PREFIX}/include
	${MKDIR} ${PREFIX}/share/examples/SCALAPACK
	${INSTALL_DATA} ${FILESDIR}/Makefile    ${PREFIX}/share/examples/SCALAPACK
	${INSTALL_DATA} ${FILESDIR}/example1.cc ${PREFIX}/share/examples/SCALAPACK
	${INSTALL_DATA} ${FILESDIR}/example1.f  ${PREFIX}/share/examples/SCALAPACK
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/design.ps    | ${GZIP_CMD} > ${DOCSDIR}/design.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/lawn100.ps   | ${GZIP_CMD} > ${DOCSDIR}/lawn100.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/manual.ps    | ${GZIP_CMD} > ${DOCSDIR}/manual.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/pblasqref.ps | ${GZIP_CMD} > ${DOCSDIR}/pblasqref.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/pumma_refmanual.ps | ${GZIP_CMD} > ${DOCSDIR}/pumma_refmanual.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/scalapack_install.ps | ${GZIP_CMD} > ${DOCSDIR}/scalapack_install.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/scalapackqref.ps | ${GZIP_CMD} > ${DOCSDIR}/scalapackqref.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/trans.ps | ${GZIP_CMD} > ${DOCSDIR}/trans.ps.gz
.endif

post-install:
	@${SED} -e 's,/usr/local,${PREFIX},g' ${FILESDIR}/pkg-message.in \
		> ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
