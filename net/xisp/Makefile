# New ports collection makefile for:	xisp
# Date created:		June 24, 1999
# Whom:			tm@onepost.net
#
# $FreeBSD$
#

PORTNAME=	xisp
PORTVERSION=	2.7p4
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://xisp.hellug.gr/release/

PATCH_SITES=	http://www.ml-search.com/xisp/distfiles/

MAINTAINER=	tm@onepost.net
COMMENT=	A user-friendly X interface to pppd/chat

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms

USE_XORG=	xpm

MAKE_ENV+=	CCFLAGS="${CFLAGS}"

MAN1=		xisp.1

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
