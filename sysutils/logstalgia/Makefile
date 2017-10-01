# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	logstalgia
PORTVERSION=	1.0.8
CATEGORIES=	sysutils www

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Website access log visualization tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to compile: custom.cpp: 'sscanf' was not declared in this scope

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libfreetype.so:print/freetype2 \
		libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libftgl.so:graphics/ftgl

GNU_CONFIGURE=	yes
USES=		autoreconf compiler:c++0x gmake jpeg localbase:ldflags pkgconfig
USE_GL=		gl glu glew
USE_SDL=	image2 sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	acaudwell
GH_PROJECT=	Logstalgia:DEFAULT Core:core
GH_TAGNAME=	32067aa:DEFAULT 683d98b:core

post-extract:
	@${MV} ${WRKDIR}/Core-*/* ${WRKSRC}/src/core/

post-patch:
	@${REINPLACE_CMD} -e 's| -Wno-unused-but-set-variable||' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
