PORTNAME=	vqcc-gtk
DISTVERSION=	0.5
PORTREVISION=	11
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	mirror176@hotmail.com
COMMENT=	LAN chat client compatible with quickChat and Vypress Chat (TM)
WWW=		https://vqcc-gtk.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification

USES=		gettext gmake gnome pkgconfig xorg
USE_GNOME=	gdkpixbufextra gnomeprefix gtk20
USE_XORG=	ice sm x11 xext xscrnsaver
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/vqcc-gtk \
		share/applications/vqcc-gtk.desktop \
		share/locale/lt/LC_MESSAGES/vqcc-gtk.mo \
		share/locale/ru/LC_MESSAGES/vqcc-gtk.mo \
		share/pixmaps/vqcc-gtk.png

.include <bsd.port.mk>
