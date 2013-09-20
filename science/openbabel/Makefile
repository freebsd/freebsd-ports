# Created by: ijliao
# $FreeBSD$

PORTNAME=	openbabel
PORTVERSION=	2.3.2
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

MAN1=		babel.1 \
		obabel.1 \
		obchiral.1 \
		obconformer.1 \
		obenergy.1 \
		obfit.1 \
		obgen.1 \
		obgrep.1 \
		obgui.1 \
		obminimize.1 \
		obprobe.1 \
		obprop.1 \
		obrotamer.1 \
		obrotate.1 \
		obspectrophore.1 \
		roundtrip.1

PLIST_SUB=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=	CAIRO PYTHON
OPTIONS_DEFAULT=	PYTHON
CAIRO_DESC=	PNG support via cairo library

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCAIRO}
LIB_DEPENDS+=	cairo:${PORTSDIR}/graphics/cairo
PLIST_SUB+=	CAIRO=""
.else
PLIST_SUB+=	CAIRO="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
CMAKE_ARGS+=	-DPYTHON_BINDINGS=on
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "
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
