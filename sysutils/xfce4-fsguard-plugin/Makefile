# Created by: Matt Lancereau <matt@rimasec.net>
# $FreeBSD$

PORTNAME=	xfce4-fsguard-plugin
PORTVERSION=	1.1.1
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Panel plugin which displays free space of mountpoint

# COPYING file is wrong compared to license header
LICENSE=	BSD2CLAUSE

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce xorg
USE_GNOME=	cairo gtk30 intltool
USE_XFCE=	panel
USE_XORG=	x11

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
