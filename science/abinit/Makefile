PORTNAME=	abinit
DISTVERSION=	9.10.3
PORTREVISION=	3
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Full-featured atomic-scale first-principles simulation software
WWW=		https://www.abinit.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le

BUILD_DEPENDS=	gm4:devel/m4	\
		${PYNUMPY}	\
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphviz>0:graphics/py-graphviz@${PY_FLAVOR}
LIB_DEPENDS=	libelpa.so:math/elpa		\
		libsz.so:science/libaec		\
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
		python shebangfix
USE_GITHUB=	yes
USE_GNOME=	libxml2
SHEBANG_FILES=	config/scripts/* doc/tutorial/paral_bandpw_assets/abinit.sub.*
SHEBANG_GLOB=	*.py
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	H5CC="${LOCALBASE}/bin/h5cc" \
		HDF5_CFLAGS="-I${LOCALBASE}/include" \
		HDF5_LDFLAGS="-L${LOCALBASE}/lib -lhdf5" \
		LINALG_FCFLAGS="-I${LOCALBASE}/include/elpa-2019.05.002/modules"	\
		LINALG_LIBS="${BLASLIB}  ${LAPACKLIB} -lelpa"	\
		NETCDF_FORTRAN_FCFLAGS=-I${LOCALBASE}/include	\
		XMLF90_FCFLAGS=-I${LOCALBASE}/include	\
		WANNIER90_LIBS="${BLASLIB}  ${LAPACKLIB} -lwannier"
CONFIGURE_ARGS=	--with-fft --with-libxc --with-libxml2 --with-netcdf	\
		--with-netcdf-fortran --with-wannier90 --with-xmlf90
FCFLAGS+=	-ffree-line-length-none
TEST_TARGET=	tests_abirules tests_buildsys # Many tests print RuntimeError, https://github.com/abinit/abinit/issues/64
TEST_WRKSRC=	${WRKSRC}/abichecks
PORTDOCS=	*

OPTIONS_DEFINE=			DOCS OPENMP OPENMPI
OPTIONS_DEFAULT=		OPENMP OPENMPI

OPENMP_CONFIGURE_ENABLE=	openmp
OPENMP_LDFLAGS=			-lomp

OPENMPI_CONFIGURE_WITH=		mpi=yes
# BROKEN with MPICH4: see <https://github.com/abinit/abinit/issues/61>
# To set back to mpich when this issue will be fixed.
OPENMPI_USES=			mpi:openmpi
# fftw3 not enabled because libfftw3_mpi is required but not packaged
OPENMPI_VARS=			FCFLAGS+="`pkg-config --cflags ompi-fort`"
OPENMPI_CONFIGURE_ENV=		CC_LDFLAGS="${MPI_LIBS} ${LDFLAGS}"	\
				CXX_LDFLAGS="${MPI_LIBS} ${LDFLAGS}"	\
				FC_LDFLAGS="${MPI_LIBS} ${LDFLAGS}"	\
				CFLAGS="${MPI_CFLAGS} ${CFLAGS}  ${CFLAGS_F2018}"	\
				MPI_CPPFLAGS="${MPI_CFLAGS}"	\
				MPI_FCFLAGS="`pkg-config --cflags ompi-fort`"	\
				MPI_LIBS="${MPI_LIBS}"	\
				MPI_LDFLAGS="${MPI_LIBS}"
# When OpenMPI is enabled, put its related variables 1st to avoid conflicts with MPICH
OPENMPI_CONFIGURE_ENV_OFF=	CC_LDFLAGS="${LDFLAGS}" CXX_LDFLAGS="${LDFLAGS}"	\
				FC_LDFLAGS="${LDFLAGS}" CFLAGS="${CFLAGS}"

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
