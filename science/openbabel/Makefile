# Created by: ijliao
# $FreeBSD$

PORTNAME=	openbabel
PORTVERSION=	2.3.2
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Chemistry file translation program

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	${LOCALBASE}/include/eigen3/Eigen/Eigen:math/eigen3

CONFLICTS_INSTALL=	babel-*

USE_GNOME=	libxml2
USES=		cmake:outsource
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
	${REINPLACE_CMD} -e 's,share/man,man,' \
		${WRKSRC}/doc/CMakeLists.txt

post-patch-CAIRO-off:
	${REINPLACE_CMD} -e '/find_package(Cairo)/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
