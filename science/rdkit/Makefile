PORTNAME=	rdkit
DISTVERSIONPREFIX=	Release_
DISTVERSION=	2025_03_1
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	LOCAL/yuri/:font # unstable, changing font file: https://fonts.google.com/download?family=Comic%20Neue&dummy=/:font
DISTFILES=	ComicNeue-Regular.ttf:font
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	${DISTFILES:C/:.*//:N*.ttf}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of cheminformatics and machine-learning software
WWW=		https://www.rdkit.org/ \
		https://github.com/rdkit/rdkit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BROKEN_FreeBSD_15_aarch64=	clang-17 crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=272652
BROKEN_FreeBSD_15_amd64=	clang-17 crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=272652
BROKEN_FreeBSD_15_i386=		clang-17 crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=272652

BUILD_DEPENDS=	catch>0:devel/catch \
		flex:textproc/flex \
		rapidjson>=0:devel/rapidjson
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libcoordgen.so:science/coordgenlibs \
		libfreetype.so:print/freetype2 \
		libmaeparser.so:science/maeparser

USES=		bison:build cmake:testing compiler:c++11-lang eigen:3 gnome python
USE_GNOME=	cairo
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TUPLE=	rareylab:RingDecomposerLib:v1.1.3_rdkit:RingDecomposerLib/External/RingFamilies/RingDecomposerLib
GH_TUPLE+=	ncbi:pubchem-align3d:daefab3:align3d/External/pubchem_shape/pubchem-align3d \
		aantron:better-enums:520d8ee:better_enums/better_enums

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
	@${MKDIR} ${WRKSRC}/External/rapidjson-1.1.0
	@cd ${WRKSRC}/External/rapidjson-1.1.0 && ${LN} -s ${LOCALBASE}/include/rapidjson include
	@cd ${WRKSRC}/Data/Fonts && ${CP} ${DISTDIR}/${DIST_SUBDIR}/ComicNeue-Regular.ttf .
	@${CP} ${WRKSRC}/better_enums/enum.h ${WRKSRC}/Code/RDGeneral

post-install-PGSQL-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/rdkit.so

# many tests fail, see https://github.com/rdkit/rdkit/issues/7779

.include <bsd.port.mk>
