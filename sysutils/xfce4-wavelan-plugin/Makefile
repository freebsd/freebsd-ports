# Created by: Manuel Rabade Garica <mig@mig-29.net>
# $FreeBSD$

PORTNAME=	xfce4-wavelan-plugin
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Displays various information about a WaveLAN device

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pkgconfig tar:bzip2 xfce:gtk3
USE_GNOME=	gtk30 glib20 intltool cairo gdkpixbuf2
USE_XFCE=	panel
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
