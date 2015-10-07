# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-minicmd-plugin
PORTVERSION=	0.4
PORTREVISION=	18
CATEGORIES=	sysutils xfce
MASTER_SITES=	ftp://ftp.berlios.de/pub/xfce-goodies/panel-plugins/4.4/
DIST_SUBDIR=	xfce4

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Displays a mini-command line on the xfce4-panel

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-10-31

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pkgconfig xfce tar:bzip2
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	libgui panel

CONFIGURE_ARGS=--disable-static

.include <bsd.port.mk>
