# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	diffmark
PORTVERSION=	0.10
CATEGORIES=	textproc
MASTER_SITES=	http://www.mangrove.cz/diffmark/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML diff and merge package

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USES=		pkgconfig
USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-libxml2-incldir=${LOCALBASE}/include/libxml2

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
