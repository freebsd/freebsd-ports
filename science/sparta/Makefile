# $FreeBSD$

PORTNAME=	sparta
PORTVERSION=	${GH_TAGNAME:C/([0-9]{1,2})([A-Z][a-z][a-z])([0-9]{4})/\3.\2.\1/S/Jan/01/S/Feb/02/S/Mar/03/S/Apr/04/S/May/05/S/Jun/06/S/Jul/07/S/Aug/08/S/Sep/09/S/Oct/10/S/Nov/11/S/Dec/12/}
PORTREVISION=	1
CATEGORIES=	science
PKGNAMESUFFIX=	-dsmc # Direct Simulation Monte Carlo

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Gas simulator: SPARTA DSMC software package

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang gmake localbase
USE_GITHUB=	yes
GH_TAGNAME=	24Jan2020

CXXFLAGS+=	-DSPARTA_UNORDERED_MAP

WRKSRC_SUBDIR=	src
MAKE_ARGS=	CC=${CXX} CCFLAGS="${CXXFLAGS}" LINK=${CXX} LINKFLAGS="${LDFLAGS}" mode=exe

OPTIONS_SINGLE=			PARALLEL
OPTIONS_SINGLE_PARALLEL=	SERIAL MPI
OPTIONS_DEFAULT=		MPI
PARALLEL_DESC=			Parallelization

SERIAL_DESC=			Serial: no parallelization
SERIAL_ALL_TARGET=		serial
SERIAL_PLIST_FILES=		bin/spa_serial

MPI_ALL_TARGET=			mpi
MPI_PLIST_FILES=		bin/spa_mpi
MPI_CXXFLAGS=			-I${LOCALBASE}/mpi/openmpi/include
MPI_LDFLAGS=			${LOCALBASE}/mpi/openmpi/lib/libmpi.so \
				${LOCALBASE}/mpi/openmpi/lib/libmpi_cxx.so \
				-Wl,-rpath=${LOCALBASE}/mpi/openmpi/lib
MPI_LIB_DEPENDS=		libmpi.so:net/openmpi

PORTSCOUT=	ignore:1 # due to a special version tagging scheme that this project uses portscout fails to find new versions, watching their release page instead

post-patch:
	@${REINPLACE_CMD} 's|SHELL = /bin/bash|SHELL = ${LOCALBASE}/bin/bash|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spa_* ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
