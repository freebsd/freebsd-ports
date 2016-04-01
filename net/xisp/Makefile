# Created by: tm@onepost.net
# $FreeBSD$

PORTNAME=	xisp
PORTVERSION=	2.7p4
PORTREVISION=	9
CATEGORIES=	net
MASTER_SITES=	http://xisp.hellug.gr/release/

PATCH_SITES=	http://www.ml-search.com/xisp/distfiles/

MAINTAINER=	tm@onepost.net
COMMENT=	User-friendly X interface to pppd/chat

LIB_DEPENDS=	libforms.so:x11-toolkits/xforms

USE_XORG=	xpm

MAKE_ENV+=	CCFLAGS="${CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
