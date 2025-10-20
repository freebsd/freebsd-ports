PORTNAME=	libmesh
DISTVERSION=	1.7.5
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	https://github.com/libMesh/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Numerical simulation of partial differential equations
WWW=		https://libmesh.github.io \
		https://github.com/libMesh/libmesh

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		compilation fails with nlopt-2.9.0, see https://github.com/libMesh/libmesh/issues/4009

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libnlopt.so:math/nlopt
TEST_DEPENDS=	bash:shells/bash

USES=		compiler:c++17-lang eigen:3 gmake libtool localbase perl5 pkgconfig shebangfix tar:xz

SHEBANG_GLOB=	*.sh # for one or more run.sh files in tests

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-methods=opt \
		--with-thread-model=pthread \
		--datarootdir=${DATADIR} \
		--enable-amr \
		--enable-nlopt \
		--disable-strict-lgpl \
		--enable-tetgen \
		--enable-triagle \
		--with-boost=${LOCALBASE} \
		--with-eigen-include=${LOCALBASE}/include/eigen3 \
		--disable-netcdf --disable-netcdf-4 # https://github.com/libMesh/libmesh/issues/1542
CONFIGURE_ARGS+=	--disable-metaphysicl # enabling this causes libmesh to install a bundled metaphysicl that would conflict with the metaphysicl package
CONFIGURE_ARGS+=	--with-nlopt-include=${LOCALBASE}/include --with-nlopt-lib=${LOCALBASE}/lib # workaround for https://github.com/libMesh/libmesh/issues/3314
MAKE_ARGS=	LDFLAGS="-pthread -lexecinfo -L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

CXXFLAGS+=	-I${WRKSRC}/contrib/parmetis/include # because parmetis.h isn't found for ./include/libmesh/parmetis_helper.h

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=			GLPK HDF5 MPI EXAMPLES
OPTIONS_DEFAULT=		MPI
GLPK_DESC=			Glpk linear programming solver library

GLPK_CONFIGURE_ENABLE=		glpk
GLPK_LIB_DEPENDS=		libglpk.so:math/glpk

HDF5_CONFIGURE_ENABLE=		hdf5
HDF5_LIB_DEPENDS=		libhdf5.so:science/hdf5

MPI_CONFIGURE_ENABLE=		mpi
MPI_CONFIGURE_ON=		--with-mpi=${LOCALBASE} --with-mpi-include=${LOCALBASE}/include --with-mpi-lib=${LOCALBASE}/lib
MPI_LIB_DEPENDS=		libmpi.so:net/mpich

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
	# delete metis.h, see https://github.com/libMesh/libmesh/issues/3317
	${RM} ${STAGEDIR}${PREFIX}/include/metis.h

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
