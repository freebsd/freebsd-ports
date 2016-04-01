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

LIB_DEPENDS=	libarpack.so:math/arpack \
		libumfpack.so:math/suitesparse

GNU_CONFIGURE=	yes
USES=		fortran gmake libtool
USE_LDCONFIG=	yes
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
OPTIONS_RADIO=	BLAS
OPTIONS_RADIO_BLAS=	REFERENCE GOTOBLAS ATLAS
OPTIONS_DEFAULT=	REFERENCE

REFERENCE_DESC=	Blas / Lapack
REFERENCE_USES=	blaslapack:netlib
REFERENCE_CONFIGURE_ON=	--with-blas=blas

ATLAS_DESC=	ATLAS
ATLAS_USES=	blaslapack:atlas
ATLAS_CONFIGURE_ON=	--with-blas=atlas

GOTOBLAS_DESC=	GotoBLAS2
GOTOBLAS_USES=	blaslapack:gotoblas
GOTOBLAS_CONFIGURE_ON=	--with-blas=goto --with-goto=goto2

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.if ${PORT_OPTIONS:MMPI}
LIB_DEPENDS+=	libmpich.so:net/mpich2
CONFIGURE_ARGS+=	--with-mpi=yes --enable-schur
CPPFLAGS+=	-I${LOCALBASE}/include
. if ! ${PORT_OPTIONS:MMETIS}
WITH_CHACO=	yes
. endif
.else
CONFIGURE_ARGS+=	--with-mpi=no
.endif

.if ${PORT_OPTIONS:MMETIS}
LIB_DEPENDS+=	libmetis.so:math/metis4
CONFIGURE_ARGS+=	--with-metis=yes
CPPFLAGS+=	-I${LOCALBASE}/include/metis
.else
CONFIGURE_ARGS+=	--with-metis=no
.endif

.if ${PORT_OPTIONS:MCHACO}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libchaco.a:math/chaco
CONFIGURE_ARGS+=	--with-chaco=yes
.else
CONFIGURE_ARGS+=	--with-chaco=no
.endif

.if ${PORT_OPTIONS:MGINAC}
LIB_DEPENDS+=	libmetis.so:math/metis4 \
		libginac.so:math/GiNaC
CONFIGURE_ARGS+=	--with-ginac=yes
CPPFLAGS+=	-I${LOCALBASE}/include/metis
.else
CONFIGURE_ARGS+=	--with-ginac=no
.endif

.if ${PORT_OPTIONS:MTCL}
IGNORE=		you enabled Tcl-support, which is not implemented yet
LIB_DEPENDS+=	libtcl84.so:lang/tcl84
CONFIGURE_ARGS+=	--with-tcl=yes
CPPFLAGS+=	-I${LOCALBASE}/include/tcl8.4
.else
CONFIGURE_ARGS+=	--with-tcl=no
.endif

pre-configure:
	${REINPLACE_CMD} -e '/try_lapack_LIBS=/s/-llapack/${LAPACKLIB}/' \
		-e 's/ -lxerbla//; s/-lcholmod/-lcholmod ${BLASLIB} ${LAPACKLIB} -lsuitesparseconfig/'	\
		${WRKSRC}/configure

.include <bsd.port.post.mk>
