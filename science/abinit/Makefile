# Created by: NAKATA Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abinit
DISTVERSIONPREFIX=	v
DISTVERSION=	9.4.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Full-featured atomic-scale first-principles simulation software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le

BUILD_DEPENDS=	gm4:devel/m4	\
		${PYNUMPY}	\
		${PY_PYGMENTS}	\
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphviz>0:graphics/py-graphviz@${PY_FLAVOR}
LIB_DEPENDS=	libelpa.so:math/elpa		\
		libsz.so:science/szip		\
		libelpa.so:math/elpa		\
		libxc.so:science/libxc		\
		libfftw3.so:math/fftw3		\
		libhdf5.so:science/hdf5		\
		libxml2.so:textproc/libxml2	\
		libnetcdf.so:science/netcdf	\
		libxmlf90.so:textproc/xmlf90	\
		libwannier.so:science/wannier90	\
		libnetcdff.so:science/netcdf-fortran
RUN_DEPENDS=	atompaw:science/atompaw
TEST_DEPENDS=	${PYNUMPY}	\
		libyaml>0:textproc/libyaml

USES=		autoreconf:build blaslapack:netlib fortran gmake gnome localbase:ldflags	\
		python:3.7+ shebangfix
USE_GITHUB=	yes
USE_GNOME=	libxml2
SHEBANG_FILES=	config/scripts/* doc/tutorial/paral_gspw_assets/abinit.sub.*
SHEBANG_GLOB=	*.py
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC_LDFLAGS="${LDFLAGS}" CXX_LDFLAGS="${LDFLAGS}" FC_LDFLAGS="${LDFLAGS}"	\
		LINALG_FCFLAGS="-I${LOCALBASE}/include/elpa-2019.05.002/modules"	\
		LINALG_LIBS="${BLASLIB}  ${LAPACKLIB} -lelpa"	\
		NETCDF_FORTRAN_FCFLAGS=-I${LOCALBASE}/include	\
		XMLF90_FCFLAGS=-I${LOCALBASE}/include	\
		WANNIER90_LIBS="${BLASLIB}  ${LAPACKLIB} -lwannier"
CONFIGURE_ARGS=	--with-fft --with-libxc --with-libxml2 --with-netcdf	\
		--with-netcdf-fortran --with-wannier90 --with-xmlf90
FCFLAGS+=	-ffree-line-length-none
TEST_TARGET=	tests_abirules tests_buildsys
TEST_WRKSRC=	${WRKSRC}/abichecks
PORTDOCS=	*

OPTIONS_DEFINE=			DOCS OPENMP MPI
OPTIONS_DEFAULT=		OPENMP MPI

OPENMP_CONFIGURE_ENABLE=	openmp
OPENMP_LDFLAGS=			-lomp

MPI_CONFIGURE_WITH=		mpi=yes
# fftw3 not enabled because libfftw3_mpi is required but not packaged
MPI_VARS=			FFLAGS+=-I${LOCALBASE}/include FCFLAGS+=-I${LOCALBASE}/include	\
				CONFIGURE_ENV+=MPI_LIBS="`pkg-config --libs mpich` -lmpifort"	\
				CONFIGURE_ENV+MPI_LDFLAGS="`pkg-config --libs mpich` -lmpifort"
MPI_BUILD_DEPENDS=		mpich>0:net/mpich
MPI_RUN_DEPENDS=		mpich>0:net/mpich

.if defined(WITH_LEVMAR)
# --with-levmar seems deprecated
LIB_DEPENDS+=	liblevmar.so:math/levmar
CONFIGURE_ENV+=	LEVMAR_LIBS="-llevmar ${BLASLIB} ${LAPACKLIB}"
CONFIGURE_ARGS+=	--with-levmar
.endif

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
FCFLAGS+=	-fallow-argument-mismatch # see https://github.com/abinit/abinit/issues/41
.endif

pre-configure:
	(cd ${WRKSRC} && ./autogen.sh)

post-install-DOCS-on:
	${REINPLACE_CMD} -e 's|/usr/bin/env  python|${PYTHON_CMD}|'	\
		${WRKSRC}/doc/tutorial/paral_moldyn_assets/diag_moldyn.py
	${RM} ${WRKSRC}/doc/tutorial/paral_moldyn_assets/diag_moldyn.py.bak
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/tutorial ${STAGEDIR}${DOCSDIR}

pre-test:
	${TOUCH} ${TEST_WRKSRC}/make.log

.include <bsd.port.post.mk>
