# Created by: Igor Pokrovsky <tiamat@comset.net>

PORTNAME=	gl2ps
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	print graphics
MASTER_SITES=	http://www.geuz.org/gl2ps/src/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	C library providing vector output for OpenGL applications

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake gl tar:tgz
USE_GL=		gl
USE_LDCONFIG=	yes
PLIST_SUB=	SHLIB_VER=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
