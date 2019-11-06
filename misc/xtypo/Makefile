# Created by: Takeshi MUTOH <tmutoh@mx10.freecom.ne.jp>
# $FreeBSD$

PORTNAME=	xtypo
PORTVERSION=	1.02
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.intec.co.jp/pub/utils/

MAINTAINER=	mutoh@openedu.org
COMMENT=	X-based keyboard trainer

BROKEN=		unfetchable

PLIST_FILES=	bin/xtypo
USES=		imake xorg
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
ALL_TARGET=	xtypo

WRKSRC=		${WRKDIR}/xtypo

.include <bsd.port.mk>
