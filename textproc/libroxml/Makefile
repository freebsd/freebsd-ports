# New ports collection makefile for:	libroxml
# Date created:         2010-04-16
# Whom:                 Hung-Yi Chen <gaod@hychen.org>
#
# $FreeBSD$
#

PORTNAME=	libroxml
PORTVERSION=	2.1.1
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	gaod@hychen.org
COMMENT=	A minimum, easy-to-use, C implementation for xml file parsing

LICENSE=	LGPL21

PROJECTHOST=	libroxml

USE_GMAKE=	yes
MAKE_ENV+=	DESTDIR=${PREFIX}
USE_LDCONFIG=	yes

MAN1=		roxml.1

PLIST_FILES=	bin/roxml \
		lib/libroxml.so \
		lib/libroxml.so.0 \
		lib/libroxml.a \
		include/roxml.h \
		libdata/pkgconfig/libroxml.pc

pre-build:
	@cd ${WRKSRC} && ${GMAKE} clean

.include <bsd.port.mk>
