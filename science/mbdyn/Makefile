# Created by: Kay Lehmann <kay_lehmann@web.de>
# $FreeBSD$

PORTNAME=	mbdyn
PORTVERSION=	1.7.1
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://www.mbdyn.org/userfiles/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MultiBody Dynamics analysis system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libarpack.so:math/arpack \
		libumfpack.so:math/suitesparse

BROKEN_powerpc=	Does not compile on powerpc

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib fortran gmake libtool localbase
USE_LDCONFIG=	yes
CPPFLAGS+=	-fpermissive -I${LOCALBASE}/include/suitesparse
CONFIGURE_ARGS+=	--program-prefix=''
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MPI METIS CHACO GINAC
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

MPI_DESC=		Enable mpich-support (Requires Metis or Chaco, broken)
MPI_IGNORE=		you enabled MPI support, which is broken
MPI_BUILD_DEPENDS_OFF=	libatomic_ops>0:devel/libatomic_ops
MPI_LIB_DEPENDS=	libmpich.so:net/mpich2
MPI_CONFIGURE_ON=	--with-mpi=yes --enable-schur
MPI_CONFIGURE_OFF=	--with-mpi=no --enable-multithread

METIS_DESC=		Enable metis-support
METIS_LIB_DEPENDS=	libmetis.so:math/metis4
METIS_CONFIGURE_ON=	--with-metis=yes
METIS_CPPFLAGS=		-I${LOCALBASE}/include/metis
METIS_CONFIGURE_OFF=	--with-metis=no

CHACO_DESC=		Enable chaco-support
CHACO_BUILD_DEPENDS=	${LOCALBASE}/lib/libchaco.a:math/chaco
CHACO_CONFIGURE_ON=	--with-chaco=yes
CHACO_CONFIGURE_OFF=	--with-chaco=no

GINAC_DESC=		Enable GiNaC-support (not implemented yet)
GINAC_IGNORE=		you enabled GiNaC-support, which is broken
GINAC_LIB_DEPENDS=	libmetis.so:math/metis4 \
			libginac.so:math/GiNaC
GINAC_CONFIGURE_ON=	--with-ginac=yes
GINAC_CONFIGURE_OFF=	--with-ginac=no
GINAC_CPPFLAGS=		-I${LOCALBASE}/include/metis

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMPI} && ! ${PORT_OPTIONS:MMETIS}
WITH_CHACO=	yes
.endif

pre-configure:
	${REINPLACE_CMD} -e '/try_lapack_LIBS=/s/-llapack/${LAPACKLIB}/' \
		-e 's/ -lxerbla//; s/-lcholmod/-lcholmod ${BLASLIB} ${LAPACKLIB} -lsuitesparseconfig/'	\
		${WRKSRC}/configure

.include <bsd.port.post.mk>
