# Created by: Yuri Victorovich <yuri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmesh
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Numerical simulation of partial differential equations

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		autoreconf compiler:c++11-lang eigen:3 gmake libtool
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	libMesh
CONFIGURE_ARGS=	--disable-static \
		--with-methods=opt \
		--with-thread-model=pthread \
		--datarootdir=${DATADIR} \
		--enable-amr \
		--disable-strict-lgpl \
		--enable-tetgen \
		--enable-triagle \
		--with-boost=${LOCALBASE} \
		--with-eigen-include=${LOCALBASE}/include/eigen3 \
		--disable-netcdf --disable-netcdf-4 # https://github.com/libMesh/libmesh/issues/1542
MAKE_ARGS=	LDFLAGS="-pthread -lexecinfo"
USE_LDCONFIG=	yes

OPTIONS_DEFINE=			GLPK HDF5 MPI EXAMPLES
OPTIONS_DEFAULT=		MPI
GLPK_DESC=			Glpk linear programming solver library

GLPK_CONFIGURE_ENABLE=		glpk
GLPK_LIB_DEPENDS=		libglpk.so:math/glpk
HDF5_CONFIGURE_ENABLE=		hdf5
HDF5_LIB_DEPENDS=		libhdf5.so:science/hdf5
MPI_CONFIGURE_ENABLE=		mpi
FSCURVES_CONFIGURE_ENABLE=	sfc
EXAMPLES_CONFIGURE_ENABLE=	examples
EXAMPLES_VARS=			PKGMESSAGE=pkg-message-examples
SUB_FILES=			pkg-message-examples

PORTEXAMPLES=	*

post-extract:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MV} ${STAGEDIR}${PREFIX}/etc/libmesh/Make.common ${STAGEDIR}${DATADIR}
	@cd ${STAGEDIR}${PREFIX} && ${RM} -r \
		etc/libmesh \
		Make.common \
		contrib \
		libdata/pkgconfig/Make.common # https://github.com/libMesh/libmesh/issues/1539

post-install-EXAMPLES-on:
	# https://github.com/libMesh/libmesh/issues/1541
	@${MV} ${STAGEDIR}${PREFIX}/examples ${STAGEDIR}${EXAMPLESDIR}
	@${FIND} ${STAGEDIR}${EXAMPLESDIR} -name Makefile | ${XARGS} ${REINPLACE_CMD} -i '' -e ' \
		s|LIBMESH_DIR ?= .*|LIBMESH_DIR ?= ${PREFIX}| ; \
		s|$$(LIBMESH_DIR)/Make.common|${DATADIR}/Make.common| ; \
		s|LIBMESH_DIR/examples|LIBMESH_DIR/share/examples/${PORTNAME}| ; \
		s|$$(libmesh_LDFLAGS)|$$(libmesh_LDFLAGS) -pthread|'
	@${FIND} ${STAGEDIR}${EXAMPLESDIR} -name run.sh | ${XARGS} ${CHMOD} +x
	@${FIND} ${STAGEDIR}${EXAMPLESDIR} -name run.sh | ${XARGS} ${REINPLACE_CMD} -i '' -e ' \
		s|#set -x|export LIBMESH_DIR=${PREFIX}| ; \
		s|#!/bin/bash|#!${LOCALBASE}/bin/bash| ; \
		s|LIBMESH_DIR/examples|LIBMESH_DIR/share/examples/${PORTNAME}| ; \
		s|reference_elements|share/${PORTNAME}/reference_elements|'
	@${REINPLACE_CMD} -i '' -e 's|libmesh_LIBTOOL ?= /usr/local/contrib/bin/libtool|libmesh_LIBTOOL ?= libtool|' \
		${STAGEDIR}${DATADIR}/Make.common

.include <bsd.port.mk>
