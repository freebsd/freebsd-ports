PORTNAME=	code_saturne
PORTVERSION=	8.1.1
PORTREVISION=	5
CATEGORIES=	science parallel
MASTER_SITES=	https://www.code-saturne.org/releases/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	EDF's general purpose Computational Fluid Dynamics (CFD) software
WWW=		https://www.code-saturne.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${MPI4PY}	\
		gsed:textproc/gsed
LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo	\
		libcgns.so:science/cgnslib	\
		libpetsc.so:science/PETSc	\
		libHYPRE.so:science/hypre	\
		libhdf5.so:science/hdf5		\
		libscotch.so:cad/scotch		\
		libsmumps.so:math/mumps		\
		libcblas.so:math/cblas		\
		libmedC.so:french/med
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}	\
		${MPI4PY}	\
		xmgrace:math/grace	\
		bash:shells/bash	\
		xterm:x11/xterm

USES=		autoreconf bison blaslapack compiler:c11 fortran gettext gnome gmake \
		iconv localbase libtool mpi pyqt:5 python shebangfix xorg
USE_GNOME=	libxml2
USE_PYQT=	pyqt5
USE_XORG=	x11
SHEBANG_FILES=	install_saturne.py tests/unittests.py build-aux/*.py
CFLAGS+=	-D__XSI_VISIBLE -Wno-error=incompatible-function-pointer-types
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-salome --without-salome-yacs --without-salome-kernel	\
		--without-salome-gui --enable-python	\
		--with-blas=yes --with-blas-type=BLAS	\
		--with-blas-include=${LOCALBASE}/include/cblas	\
		--with-blas-lib=${LOCALBASE}/lib	\
		--with-hypre="${LOCALBASE}" --with-mpi	\
		--with-mumps="${LOCALBASE}" --with-petsc="${LOCALBASE}"	\
		--with-scotch-include="${LOCALBASE}/include"
CONFIGURE_ENV=	ac_cv_path_SED=${LOCALBASE}/bin/gsed ldflags_rpath="-R"	\
		MUMPS_LIBS="-lmpiseq -llapack"
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
BINARY_ALIAS=	python=${PYTHON_CMD} \
		pyrcc5=pyrcc5-${PYTHON_VER} \
		pyuic5=pyuic5-${PYTHON_VER}

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	METIS
OPTIONS_RADIO=		METIS
OPTIONS_RADIO_METIS=	METIS PARMETIS
OPTIONS_SUB=		yes
METIS_DESC=		Support of METIS
METIS_LIB_DEPENDS=	libmetis.so:math/metis
METIS_CONFIGURE_ON=	--with-metis-include="${LOCALBASE}/include"
PARMETIS_DESC=		Support of ParMETIS
PARMETIS_LIB_DEPENDS=	libparmetis.so:math/parmetis
PARMETIS_CONFIGURE_ON=	--with-metis-include="${LOCALBASE}/include/parmetis"	\
			--with-metis-lib="${LOCALBASE}/lib"
PARMETIS_CONFIGURE_ENV=	LIBS=-lexecinfo

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
.else
CONFIGURE_ARGS+=	--enable-openmp
.endif

.if ${PORT_OPTIONS:MDOCS}
USES+=		tex
USE_TEX=	tex:build
BUILD_DEPENDS+=	fig2dev:print/fig2dev		\
		doxygen:devel/doxygen		\
		dot:graphics/graphviz		\
		dvips:print/tex-dvipsk		\
		${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
BINARY_ALIAS+=	sphinx-build=sphinx-build-${PYTHON_VER}
ALL_TARGET=	all pdf
DOCS=		AUTHORS ChangeLog README
PORTDOCS=	*
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|'	\
		${WRKSRC}/Makefile.am
	${REINPLACE_CMD} -e 's|make -s|${GMAKE} -s|' ${WRKSRC}/m4/cs_petsc.m4
.for cs in config/cs_auto_flags.sh libple/config/ple_auto_flags.sh
	${REINPLACE_CMD} -e 's|fopenmp=libomp|fopenmp|' ${WRKSRC}/${cs}
.endfor

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/code_saturne/cs_solver

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:C|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
