PORTNAME=	abinit
DISTVERSION=	10.2.7
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Full-featured atomic-scale first-principles simulation software
WWW=		https://www.abinit.org \
		https://github.com/abinit/abinit

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
		libnetcdf.so:science/netcdf	\
		libxmlf90.so:textproc/xmlf90	\
		libwannier.so:science/wannier90	\
		libnetcdff.so:science/netcdf-fortran
RUN_DEPENDS=	atompaw:science/atompaw
TEST_DEPENDS=	bash:shells/bash \
		${PYNUMPY} \
		libyaml>0:textproc/libyaml

USES=		autoreconf:build blaslapack:netlib fortran gmake gnome localbase:ldflags	\
		python shebangfix
USE_GITHUB=	yes
USE_GNOME=	libxml2
SHEBANG_FILES=	config/scripts/* doc/tutorial/paral_bandpw_assets/abinit.sub.*
SHEBANG_GLOB=	*.py *.sh
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	H5CC="${LOCALBASE}/bin/h5cc" \
		HDF5_CFLAGS="-I${LOCALBASE}/include" \
		HDF5_LDFLAGS="-L${LOCALBASE}/lib -lhdf5" \
		LINALG_FCFLAGS="-I${LOCALBASE}/include/elpa-2019.05.002/modules"	\
		LINALG_LIBS="${BLASLIB}  ${LAPACKLIB} -lelpa"	\
		NETCDF_FORTRAN_FCFLAGS=-I${LOCALBASE}/include	\
		XMLF90_FCFLAGS=-I${LOCALBASE}/include/xmlf90	\
		WANNIER90_LIBS="${BLASLIB}  ${LAPACKLIB} -lwannier"
CONFIGURE_ARGS=	--with-fft --with-libxc --with-libxml2 --with-netcdf	\
		--with-netcdf-fortran --with-wannier90 --with-xmlf90
FCFLAGS+=	-ffree-line-length-none
TEST_TARGET=	tests_abirules tests_buildsys # Many tests print RuntimeError, https://github.com/abinit/abinit/issues/64
TEST_WRKSRC=	${WRKSRC}/abichecks
PORTDOCS=	*

BINARY_ALIAS=	git=false

OPTIONS_DEFINE=			DOCS OPENMP
OPTIONS_DEFAULT=		MPICH
OPTIONS_RADIO=			MPIX
OPTIONS_RADIO_MPIX=		NOMPI MPICH OPENMPI

OPENMP_CONFIGURE_ENABLE=	openmp
OPENMP_LDFLAGS=			-lomp

MIX_DESC=			MPI options

NOMPI_DESC=			Do not use MPI
NOMPI_CONFIGURE_ON=		CC_LDFLAGS="${LDFLAGS}" CXX_LDFLAGS="${LDFLAGS}"	\
				FC_LDFLAGS="${LDFLAGS}" CFLAGS="${CFLAGS}"

OPENMPI_USES=			mpi:openmpi
OPENMPI_CONFIGURE_ON=		mpi=yes
OPENMPI_VARS=			FCFLAGS+="`pkg-config --cflags ompi-fort`" \
				CFLAGS+="${MPI_CFLAGS}" \
				LDFLAGS+="${MPI_LDFLAGS}"
OPENMPI_CONFIGURE_ENV=		${MPIX_CONFIGURE_ENV} \
				MPI_FCFLAGS="`pkg-config --cflags ompi-fort`"

MPICH_USES=			mpi:mpich
MPICH_CONFIGURE_ON=		mpi=yes
MPICH_VARS=			FFLAGS+=-I${LOCALBASE}/include FCFLAGS+=-I${LOCALBASE}/include	\
				CONFIGURE_ENV+=MPI_LIBS="`pkg-config --libs mpich` -lmpifort"	\
				CONFIGURE_ENV+MPI_LDFLAGS="`pkg-config --libs mpich` -lmpifort"
MPICH_CONFIGURE_ENV=		${MPIX_CONFIGURE_ENV}

MPIX_CONFIGURE_ENV=		CC_LDFLAGS="${MPI_LIBS} ${LDFLAGS}" \
				CXX_LDFLAGS="${MPI_LIBS} ${LDFLAGS}" \
				FC_LDFLAGS="${MPI_LIBS} ${LDFLAGS}" \
				CFLAGS="${MPI_CFLAGS} ${CFLAGS} ${CFLAGS_F2018}" \
				MPI_CPPFLAGS="${MPI_CFLAGS}" \
				MPI_LIBS="${MPI_LIBS}" \
				MPI_LDFLAGS="${MPI_LIBS}"
# When OpenMPI is enabled, put its related variables 1st to avoid conflicts with MPICH

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

pre-configure: # version lines below are workaround for https://github.com/abinit/abinit/issues/75
	@cd ${WRKSRC} && \
		${ECHO} ${PORTVERSION} > .version && \
		${ECHO} ${PORTVERSION} > .tarball-version && \
		./autogen.sh

post-install-DOCS-on:
	${REINPLACE_CMD} -e 's|/usr/bin/env  python|${PYTHON_CMD}|'	\
		${WRKSRC}/doc/tutorial/paral_moldyn_assets/diag_moldyn.py
	${RM} ${WRKSRC}/doc/tutorial/paral_moldyn_assets/diag_moldyn.py.bak
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/tutorial ${STAGEDIR}${DOCSDIR}

pre-test:
	${TOUCH} ${TEST_WRKSRC}/make.log

test-long: # run all examples from tutorial/Input
	@cd ${WRKSRC}/tests/tutorial/Input && \
		for abi in `${LS} *.abi`; do \
			${ECHO} "===> Running example $$abi" && \
			${SETENV} PATH=${STAGEDIR}${PREFIX}/bin:${PATH} ABI_PSPDIR=${WRKSRC}/tests/Psps_for_tests abinit $$abi; \
		done

# fftw3 not enabled because libfftw3_mpi is required but not packaged

.include <bsd.port.post.mk>
