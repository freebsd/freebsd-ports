PORTNAME=	xfce4-appfinder
PORTVERSION=	4.18.1
PORTREVISION=	2
CATEGORIES=	misc xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Application launcher and finder
WWW=		https://www.xfce.org/

LICENSE=	GPLv2

USES=		compiler:c11 gettext-tools gmake gnome pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_XFCE=	garcon libmenu xfconf

GNU_CONFIGURE=	yes

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
