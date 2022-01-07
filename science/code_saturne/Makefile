# Created by: thierry@pompo.net

PORTNAME=	code_saturne
PORTVERSION=	7.1.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	science parallel

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	EDF's general purpose Computational Fluid Dynamics (CFD) software

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed
LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo	\
		libcgns.so:science/cgnslib	\
		libhdf5.so:science/hdf5		\
		libmedC.so:french/med
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}	\
		xmgrace:math/grace	\
		bash:shells/bash	\
		xterm:x11/xterm

USE_GITHUB=	yes
GH_ACCOUNT=	code-saturne

USES=		autoreconf bison compiler:c11 fortran gettext gnome gmake \
		iconv localbase libtool pyqt:5 python:3.7+ shebangfix xorg
USE_GNOME=	libxml2
USE_PYQT=	core gui sip widgets xml_build
USE_XORG=	x11
SHEBANG_FILES=	install_saturne.py tests/unittests.py bin/*.py build-aux/*.py
CFLAGS+=	-D__XSI_VISIBLE
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-salome --without-salome-yacs --without-salome-kernel	\
		--without-salome-gui --enable-python
CONFIGURE_ENV=	ac_cv_path_SED=${LOCALBASE}/bin/gsed
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
BINARY_ALIAS=	python=${PYTHON_CMD} \
		pyrcc5=pyrcc5-${PYTHON_VER} \
		pyuic5=pyuic5-${PYTHON_VER}

OPTIONS_DEFINE=		DOCS EXAMPLES BATCH BLAS HYPRE MPICH MUMPS PETSC SCOTCH
OPTIONS_DEFAULT=	BATCH BLAS HYPRE METIS MPICH MUMPS PETSC SCOTCH
OPTIONS_RADIO=		METIS
OPTIONS_RADIO_METIS=	METIS PARMETIS
OPTIONS_SUB=		yes
BLAS_DESC=		Support of BLAS
BLAS_USES=		blaslapack
BLAS_CONFIGURE_ON=	--with-blas=yes --with-blas-type=BLAS	\
			--with-blas-include=${LOCALBASE}/include/cblas	\
			--with-blas-lib=${LOCALBASE}/lib
BLAS_LIB_DEPENDS=	libcblas.so:math/cblas
BATCH_DESC=		Use Torque to submit batches
BATCH_RUN_DEPENDS=	pbs-config:sysutils/torque
HYPRE_DESC=		Support of HYPRE
HYPRE_BUILD_DEPENDS=	hypre>0:science/hypre
HYPRE_RUN_DEPENDS=	hypre>0:science/hypre
HYPRE_CONFIGURE_ON=	--with-hypre="${LOCALBASE}"
MPICH_USES=		mpi
MPICH_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpi4py>0:net/py-mpi4py@${PY_FLAVOR}
MPICH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpi4py>0:net/py-mpi4py@${PY_FLAVOR}
MPICH_CONFIGURE_WITH=	mpi
METIS_DESC=		Support of METIS
METIS_LIB_DEPENDS=	libmetis.so:math/metis
METIS_CONFIGURE_ON=	--with-metis-include="${LOCALBASE}/include"
MUMPS_DESC=		Support of MUMPS
MUMPS_LIB_DEPENDS=	libsmumps.so:math/mumps
MUMPS_CONFIGURE_ON=	--with-mumps="${LOCALBASE}"
MUMPS_CONFIGURE_ENV=	MUMPS_LIBS="-lmpiseq -llapack"
PARMETIS_DESC=		Support of ParMETIS
PARMETIS_LIB_DEPENDS=	libparmetis.so:math/parmetis
PARMETIS_CONFIGURE_ON=	--with-metis-include="${LOCALBASE}/include/parmetis"	\
			--with-metis-lib="${LOCALBASE}/lib/parmetis"
PARMETIS_CONFIGURE_ENV=	LIBS=-lexecinfo
PETSC_DESC=		Support of PETSc
PETSC_LIB_DEPENDS=	libpetsc.so:science/PETSc
PETSC_CONFIGURE_ON=	--with-petsc="${LOCALBASE}"
SCOTCH_DESC=		Support of Scotch
SCOTCH_LIB_DEPENDS=	libscotch.so:cad/scotch
SCOTCH_CONFIGURE_ON=	--with-scotch-include="${LOCALBASE}/include"

TEST_TARGET=	check

.if defined(PACKAGE_BUILDING)
TERM=		vt100	# Force for pointyhat to override su
.else
TERM?=		vt100	# Default value needed for tput in jail or tinderbox
.endif

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
# /wrkdirs/usr/ports/science/code_saturne/work/code_saturne-5.3.0/src/apps/.libs
# /libsaturne.so:
# undefined reference to `__atomic_compare_exchange'
CONFIGURE_ARGS+=	--disable-openmp
.endif

.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	tex:build
BUILD_DEPENDS+=	fig2dev:print/fig2dev		\
		doxygen:devel/doxygen		\
		dot:graphics/graphviz		\
		${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
BINARY_ALIAS+=	sphinx-build=sphinx-build-${PYTHON_VER}
ALL_TARGET=	all pdf
DOCS=		AUTHORS ChangeLog README
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|'	\
		${WRKSRC}/Makefile.am

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/code_saturne/cs_solver

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:C|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
