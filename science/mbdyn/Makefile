# Created by: Kay Lehmann <kay_lehmann@web.de>
# $FreeBSD$

PORTNAME=	mbdyn
PORTVERSION=	1.7.3
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://www.mbdyn.org/userfiles/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MultiBody Dynamics analysis system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc=	Does not compile on powerpc

BUILD_DEPENDS=	libatomic_ops>0:devel/libatomic_ops
LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libarpack.so:math/arpack-ng \
		libumfpack.so:math/suitesparse

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib fortran gmake libtool:build localbase
USE_LDCONFIG=	yes
CPPFLAGS+=	-fpermissive -I${LOCALBASE}/include/suitesparse
CONFIGURE_ARGS=	--program-prefix='' --enable-multithread --with-mpi=no \
		--with-ginac=no
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	METIS CHACO
OPTIONS_RADIO=	BLAS
OPTIONS_RADIO_BLAS=	REFERENCE GOTOBLAS ATLAS
OPTIONS_DEFAULT=	REFERENCE

ATLAS_DESC=	ATLAS
CHACO_DESC=	Enable chaco-support
GOTOBLAS_DESC=	GotoBLAS2
METIS_DESC=	Enable metis-support
REFERENCE_DESC=	Blas / Lapack

ATLAS_CONFIGURE_ON=	--with-blas=atlas
ATLAS_USES=	blaslapack:atlas

CHACO_BUILD_DEPENDS=	${LOCALBASE}/lib/libchaco.a:math/chaco
CHACO_CONFIGURE_ON=	--with-chaco=yes
CHACO_CONFIGURE_OFF=	--with-chaco=no

GOTOBLAS_CONFIGURE_ON=	--with-blas=goto --with-goto=goto2
GOTOBLAS_USES=	blaslapack:gotoblas

METIS_CONFIGURE_ON=	--with-metis=yes
METIS_CONFIGURE_OFF=	--with-metis=no
METIS_CPPFLAGS=		-I${LOCALBASE}/include/metis
METIS_LIB_DEPENDS=	libmetis.so:math/metis

REFERENCE_CONFIGURE_ON=	--with-blas=blas
REFERENCE_USES=	blaslapack:netlib

pre-configure:
	${REINPLACE_CMD} -e '/try_lapack_LIBS=/s/-llapack/${LAPACKLIB}/' \
		-e 's/ -lxerbla//; s/-lcholmod/-lcholmod ${BLASLIB} ${LAPACKLIB} -lsuitesparseconfig/'	\
		${WRKSRC}/configure

.include <bsd.port.mk>
