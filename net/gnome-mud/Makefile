# New ports collection makefile for:	amcl
# Date created:				15 Apr 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	gnome-mud
PORTVERSION=	0.10.7
PORTREVISION=	11
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-based MUD client with triggers, aliases, colors, etc

USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnometarget gnomeprefix intlhack libgnomeui \
		pygtk2 vte
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-mccp
INSTALLS_OMF=	yes

MAN6=		gnome-mud.6
GCONF_SCHEMAS=	gnome-mud.schemas

post-patch:
	@${REINPLACE_CMD} -e \
		's|prefix)/games|prefix)/bin|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
