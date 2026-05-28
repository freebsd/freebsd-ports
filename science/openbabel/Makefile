PORTNAME=	openbabel
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	3-2-0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chemical toolbox designed to speak the many languages of chemical data
WWW=		https://openbabel.org/ \
		https://github.com/openbabel/openbabel

LICENSE=	GPLv2+

BUILD_DEPENDS=	rapidjson>0:devel/rapidjson
LIB_DEPENDS=	libmaeparser.so:science/maeparser	\
		libcoordgen.so:science/coordgenlibs	\
		libboost_thread.so:devel/boost-libs

USES=		cmake:testing compiler:c++11-lang eigen:3 gnome perl5 pkgconfig tar:bz2
USE_CXXSTD=	c++11
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_GITHUB=	yes
USE_PERL5=	build

CMAKE_ON=	WITH_COORDGEN WITH_JSON OPENBABEL_USE_SYSTEM_RAPIDJSON WITH_MAEPARSER
CMAKE_OFF=	ENABLE_TESTS PYTHON_BINDINGS
CMAKE_TESTING_ON=	ENABLE_TESTS

CONFLICTS_INSTALL=	babel

PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=		CAIRO GUI
OPTIONS_DEFAULT=	CAIRO GUI
OPTIONS_SUB=		yes

CAIRO_DESC=		PNG support via cairo library
CAIRO_USE=		GNOME=cairo

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

# tests as of 3.2.0: 100% tests passed, 0 tests failed out of 337

.include <bsd.port.post.mk>
