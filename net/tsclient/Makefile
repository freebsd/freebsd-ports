# New ports collection makefile for: 	tsclient
# Date created:				01 Mar 2003
# Whom:					Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	tsclient
PORTVERSION=	0.104
CATEGORIES=	net gnome
MASTER_SITES=	http://www.gnomepro.com/tsclient/

MAINTAINER=	einekoai@chello.nl
COMMENT=	A GNOME 2 frontend for rdesktop

LIB_DEPENDS=	panel-applet-2.0:${PORTSDIR}/x11/gnomepanel
RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	@${LN} -sf ${PREFIX}/share/gnome/pixmaps/tsclient/tsclient.png \
		${PREFIX}/share/gnome/pixmaps/tsclient.png
.include <bsd.port.mk>
