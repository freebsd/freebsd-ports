# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	meep
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/meep/

MAINTAINER=	devel@stasyan.com
COMMENT=	FDTD simulation software to model electromagnetic systems

BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash \
		harminv:${PORTSDIR}/science/harminv \
		gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS+=	guile.21:${PORTSDIR}/lang/guile \
		blas.2:${PORTSDIR}/math/blas \
		ctl.5:${PORTSDIR}/science/libctl \
		hdf5.7:${PORTSDIR}/science/hdf5-18
RUN_DEPENDS+=	harminv:${PORTSDIR}/science/harminv

GNU_CONFIGURE=	yes
USE_GCC=	yes
USES=		fortran gettext gmake iconv pathfix
USE_AUTOTOOLS+=	libltdl
CPPFLAGS+=	-I${LOCALBASE}/include
LD_LIBRARY_PATH=	-L${LOCALBASE}/lib -L/usr/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	LD_LIBRARY_PATH="${LD_LIBRARY_PATH}"

OPTIONS_DEFINE=		OPENMPI
OPTIONS_DEFAULT=	OPENMPI
OPENMPI_DESC=		MPI support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENMPI}
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpiCC:${PORTSDIR}/net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpirun:${PORTSDIR}/net/openmpi
CONFIGURE_ARGS+=--with-mpi
CONFIGURE_ENV+=	MPICXX=${LOCALBASE}/mpi/openmpi/bin/mpiCC
PLIST_SUB+=	MPI="" NOMPI="@comment "
.else
CONFIGURE_ARGS+=--without-mpi
PLIST_SUB+=	MPI="@comment " NOMPI=""
.endif

post-patch:
	${REINPLACE_CMD} -e 's+\#\! /bin/sh+\#\! ${PREFIX}/bin/bash+' \
		-e s+\$$\(SHELL\)+${PREFIX}/bin/bash+ ${WRKSRC}/configure

.include <bsd.port.mk>
