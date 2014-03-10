# Created by: Yuri <yuri@tsoft.com>
# $FreeBSD$

PORTNAME=	assimp
PORTVERSION=	3.0
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}-3.0
DISTNAME=	${PORTNAME}--${PORTVERSION}.1270-source-only

MAINTAINER=	yuri@tsoft.com
COMMENT=	Library to import various 3D model formats in a uniform manner

LICENSE=	BSD

LIB_DEPENDS=	libboost_filesystem.so:${PORTSDIR}/devel/boost-libs

USES=		cmake pkgconfig zip
USE_GCC=	yes	# GCC 4.2 causes compiler warnings
USE_LDCONFIG=	yes

# CMAKE_ARGS instructs cmake to skip runtime path removal during install
CMAKE_ARGS+=	"-DCMAKE_SKIP_RPATH=ON"

post-patch:
	@${REINPLACE_CMD} 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
