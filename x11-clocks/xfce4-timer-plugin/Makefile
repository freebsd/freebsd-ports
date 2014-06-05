# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfce4-timer-plugin
PORTVERSION=	1.6.0
CATEGORIES=	x11-clocks xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Timer plugin for Xfce

LICENSE=	GPLv2

INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_XFCE=	configenv libmenu libutil panel
USES=		pkgconfig gettext gmake tar:bzip2

.include <bsd.port.mk>
