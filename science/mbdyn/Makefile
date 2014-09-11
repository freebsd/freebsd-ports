# Created by: Kay Lehmann <kay_lehmann@web.de>
# $FreeBSD$

PORTNAME=	mbdyn
PORTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.aero.polimi.it/~masarati/Download/mbdyn/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MultiBody Dynamics analysis system

LICENSE=	GPLv2

LIB_DEPENDS=	libarpack.so:${PORTSDIR}/math/arpack \
		libumfpack.so:${PORTSDIR}/math/suitesparse

GNU_CONFIGURE=	yes
USES=		fortran gmake libtool
CPPFLAGS+=	-fpermissive -I${LOCALBASE}/include/suitesparse
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--program-prefix=''
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MPI METIS CHACO GINAC TCL
MPI_DESC=	Enable mpich-support
METIS_DESC=	Enable metis-support
CHACO_DESC=	Enable chaco-support
GINAC_DESC=	Enable GiNaC-support (not implemented yet)
TCL_DESC=	Enable tcl-support (not implemented yet)

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

WITH_BLAS?=	reference

. if ${WITH_BLAS} == reference
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas \
		liblapack.so:${PORTSDIR}/math/lapack
CONFIGURE_ARGS+=	--with-blas=blas
LAPACK_LIBS=	-llapack
.elif ${WITH_BLAS} == gotoblas
LIB_DEPENDS+=	libgoto.so:${PORTSDIR}/math/gotoblas
CONFIGURE_ARGS+=	--with-blas=goto --with-goto=goto2
LAPACK_LIBS=	-lgoto2
.elif ${WITH_BLAS} == atlas
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
CONFIGURE_ARGS+=	--with-blas=atlas
LAPACK_LIBS=	-lalapack
.endif

.if ${PORT_OPTIONS:MMPI}
LIB_DEPENDS+=	libmpich.so:${PORTSDIR}/net/mpich2
CONFIGURE_ARGS+=	--with-mpi=yes --enable-schur
CPPFLAGS+=	-I${LOCALBASE}/include
. if ! ${PORT_OPTIONS:MMETIS}
WITH_CHACO=	yes
. endif
.else
CONFIGURE_ARGS+=	--with-mpi=no
.endif

.if ${PORT_OPTIONS:MMETIS}
LIB_DEPENDS+=	libmetis.so:${PORTSDIR}/math/metis4
CONFIGURE_ARGS+=	--with-metis=yes
CPPFLAGS+=	-I${LOCALBASE}/include/metis
.else
CONFIGURE_ARGS+=	--with-metis=no
.endif

.if ${PORT_OPTIONS:MCHACO}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libchaco.a:${PORTSDIR}/math/chaco
CONFIGURE_ARGS+=	--with-chaco=yes
.else
CONFIGURE_ARGS+=	--with-chaco=no
.endif

.if ${PORT_OPTIONS:MGINAC}
LIB_DEPENDS+=	libmetis.so:${PORTSDIR}/math/metis4 \
		ginac:${PORTSDIR}/math/GiNaC
CONFIGURE_ARGS+=	--with-ginac=yes
CPPFLAGS+=	-I${LOCALBASE}/include/metis
.else
CONFIGURE_ARGS+=	--with-ginac=no
.endif

.if ${PORT_OPTIONS:MTCL}
IGNORE=		you enabled Tcl-support, which is not implemented yet
LIB_DEPENDS+=	libtcl84.so:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	--with-tcl=yes
CPPFLAGS+=	-I${LOCALBASE}/include/tcl8.4
.else
CONFIGURE_ARGS+=	--with-tcl=no
.endif

post-patch:
	${REINPLACE_CMD} -e '/try_lapack_LIBS=/s/-llapack/${LAPACK_LIBS}/' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
