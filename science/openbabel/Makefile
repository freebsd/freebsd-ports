# Created by: ijliao
# $FreeBSD$

PORTNAME=	openbabel
PORTVERSION=	2.4.1
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chemistry file translation program

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	Does not build: relocation truncated to fit: R_PPC64_TOC16_DS

CONFLICTS_INSTALL=	babel-*

USE_CXXSTD=	gnu++98
USE_GNOME=	libxml2
USES=		cmake:outsource eigen:3
CMAKE_ARGS=	-DBUILD_GUI=off
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=	CAIRO PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=	yes

CAIRO_DESC=	PNG support via cairo library
CAIRO_LIB_DEPENDS=	libcairo.so:graphics/cairo
CAIRO_USES=	pkgconfig

PYTHON_USES=	python
PYTHON_CMAKE_ON=	-DPYTHON_BINDINGS=on

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s,$${LIB_INSTALL_DIR},libdata,' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's,man/man1,../man/man1,' \
		${WRKSRC}/doc/CMakeLists.txt

post-patch-CAIRO-off:
	${REINPLACE_CMD} -e '/find_package(Cairo)/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
