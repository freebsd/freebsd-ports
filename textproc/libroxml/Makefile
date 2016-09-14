# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	libroxml
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	gaod@hychen.org
COMMENT=	Minimum, easy-to-use, C implementation for xml file parsing

LICENSE=	LGPL21

BROKEN=		Unfetchable (google code has gone away)

PROJECTHOST=	libroxml

USES=		gmake
# Workaround overwriting DESTDIR var
DESTDIRNAME=	NONE
MAKE_ARGS=	DESTDIR=${STAGEDIR}${PREFIX}
USE_LDCONFIG=	yes

PLIST_FILES=	bin/roxml \
		lib/libroxml.so \
		lib/libroxml.so.0 \
		lib/libroxml.a \
		include/roxml.h \
		libdata/pkgconfig/libroxml.pc \
		man/man1/roxml.1.gz

pre-build:
	@cd ${WRKSRC} && ${MAKE_CMD} clean

.include <bsd.port.mk>
