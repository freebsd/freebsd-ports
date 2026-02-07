PORTNAME=	mbdyn
DISTVERSION=	1.7.3
PORTREVISION=	19
CATEGORIES=	science
MASTER_SITES=	https://www.mbdyn.org/userfiles/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MultiBody Dynamics analysis system
WWW=		https://www.mbdyn.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc=		does not compile on powerpc

BUILD_DEPENDS=	libatomic_ops>0:devel/libatomic_ops
LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libarpack.so:math/arpack-ng \
		libumfpack.so:math/suitesparse-umfpack

USES=		compiler:c++11-lib fortran gmake libtool:build localbase
USE_LDCONFIG=	yes
USE_CXXSTD=	c++14 # fix build breakage with clang16 due to use of deprecated feature 'dynamic exception specifications', see https://public.gitlab.polimi.it/DAER/mbdyn/-/issues/339

CPPFLAGS+=	-fpermissive -I${LOCALBASE}/include/suitesparse

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--program-prefix='' --enable-multithread --with-mpi=no \
		--with-ginac=no

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	METIS CHACO
OPTIONS_RADIO=	BLAS
OPTIONS_RADIO_BLAS=	REFERENCE ATLAS
OPTIONS_DEFAULT=	REFERENCE

ATLAS_DESC=	ATLAS
CHACO_DESC=	Enable chaco-support
METIS_DESC=	Enable metis-support
REFERENCE_DESC=	Blas / Lapack

ATLAS_CONFIGURE_ON=	--with-blas=atlas
ATLAS_USES=	blaslapack:atlas

CHACO_BUILD_DEPENDS=	${LOCALBASE}/lib/libchaco.a:math/chaco
CHACO_CONFIGURE_ON=	--with-chaco=yes
CHACO_CONFIGURE_OFF=	--with-chaco=no

METIS_CONFIGURE_ON=	--with-metis=yes
METIS_CONFIGURE_OFF=	--with-metis=no
METIS_CPPFLAGS=		-I${LOCALBASE}/include/metis
METIS_LIB_DEPENDS=	libmetis.so:math/metis

REFERENCE_CONFIGURE_ON=	--with-blas=blas
REFERENCE_USES=	blaslapack:netlib

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch in argument 't' at (1); passed REAL(4) to INTEGER(4)
# in theory, this should set FCFLAGS, but the port does not conform
FFLAGS+=	-fallow-argument-mismatch
.endif

pre-configure:
	${REINPLACE_CMD} -e '/try_lapack_LIBS=/s/-llapack/${LAPACKLIB}/' \
		-e 's/ -lxerbla//; s/-lcholmod/-lcholmod ${BLASLIB} ${LAPACKLIB} -lsuitesparseconfig/'	\
		${WRKSRC}/configure

.include <bsd.port.post.mk>
