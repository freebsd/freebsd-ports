# Created by: Manuel Rabade Garica <mig@mig-29.net>
# $FreeBSD$

PORTNAME=	xfce4-wavelan-plugin
PORTVERSION=	0.5.12
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Displays various information about a WaveLAN device

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
USES=		gettext pkgconfig gmake libtool xfce tar:bzip2
USE_GNOME=	gtk20 glib20 intltool intlhack
USE_XFCE=	panel

.include <bsd.port.mk>
