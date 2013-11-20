# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/gconf-editor/Makefile 18897 2013-11-18 16:14:39Z kwm $

PORTNAME=	gconf-editor
PORTVERSION=	3.0.1
PORTEPOCH=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gconf database editor for the GNOME 3 environment

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intlhack gtk30 gconf2 gnomedocutils
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gconf-editor.schemas

.include <bsd.port.mk>
