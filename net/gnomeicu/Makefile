# New ports collection makefile for:	gtkicq
# Version required:		0.55
# Date created:			Oct 15 1998
# Whom:				Vanilla Pooh Shu <vanilla@FreeBSD.ORG>
#
# $Id:$
#

DISTNAME=	gtkicq-0.55
CATEGORIES=	net
MASTER_SITES=	ftp://ncis.ml.org/pub/gtkicq/

MAINTAINER=	Nakai@technologist.com

LIB_DEPENDS=	gnome.0:${PORTSDIR}/x11/gnomelibs

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
