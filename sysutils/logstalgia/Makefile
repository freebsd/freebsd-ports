# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	logstalgia
PORTVERSION=	1.0.7
CATEGORIES=	sysutils www

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Website access log visualization tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libfreetype.so:print/freetype2 \
		libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libftgl.so:graphics/ftgl

USE_GITHUB=	yes
GH_ACCOUNT=	acaudwell
GH_PROJECT=	Logstalgia:DEFAULT Core:core
GH_TAGNAME=	d99bdb2:DEFAULT 83eba3a:core

GNU_CONFIGURE=	yes
USES=		autoreconf compiler:c++0x gmake jpeg localbase:ldflags pkgconfig
USE_GL=		gl glu glew
USE_SDL=	image2 sdl2

post-extract:
	@${MV} ${WRKDIR}/Core-83eba3a/* ${WRKSRC}/src/core/

post-patch:
	@${REINPLACE_CMD} -e 's| -Wno-unused-but-set-variable||' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
