# New ports collection makefile for:	mbdyn
# Date created:		2005-01-30
# Whom:			Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	mbdyn
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://mbdyn.aero.polimi.it/~masarati/Download/mbdyn/

MAINTAINER=	kay_lehmann@web.de
COMMENT=	A MultiBody Dynamics analysis system

LIB_DEPENDS=	umfpack:${PORTSDIR}/math/suitesparse

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:259
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--program-prefix='' --with-umfpack=yes
CPPFLAGS+=	-I${LOCALBASE}/include/suitesparse ${PTHREAD_CFLAGS}
LDFLAGS+=	-lm -L${LOCALBASE}/lib ${PTHREAD_LIBS}
WANT_FORTRAN=	yes #dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42
FORTRANLIBS=	-lgfortranbegin -lgfortran
GCCLIBDIR=	-L`${CAT} ${WRKSRC}/LIBDIR` -L`${CAT} ${WRKSRC}/LIBDIR`/../../..

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		FC="${FC}" F77="${F77}" FFLAGS="${FFLAGS}"

MAN1=		mbdyn.1

OPTIONS=	MPI "Enable mpich-support" off \
		METIS "Enable metis-support" off \
		GINAC "Enable GiNaC-support (not implemented yet)" off \
		TCL "Enable tcl-support (not implemented yet)" off

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
CONFIGURE_ARGS+=	--with-blas=atlas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
CONFIGURE_ARGS+=	--with-blas=blas
.endif

pre-configure:
	@${DIRNAME} `${F77} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
	@${REINPLACE_CMD} -e "s+%%GCCLIBDIR%%+${GCCLIBDIR}+" -e "s+%%FORTRANLIBS%%+${FORTRANLIBS}+" ${WRKSRC}/configure.in

.if defined(WITH_MPI)
BUILD_DEPENDS+=	${LOCALBASE}/mpich/lib/libmpich.a:${PORTSDIR}/net/mpich
CONFIGURE_ARGS+=	--with-mpi=pmpi
CPPFLAGS+=	-I${LOCALBASE}/mpich/include -I${LOCALBASE}/mpich/include/mpi2c++
LDFLAGS+=	-L${LOCALBASE}/mpich/lib
.else
CONFIGURE_ARGS+=	--with-mpi=no
.endif

.if defined(WITH_METIS)
BROKEN=		Does not compile with metis enabled
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmetis.a:${PORTSDIR}/math/metis
CONFIGURE_ARGS+=	--with-metis=yes
CPPFLAGS+=	-I${LOCALBASE}/include/metis
.else
CONFIGURE_ARGS+=	--with-metis=no
.endif

.if defined(WITH_GINAC)
IGNORE=		you enabled GiNaC-support, which is not implemented yet
#BUILD_DEPENDS+=	${LOCALBASE}/lib/libmetis.a:${PORTSDIR}/math/metis
CONFIGURE_ARGS+=	--with-ginac=yes
CPPFLAGS+=	-I${LOCALBASE}/include/metis
.else
CONFIGURE_ARGS+=	--with-ginac=no
.endif

.if defined(WITH_TCL)
IGNORE=		you enabled Tcl-support, which is not implemented yet
LIB_DEPENDS+=	tcl84:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	--with-tcl=yes
CPPFLAGS+=	-I${LOCALBASE}/include/tcl8.4
.else
CONFIGURE_ARGS+=	--with-tcl=no
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

.if ${OSVERSION} < 500000
BROKEN=		Does not compile
.endif

.include <bsd.port.post.mk>
