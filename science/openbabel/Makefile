PORTNAME=	openbabel
DISTVERSION=	3.1.1
PORTREVISION=	5
DISTVERSIONSUFFIX=	-source
CATEGORIES=	science
MASTER_SITES=	https://github.com/openbabel/openbabel/releases/download/openbabel-${PORTVERSION:C/\./-/g}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chemical toolbox designed to speak the many languages of chemical data

LICENSE=	GPLv2+

BUILD_DEPENDS=	rapidjson>0:devel/rapidjson
LIB_DEPENDS=	libmaeparser.so:science/maeparser	\
		libcoordgen.so:science/coordgenlibs	\
		libboost_thread.so:devel/boost-libs

CONFLICTS_INSTALL=	babel

USES=		cmake compiler:c++11-lang eigen:3 gnome pkgconfig tar:bz2
USE_CXXSTD=	gnu++98
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ON=	WITH_COORDGEN WITH_JSON OPENBABEL_USE_SYSTEM_RAPIDJSON WITH_MAEPARSER
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_SUB=	VERSION=3.1.0	# To be replaced by ${PORTVERSION} nexttime!

OPTIONS_DEFINE=		CAIRO PYTHON GUI
OPTIONS_DEFAULT=	CAIRO PYTHON GUI
OPTIONS_SUB=		yes

CAIRO_DESC=		PNG support via cairo library
CAIRO_USE=		GNOME=cairo

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	PYTHON_BINDINGS

GUI_CMAKE_BOOL=		BUILD_GUI
GUI_CMAKE_ON=		-DwxWidgets_CONFIG_EXECUTABLE:STRING=${WX_CONFIG}
GUI_USE=		WX=3.0

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-Wno-narrowing
USE_CXXSTD=	c++11
.endif

pre-configure:
	${REINPLACE_CMD} -e '/pkgconfig/s,$${LIB_INSTALL_DIR},libdata,' \
		${WRKSRC}/CMakeLists.txt

pre-configure-CAIRO-off:
	${REINPLACE_CMD} -e '/find_package(Cairo)/d' \
		${WRKSRC}/CMakeLists.txt

post-install-PYTHON-on:
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})

.include <bsd.port.post.mk>
