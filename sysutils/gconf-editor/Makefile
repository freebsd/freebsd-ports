# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
#   $MCom: ports/trunk/sysutils/gconf-editor/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	gconf-editor
PORTVERSION=	3.0.1
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gconf database editor for the GNOME 3 environment

USES=		gettext gmake gnome pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix intlhack gtk30 gconf2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gconf-editor.schemas

.include <bsd.port.mk>
