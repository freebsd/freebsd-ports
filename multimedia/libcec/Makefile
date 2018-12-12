# Created by: Manuel Creach <manuel.creach@icloud.com>
# $FreeBSD$

PORTNAME=	libcec
PORTVERSION=	4.0.2
PORTREVISION=	6
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	multimedia

MAINTAINER=	mikael.urankar@gmail.com
COMMENT=	Library to control Pulse-Eight's HDMI-CEC adapter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libp8-platform.so:devel/p8-platform

USE_GITHUB=	yes
GH_ACCOUNT=	Pulse-Eight

USES=		alias cmake compiler:c++11-lib pkgconfig shebangfix
SHEBANG_FILES=	src/pyCecClient/pyCecClient.py
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DCMAKE_REQUIRED_INCLUDES:PATH="${LOCALBASE}/include" \
		-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib"

PLIST_SUB=	PORTVERSION="${PORTVERSION}" \
		PORTVERSION_MAJOR="${PORTVERSION:C/([0-9]).*/\1/1}"

OPTIONS_DEFINE=	PYTHON X11
OPTIONS_DEFAULT=	PYTHON X11
OPTIONS_DEFINE_armv6=	RPI
OPTIONS_DEFAULT_armv6=	RPI
OPTIONS_EXCLUDE_armv6=	X11
OPTIONS_SUB=	yes

PYTHON_DESC=	build python wrapper
PYTHON_BUILD_DEPENDS+=	swig3.0:devel/swig30
RPI_DESC=	build libcec support for raspberrypi
RPI_CMAKE_ON=	-DRPI_INCLUDE_DIR=${LOCALBASE}/include -DRPI_LIB_DIR=${LOCALBASE}/lib
RPI_LIB_DEPENDS=	libbcm_host.so:misc/raspberrypi-userland

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python:build
.else
CMAKE_ARGS+=	-DSKIP_PYTHON_WRAPPER:BOOL=true
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11 xorgproto xrandr
.endif

post-patch:
	@${REINPLACE_CMD} 's|$${GIT_REVISION}|${PORTVERSION}|g' \
		${WRKSRC}/src/libcec/cmake/SetBuildInfo.cmake
	@${REINPLACE_CMD} -e '/SOVERSION/ s|\.0||' \
		-e 's|$${CMAKE_INSTALL_LIBDIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/src/libcec/CMakeLists.txt
.if ! ${PORT_OPTIONS:MPYTHON}
	@${REINPLACE_CMD} '/pyCecClient/d' \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
