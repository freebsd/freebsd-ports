# Created by: Manuel Rabade Garica <mig@mig-29.net>
# $FreeBSD$

PORTNAME=	xfce4-wavelan-plugin
PORTVERSION=	0.5.11
PORTREVISION=	1
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Displays various information about a WaveLAN device

GNU_CONFIGURE=	yes
USES=		gettext pkgconfig gmake libtool tar:bzip2
USE_GNOME=	gtk20 glib20 intltool intlhack
USE_XFCE=	configenv libutil libmenu panel

.include <bsd.port.mk>
