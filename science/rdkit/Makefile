PORTNAME=	rdkit
DISTVERSIONPREFIX=	Release_
DISTVERSION=	2025_09_2
CATEGORIES=	science
MASTER_SITES=	https://github.com/schrodinger/maeparser/archive/:maeparser \
		https://github.com/schrodinger/coordgenlibs/archive/:coordgen \
		https://codeload.github.com/Glysade/chemdraw/tar.gz/refs/tags/:chemdraw \
		https://github.com/Tencent/rapidjson/archive/:rapidjson \
		LOCAL/yuri/:font # unstable, changing font file: https://fonts.google.com/download?family=Comic%20Neue&dummy=/:font
DISTFILES=	v${MAEPARSER_VERSION}.tar.gz:maeparser \
		v${COORDGEN_VERSION}.tar.gz:coordgen \
		v${CHEMDRAW_VERSION}:chemdraw \
		v${RAPIDJSON_VERSION}.tar.gz:rapidjson \
		ComicNeue-Regular.ttf:font
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	${DISTFILES:C/:.*//:Nv*:N*.ttf}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of cheminformatics and machine-learning software
WWW=		https://www.rdkit.org/ \
		https://github.com/rdkit/rdkit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BROKEN_FreeBSD_16_amd64=	clang crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=272652

BUILD_DEPENDS=	catch>0:devel/catch \
		flex:textproc/flex
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libfreetype.so:print/freetype2

USES=		bison:build cmake:testing compiler:c++11-lang eigen:3 gnome pkgconfig python
USE_GNOME=	cairo
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TUPLE=	rareylab:RingDecomposerLib:v1.1.3_rdkit:RingDecomposerLib/External/RingFamilies/RingDecomposerLib
GH_TUPLE+=	ncbi:pubchem-align3d:daefab3:align3d/External/pubchem_shape/pubchem-align3d \
		aantron:better-enums:520d8ee:better_enums/better_enums

MAEPARSER_VERSION=	1.3.3
COORDGEN_VERSION=	3.0.2
CHEMDRAW_VERSION=	1.0.11
RAPIDJSON_VERSION=	1.1.0

CMAKE_ON=	RDK_BUILD_CAIRO_SUPPORT
CMAKE_OFF=	RDK_INSTALL_INTREE RDK_USE_FLEXBISON \
		RDK_INSTALL_STATIC_LIBS RDK_SWIG_STATIC RDK_PGSQL_STATIC \
		RDK_OPTIMIZE_NATIVE \
		RDK_BUILD_CPP_TESTS
CMAKE_ARGS=	-DCATCH_DIR=${LOCALBASE}/include/catch2

CFLAGS+=	-D_GNU_SOURCE
CXXFLAGS+=	-D_GNU_SOURCE
		#-I${WRKSRC}/better_enums

DATADIR=	${PREFIX}/share/RDKit
DOCSDIR=	${PREFIX}/share/doc/RDKit

#		RDBASE=${STAGEDIR}${PREFIX}
TEST_ENV=	${MAKE_ENV} \
		RDBASE=${WRKSRC} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

OPTIONS_DEFINE=		DOCS PGSQL PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

DOCS_CMAKE_BOOL=	FREEBSD_INSTALL_DOCS
DOCS_CMAKE_ON=		-DFREEBSD_DOCSDIR:PATH=${DOCSDIR}

PGSQL_USES=		pgsql
PGSQL_DESC=		Build the PostgreSQL cartridge
PGSQL_CMAKE_BOOL=	RDK_BUILD_PGSQL

PYTHON_CMAKE_BOOL=	RDK_BUILD_PYTHON_WRAPPERS
PYTHON_BUILD_DEPENDS=	${PYNUMPY}
PYTHON_LIB_DEPENDS=	${PY_BOOST}
PYTHON_RUN_DEPENDS=	${PYNUMPY} \
			${PY_PILLOW} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${PY_FLAVOR}

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc || ${ARCH} == powerpc64
PLIST_SUB+=	LITTLE_ENDIAN="@comment "
.else
PLIST_SUB+=	LITTLE_ENDIAN=""
.endif

post-extract:
	#@${MKDIR} ${WRKSRC}/External/rapidjson-1.1.0
	#@cd ${WRKSRC}/External/rapidjson-1.1.0 && ${LN} -s ${LOCALBASE}/include/rapidjson include
	@cd ${WRKSRC}/Data/Fonts && ${CP} ${DISTDIR}/${DIST_SUBDIR}/ComicNeue-Regular.ttf .
	@${CP} ${WRKSRC}/better_enums/enum.h ${WRKSRC}/Code/RDGeneral

post-patch:
	# replace the URLs for fetched libs with the local file path to the distfiles, so that it can be used without internet access
	@${REINPLACE_CMD} \
		-e 's|https://github.com/schrodinger/maeparser/archive/|file://${DISTDIR}/${DIST_SUBDIR}/|g' \
		${WRKSRC}/External/CoordGen/CMakeLists.txt
	@${REINPLACE_CMD} \
		-e 's|https://github.com/schrodinger/coordgenlibs/archive/|file://${DISTDIR}/${DIST_SUBDIR}/|g' \
		${WRKSRC}/External/CoordGen/CMakeLists.txt
	@${REINPLACE_CMD} \
		-e 's|https://codeload.github.com/Glysade/chemdraw/tar.gz/refs/tags/|file://${DISTDIR}/${DIST_SUBDIR}/|g' \
		${WRKSRC}/External/ChemDraw/CMakeLists.txt
	@${REINPLACE_CMD} \
		-e 's|https://github.com/Tencent/rapidjson/archive/|file://${DISTDIR}/${DIST_SUBDIR}/|g' \
		${WRKSRC}/Code/GraphMol/MolInterchange/CMakeLists.txt

pre-build:
	@${REINPLACE_CMD} \
		-e 's|const SizeType length;|SizeType length;|g' \
		${WRKSRC}/External/rapidjson/rapidjson-1.1.0/include/rapidjson/document.h

post-install:
	@${RM} -f ${STAGEDIR}${PREFIX}/lib/libexpat.a

post-install-PGSQL-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/rdkit.so

# many tests fail, see https://github.com/rdkit/rdkit/issues/7779
# tests as of 2025_09_1: 65% tests passed, 24 tests failed out of 68
# tests as of 2025_09_2: 63% tests passed, 26 tests failed out of 70

.include <bsd.port.mk>
