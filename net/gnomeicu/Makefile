# New ports collection makefile for:	gtkicq
# Version required:		0.56
# Date created:			Oct 15 1998
# Whom:				Vanilla Pooh Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.5 1999/01/12 16:50:45 vanilla Exp $
#

DISTNAME=	gtkicq-0.56
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bse.bg/pub/Unix/icq/ \
		ftp://ftp.infodrom.north.de/pub/unix/gtk-etc/apps/gtkicq/ \
		ftp://ftp.rnd.runnet.ru/pub/unix/GUI_Toolkits/gtk/

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	gnome.1:${PORTSDIR}/x11/gnomelibs \
		panel_applet.0:${PORTSDIR}/x11/gnomecore

BROKEN=		"gtkicq 0.58 is out"

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include \
		-I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

.include <bsd.port.mk>
