# Created by: ijliao
# $FreeBSD$

PORTNAME=	openbabel
PORTVERSION=	2.3.2
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Chemistry file translation program

BUILD_DEPENDS=	${LOCALBASE}/include/eigen3/Eigen/Eigen:${PORTSDIR}/math/eigen3

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
CAIRO_LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo
CAIRO_USES=	pkgconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python
CMAKE_ARGS+=	-DPYTHON_BINDINGS=on
.endif

post-patch:
.if !${PORT_OPTIONS:MCAIRO}
	${REINPLACE_CMD} -e '/find_package(Cairo)/d' \
		${WRKSRC}/CMakeLists.txt
.endif
	${REINPLACE_CMD} -e '/pkgconfig/s,$${LIB_INSTALL_DIR},libdata,' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's,share/man,man,' \
		${WRKSRC}/doc/CMakeLists.txt

.include <bsd.port.mk>
