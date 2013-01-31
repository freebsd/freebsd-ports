# Created by: Yuri <yuri@tsoft.com>
# $FreeBSD$

PORTNAME=	assimp
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}-3.0
DISTNAME=	${PORTNAME}--${PORTVERSION}.1270-source-only

MAINTAINER=	yuri@tsoft.com
COMMENT=	Library to import various 3D model formats in a uniform manner

LICENSE=	BSD

LIB_DEPENDS=	boost_filesystem:${PORTSDIR}/devel/boost-libs

USE_ZIP=	yes
USE_CMAKE=	yes
USE_PKGCONFIG=	build
USE_GCC=	4.6+ # 4.2+ causes compiler warnings
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

# CMAKE_ARGS instructs cmake to skip runtime path removal during install
CMAKE_ARGS+=	"-DCMAKE_SKIP_RPATH=ON"

post-patch:
	@${REINPLACE_CMD} 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
