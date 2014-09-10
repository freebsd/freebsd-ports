# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	meep
PORTVERSION=	1.2
PORTREVISION=	9
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/meep/

MAINTAINER=	devel@stasyan.com
COMMENT=	FDTD simulation software to model electromagnetic systems

BUILD_DEPENDS=	harminv:${PORTSDIR}/science/harminv \
		gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS=	libguile.so:${PORTSDIR}/lang/guile \
		libblas.so:${PORTSDIR}/math/blas \
		libctl.so:${PORTSDIR}/science/libctl \
		libhdf5.so:${PORTSDIR}/science/hdf5
RUN_DEPENDS=	harminv:${PORTSDIR}/science/harminv

GNU_CONFIGURE=	yes
USE_GCC=	yes
USES=		fortran gettext gmake iconv libtool pathfix pkgconfig
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS+=	CC="${CC}" CXX="${CXX}"

OPTIONS_DEFINE=		OPENMPI
OPTIONS_DEFAULT=	OPENMPI
OPENMPI_DESC=		MPI support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENMPI}
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpiCC:${PORTSDIR}/net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpirun:${PORTSDIR}/net/openmpi
CONFIGURE_ARGS+=--with-mpi
CONFIGURE_ENV+=	MPICXX=${LOCALBASE}/mpi/openmpi/bin/mpiCC
CFLAGS+=	-I${LOCALBASE}/mpi/openmpi/include
PLIST_SUB+=	MPI="" NOMPI="@comment "
.else
CONFIGURE_ARGS+=--without-mpi
PLIST_SUB+=	MPI="@comment " NOMPI=""
.endif

.include <bsd.port.mk>
