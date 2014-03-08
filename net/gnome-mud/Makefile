# Created by: will
# $FreeBSD$

PORTNAME=	gnome-mud
PORTVERSION=	0.11.2
PORTREVISION=	3
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-based MUD client with triggers, aliases, colors, etc

LIB_DEPENDS=	pcre.3:${PORTSDIR}/devel/pcre \
		gnet-2.0.0:${PORTSDIR}/net/gnet2

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
USE_BZIP2=	yes
USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	gconf2 gnomeprefix intlhack libglade2 vte
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
INSTALLS_ICONS=	yes

MAN6=		gnome-mud.6
GCONF_SCHEMAS=	gnome-mud.schemas

NO_STAGE=	yes
.include <bsd.port.mk>
