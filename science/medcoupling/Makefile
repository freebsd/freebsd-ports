PORTNAME=	medcoupling
DISTVERSION=	9.14.0
CATEGORIES=	science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Powerful library to manipulate meshes and fields
WWW=		https://docs.salome-platform.org/latest/dev/MEDCoupling/developer/index.html

LICENSE=	LGPL21

BUILD_DEPENDS=	salome-configuration>0:science/salome-configuration	\
		swig:devel/swig
LIB_DEPENDS=	libmed.so:french/med	\
		libsysinfo.so:devel/libsysinfo	\
		libhdf5-110.so:science/hdf5-110	\
		libcppunit.so:devel/cppunit\
		libboost_thread.so:devel/boost-libs
BUILD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}	\
			${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		cmake:noninja gnome iconv localbase:ldflags python shebangfix
USE_GNOME=	libxml2
SHEBANG_FILES=	src/MEDLoader/Swig/ConvertMEDFileTo30.py	\
		src/MEDLoader/Swig/ConvertMEDFileTo33.py	\
		src/MEDLoader/Swig/case2med src/MEDLoader/Swig/med2case	\
		v8_work/medcoup7to8.py

SHTAGNAME=	c3928d335
TAGNAME=	c3928d3350e96d4dae18752dbdb4c3e71d7c08dc
TARNAME=	${PORTNAME}-${SHTAGNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}-${SHTAGNAME}-${TAGNAME}
CFLAGS+=	-I${LOCALBASE}/include/hdf5-110
LDFLAGS+=	-Wl,--allow-shlib-undefined -lsysinfo
BINARY_ALIAS=	python3=${PYTHON_CMD}

CMAKE_ARGS=	-DCONFIGURATION_ROOT_DIR=${LOCALBASE}/share/salome/configuration	\
		-DSALOME_CXX_STANDARD=17	\
		-DMEDCOUPLING_GIT_SHA1=${PORTVERSION}-${SHTAGNAME}	\
		-DHDF5_INCLUDE_DIR:PATH=${LOCALBASE}/include/hdf5-110	\
		-DHDF5_INCLUDE_DIRS:PATH=${LOCALBASE}/include/hdf5-110	\
		-DHDF5_LIBRARIES=libhdf5-110.so
CMAKE_ON=	MEDCOUPLING_MICROMED		\
		MEDCOUPLING_ENABLE_PYTHON	\
		MEDCOUPLING_USE_64BIT_IDS
CMAKE_OFF=	MEDCOUPLING_ENABLE_RENUMBER	\
		MEDCOUPLING_MEDLOADER_USE_XDR	\
		MEDCOUPLING_PARTITIONER_PARMETIS\
		MEDCOUPLING_PARTITIONER_METIS	\
		MEDCOUPLING_PARTITIONER_SCOTCH	\
		MEDCOUPLING_BUILD_TESTS		\
		MEDCOUPLING_BUILD_DOC
.if defined(MAINTAINER_MODE)
CMAKE_ARGS+=	--trace-expand
.endif
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS MPICH
OPTIONS_SUB=	yes

MPICH_USES=		mpi
MPICH_LIB_DEPENDS=	libptscotch.so:cad/scotch
MPICH_CMAKE_BOOL=	MEDCOUPLING_USE_MPI	\
			MEDCOUPLING_PARTITIONER_PTSCOTCH
MPICH_CMAKE_ON=		-DMPI_C_COMPILER=${MPICC}	\
			-DMPI_CXX_COMPILER=${MPICXX}

pre-configure:
.for d in MEDLoader/Test ParaMEDMEMTest
	${REINPLACE_CMD} -e 's|%%BUILDDIR%%|${CONFIGURE_WRKSRC}|g'	\
		${WRKSRC}/src/${d}/CMakeLists.txt
.endfor
	${REINPLACE_CMD} -e 's|MEDCOUPLING_GIT_SHA1|"${PORTVERSION}"|'	\
		${WRKSRC}/src/PyWrapping/medcoupling.i

post-configure_:
	# Avoid conflict with science/hdf5 if it has been found
	${REINPLACE_CMD} -E -e 's|libhdf5.so.* |libhdf5-110.so.103 |'	\
		-e 's|libhdf5.so.*$$|libhdf5-110.so.103|'	\
		${CONFIGURE_WRKSRC}/build.ninja

post-stage:
	cd ${STAGEDIR}${PREFIX}/lib && ( \
		for l in `${FIND} . -type f -name "lib*.so" `; do \
			${MV} $$l $${l}.${PORTVERSION}; \
			${LN} -sf $${l}.${PORTVERSION} $${l}.${PORTVERSION:R:R}; \
			${LN} -sf $${l}.${PORTVERSION} $${l}; \
		done; \
	)
	${RM} -rf ${STAGEDIR}${PREFIX}/adm_local
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/MEDCoupling
	${MV} ${STAGEDIR}${PREFIX}/cmake_files/*.cmake	\
		${STAGEDIR}${PREFIX}/lib/cmake/MEDCoupling
	${RM} -rf ${STAGEDIR}${PREFIX}/cmake_files
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MV} ${STAGEDIR}${PREFIX}/tests ${STAGEDIR}${DATADIR}

post-stage-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
