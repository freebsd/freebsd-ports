# Created by: Olivier Duchateau
# $FreeBSD$
#

PORTNAME=	xfce4-equake-plugin
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	science xfce
MASTER_SITES=	http://www.e-quake.org/wp-uploads/2013/07/
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Earthquake monitor plugin for the Xfce desktop

GNU_CONFIGURE=	yes
USES=	gettext pkgconfig gmake
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_XFCE=	configenv libmenu libutil panel
USE_XORG=	x11
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
