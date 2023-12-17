PORTNAME=	cadabra2
DISTVERSION=	2.4.4.1
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Computer algebra system for solving field theory problems
WWW=		https://cadabra.science/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/doc/license.txt

BROKEN_FreeBSD_15=	compilation fails with clang-17, see https://github.com/kpeeters/cadabra2/issues/285

BUILD_DEPENDS=	${LOCALBASE}/include/websocketpp/client.hpp:devel/websocketpp
LIB_DEPENDS=	${PY_BOOST} \
		libboost_system.so:devel/boost-libs \
		libharfbuzz.so:print/harfbuzz \
		libpcrecpp.so:devel/pcre \
		libjsoncpp.so:devel/jsoncpp \
		libgmp.so:math/gmp \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/sympy/__init__.py:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/matplotlib/__init__.py:math/py-matplotlib@${PY_FLAVOR}

USES=		compiler:c++14-lang cmake:noninja dos2unix gettext-runtime gnome localbase:ldflags pkgconfig python sqlite tex # USES=python picks random python versions
USE_GNOME=	glib20 glibmm libsigc++20
USE_TEX=	base latex texhash

USE_GITHUB=	yes
GH_ACCOUNT=	kpeeters

DOS2UNIX_FILES=	cmake/version.cmake

CMAKE_ON=	ENABLE_SYSTEM_JSONCPP USE_PYTHON_3 # OFF doesn't work, still links to python3: https://github.com/kpeeters/cadabra2/issues/76
CMAKE_OFF=	ENABLE_MATHEMATICA
CXXFLAGS+=	-I${LOCALBASE}/include/jsoncpp
LDFLAGS+=	-ljsoncpp

PLIST_SUB=	_PY_SONAME=${_PY_SONAME}

OPTIONS_DEFINE=		GUI
OPTIONS_DEFAULT=	GUI
OPTIONS_SUB=		yes

GUI_USES=		desktop-file-utils
GUI_USE=		GNOME=gtkmm30,gdkpixbuf2
GUI_CMAKE_BOOL=		ENABLE_FRONTEND

_PY_SONAME=	${PYTHON_EXT_SUFFIX}

post-extract: # unbundle
	@${RM} -r ${WRKSRC}/libs/jsoncpp ${WRKSRC}/libs/websocketpp

.include <bsd.port.mk>
