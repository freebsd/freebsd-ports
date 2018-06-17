# $FreeBSD$

PORTNAME=	rdkit
DISTVERSIONPREFIX=	Release_
DISTVERSION=	2018_03_2
CATEGORIES=	science

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	fe443fcb429e69ef13219a7b5c6dd53544042cbf.patch:-p1 # fix the SONAMEs regression

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of cheminformatics and machine-learning software

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	flex:textproc/flex \
		rapidjson>=0:devel/rapidjson
LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		bison:build cmake:outsource eigen:3 python
USE_GITHUB=	yes
GH_TUPLE=	schrodinger:maeparser:1.0.0:maeparser/External/CoordGen/maeparser \
		schrodinger:coordgenlibs:ede3191:coordgenlibs/External/CoordGen/coordgenlibs
USE_LDCONFIG=	yes

CMAKE_OFF=	RDK_INSTALL_INTREE RDK_USE_FLEXBISON \
		RDK_INSTALL_STATIC_LIBS RDK_SWIG_STATIC RDK_PGSQL_STATIC
CMAKE_ARGS=	-DFREEBSD_DOCSDIR:PATH=${DOCSDIR}

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
			${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${PY_FLAVOR}

PORTDOCS=	*

post-extract:
	@${MKDIR} ${WRKSRC}/External/rapidjson-1.1.0
	@cd ${WRKSRC}/External/rapidjson-1.1.0 && ${LN} -s ${LOCALBASE}/include/rapidjson include

.include <bsd.port.mk>
