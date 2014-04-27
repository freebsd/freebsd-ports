# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	xfce4-mount-plugin
PORTVERSION=	0.6.7
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Mount and umount utility for the Xfce4 panel

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GNOME=	intltool intlhack
USES=		gettext pkgconfig gmake tar:bzip2
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_XFCE=	configenv libmenu panel

.include <bsd.port.mk>
