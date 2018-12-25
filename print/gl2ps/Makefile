# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	gl2ps
PORTVERSION=	1.4.0
CATEGORIES=	print graphics
MASTER_SITES=	http://www.geuz.org/gl2ps/src/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	C library providing vector output for OpenGL applications

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake tar:tgz
USE_GL=		gl
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-source

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
