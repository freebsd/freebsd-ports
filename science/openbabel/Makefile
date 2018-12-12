# Created by: ijliao
# $FreeBSD$

PORTNAME=	openbabel
PORTVERSION=	2.4.1
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chemical toolbox designed to speak the many languages of chemical data

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	babel-*

USES=		compiler:c++11-lang cmake:outsource eigen:3 gnome
USE_CXXSTD=	gnu++98
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=	CAIRO PYTHON GUI
OPTIONS_DEFAULT=	PYTHON GUI
OPTIONS_SUB=	yes

CAIRO_DESC=	PNG support via cairo library
CAIRO_USES=	pkgconfig
CAIRO_USE=	GNOME=cairo

PYTHON_USES=	python
PYTHON_CMAKE_BOOL=	PYTHON_BINDINGS

GUI_CMAKE_BOOL=	BUILD_GUI
GUI_CMAKE_ON=	-DwxWidgets_CONFIG_EXECUTABLE:STRING=${WX_CONFIG}
GUI_USE=	WX=3.0

.if exists(/usr/lib/libstdc++.so)
CXXFLAGS+=	-Wno-narrowing
USE_CXXSTD=	c++11
.endif

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s,$${LIB_INSTALL_DIR},libdata,' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's,man/man1,../man/man1,' \
		${WRKSRC}/doc/CMakeLists.txt

post-patch-CAIRO-off:
	${REINPLACE_CMD} -e '/find_package(Cairo)/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
