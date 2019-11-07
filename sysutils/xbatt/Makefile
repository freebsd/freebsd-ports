# Created by: Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
# $FreeBSD$

PORTNAME=	xbatt
PORTVERSION=	1.2.1
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.clave.gr.jp/~eto/xbatt/

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Laptop battery status display for X11

ONLY_FOR_ARCHS=	amd64 i386

USES=		imake:noman xorg
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
PLIST_FILES=	"@(,operator,2755) bin/xbatt"

.include <bsd.port.mk>
