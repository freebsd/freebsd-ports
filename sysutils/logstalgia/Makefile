PORTNAME=	logstalgia
DISTVERSION=	1.1.4
PORTREVISION=	10
CATEGORIES=	sysutils www
MASTER_SITES=	https://github.com/acaudwell/${PORTNAME}/releases/download/${DISTNAME}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Website access log visualization tool
WWW=		https://logstalgia.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libfreetype.so:print/freetype2 \
		libftgl.so:graphics/ftgl \
		libpcre2-8.so:devel/pcre2 \
		libpng.so:graphics/png

USES=		autoreconf compiler:c++0x gl jpeg localbase:ldflags pkgconfig \
		sdl xorg
USE_GL=		gl glew glu
USE_SDL=	image2 sdl2
USE_XORG=	x11

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's| -Wno-unused-but-set-variable||' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
