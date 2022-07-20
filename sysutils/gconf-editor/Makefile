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
