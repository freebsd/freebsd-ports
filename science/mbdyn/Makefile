# New ports collection makefile for:	mbdyn
# Date created:		2005-01-30
# Whom:			Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	mbdyn
PORTVERSION=	1.2.4
CATEGORIES=	science
MASTER_SITES=	http://mbdyn.aero.polimi.it/~masarati/Download/mbdyn/

MAINTAINER=	kay_lehmann@web.de
COMMENT=	A MultiBody Dynamics analysis system

LIB_DEPENDS=	lapack.3:${PORTSDIR}/math/lapack \
		atlas.1:${PORTSDIR}/math/atlas
BUILD_DEPENDS=	${LOCALBASE}/lib/libumfpack.a:${PORTSDIR}/math/umfpack

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=	13
CONFIGURE_ARGS+=	--program-prefix='' --with-umfpack=yes
CPPFLAGS+=	-I${LOCALBASE}/include/UMFPACK ${PTHREAD_CFLAGS}
LDFLAGS+=	-lm -L${LOCALBASE}/lib ${PTHREAD_LIBS}

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

MAN1=		mbdyn.1

OPTIONS=	MPI "Enable mpich-support" off \
		METIS "Enable metis-support" off \
		GINAC "Enable GiNaC-support (not implemented yet)" off \
		TCL "Enable tcl-support (not implemented yet)" off

.include <bsd.port.pre.mk>

.if defined(WITH_MPI)
BUILD_DEPENDS+=	${LOCALBASE}/mpich/lib/libmpich.a:${PORTSDIR}/net/mpich
CONFIGURE_ARGS+=	--with-mpi=pmpi
CPPFLAGS+=	-I${LOCALBASE}/mpich/include -I${LOCALBASE}/mpich/include/mpi2c++
LDFLAGS+=	-L${LOCALBASE}/mpich/lib
.else
CONFIGURE_ARGS+=	--with-mpi=no
.endif

.if defined(WITH_METIS)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmetis.a:${PORTSDIR}/math/metis
CONFIGURE_ARGS+=	--with-metis=yes
CPPFLAGS+=	-I${LOCALBASE}/include/metis
.else
CONFIGURE_ARGS+=	--with-metis=no
.endif

.if defined(WITH_GINAC)
IGNORE=		"You enabled GiNaC-support, which isn't implemented yet"
#BUILD_DEPENDS+=	${LOCALBASE}/lib/libmetis.a:${PORTSDIR}/math/metis
CONFIGURE_ARGS+=	--with-ginac=yes
CPPFLAGS+=	-I${LOCALBASE}/include/metis
.else
CONFIGURE_ARGS+=	--with-ginac=no
.endif

.if defined(WITH_TCL)
IGNORE=		"You enabled Tcl-support, which isn't implemented yet"
LIB_DEPENDS+=	tcl84:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	--with-tcl=yes
CPPFLAGS+=	-I${LOCALBASE}/include/tcl8.4
.else
CONFIGURE_ARGS+=	--with-tcl=no
.endif

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
