# New ports collection makefile for:	amcl
# Date created:				15 Apr 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	gnome-mud
PORTVERSION=	0.11.2
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-based MUD client with triggers, aliases, colors, etc

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		gnet-2.0.0:${PORTSDIR}/net/gnet2

USE_BZIP2=	yes
USE_GNOME=	gconf2 gnomehack gnomeprefix intlhack libglade2 vte
USE_GSTREAMER=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_ICONS=	yes

MAN6=		gnome-mud.6
GCONF_SCHEMAS=	gnome-mud.schemas

.include <bsd.port.mk>
