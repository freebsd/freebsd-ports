# New ports collection makefile for:	mbdyn
# Date created:		2005-01-30
# Whom:			Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	mbdyn
PORTVERSION=	1.3.9
CATEGORIES=	science
MASTER_SITES=	http://www.aero.polimi.it/~masarati/Download/mbdyn/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A MultiBody Dynamics analysis system

LIB_DEPENDS=	umfpack:${PORTSDIR}/math/suitesparse

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_FORTRAN=	yes
MAN1=		mbdyn.1
CPPFLAGS+=	-I${LOCALBASE}/include/suitesparse
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib/${CC} -L${LOCALBASE}/lib" \
		CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS+=	--program-prefix=''

LIB_DEPENDS+=	arpack:${PORTSDIR}/math/arpack

OPTIONS=	MPI "Enable mpich-support" off \
		METIS "Enable metis-support" off \
		CHACO "Enable chaco-support" off \
		GINAC "Enable GiNaC-support (not implemented yet)" off \
		TCL "Enable tcl-support (not implemented yet)" off

.include <bsd.port.pre.mk>

USE_BLAS?=	reference

. if ${USE_BLAS} == reference
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
CONFIGURE_ARGS+=	--with-blas=blas
.elif ${USE_BLAS} == gotoblas
LIB_DEPENDS+=	goto:${PORTSDIR}/math/gotoblas
CONFIGURE_ARGS+=	--with-blas=goto
.elif ${USE_BLAS} == atlas
LIB_DEPENDS+=	atlas:${PORTSDIR}/math/atlas
CONFIGURE_ARGS+=        --with-blas=atlas
.endif
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack

.if defined(WITH_MPI)
LIB_DEPENDS+=	mpich:${PORTSDIR}/net/mpich2
CONFIGURE_ARGS+=	--with-mpi=pmpi
CPPFLAGS+=	-I${LOCALBASE}/mpich/include -I${LOCALBASE}/mpich/include/mpi2c++
LDFLAGS+=	-L${LOCALBASE}/mpich/lib
.else
CONFIGURE_ARGS+=	--with-mpi=no
.endif

.if defined(WITH_METIS)
LIB_DEPENDS+=	metis:${PORTSDIR}/math/metis
CONFIGURE_ARGS+=	--with-metis=yes
CPPFLAGS+=	-I${LOCALBASE}/include/metis
.else
CONFIGURE_ARGS+=	--with-metis=no
.endif

.if defined(WITH_CHACO)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libchaco.a:${PORTSDIR}/math/chaco
CONFIGURE_ARGS+=	--with-chaco=yes
.else
CONFIGURE_ARGS+=	--with-chaco=no
.endif

.if defined(WITH_GINAC)
LIB_DEPENDS+=	metis:${PORTSDIR}/math/metis
LIB_DEPENDS+=	ginac:${PORTSDIR}/math/GiNaC
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

.include <bsd.port.post.mk>
