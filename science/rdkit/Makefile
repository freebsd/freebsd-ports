# $FreeBSD$

PORTNAME=	rdkit
DISTVERSIONPREFIX=	Release_
DISTVERSION=	2018_09_3
PORTREVISION=	6
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of cheminformatics and machine-learning software

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	catch>0:devel/catch \
		flex:textproc/flex \
		rapidjson>=0:devel/rapidjson
LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		bison:build cmake compiler:c++11-lang eigen:3 python
USE_GITHUB=	yes
GH_TUPLE=	schrodinger:maeparser:1.0.0:maeparser/External/CoordGen/maeparser \
		schrodinger:coordgenlibs:ede3191:coordgenlibs/External/CoordGen/coordgenlibs
USE_LDCONFIG=	yes

CMAKE_OFF=	RDK_INSTALL_INTREE RDK_USE_FLEXBISON \
		RDK_INSTALL_STATIC_LIBS RDK_SWIG_STATIC RDK_PGSQL_STATIC \
		RDK_OPTIMIZE_NATIVE
CMAKE_ARGS=	-DFREEBSD_DOCSDIR:PATH=${DOCSDIR} -DCATCH_DIR=${LOCALBASE}

DATADIR=	${PREFIX}/share/RDKit
DOCSDIR=	${PREFIX}/share/doc/RDKit

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

OPTIONS_DEFINE=		PYTHON DOCS
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_CMAKE_BOOL=	RDK_BUILD_PYTHON_WRAPPERS
PYTHON_BUILD_DEPENDS=	${PYNUMPY}
PYTHON_LIB_DEPENDS=	${PY_BOOST}
PYTHON_RUN_DEPENDS=	${PYNUMPY} \
			${PY_PILLOW} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${PY_FLAVOR}

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH:Marm*} || ${ARCH} == i386 || ${ARCH:Mmips*el*} || ${ARCH} == riscv
PLIST_SUB+=	LITTLE_ENDIAN=""
.else
PLIST_SUB+=	LITTLE_ENDIAN="@comment "
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/External/rapidjson-1.1.0
	@cd ${WRKSRC}/External/rapidjson-1.1.0 && ${LN} -s ${LOCALBASE}/include/rapidjson include

post-stage: # https://github.com/rdkit/rdkit/issues/2094
	#@${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake
	#@${MV} ${STAGEDIR}${PREFIX}/lib/*.cmake ${STAGEDIR}${PREFIX}/lib/cmake

.include <bsd.port.mk>
