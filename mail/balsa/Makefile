# New ports collection makefile for:   balsa
# Version required:    0.4.6.2
# Date created:        02 December 1998
# Whom:                Glenn Johnson <gljohns@bellsouth.net>
#
# $Id: Makefile,v 1.1.1.1 1998/12/09 05:20:02 vanilla Exp $
#

DISTNAME=	balsa-0.4.6.2
CATEGORIES=	mail
MASTER_SITES=	http://www.balsa.net/dist/

MAINTAINER=	gljohns@bellsouth.net

LIB_DEPENDS=	gnome.1:${PORTSDIR}/x11/gnomelibs \
		PropListgnome.1:${PORTSDIR}/devel/libPropListgnome

BROKEN=		"can't work with gnomelibs-0.99.3"

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include \
		-I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

MAN1=		balsa.1

.include <bsd.port.mk>
