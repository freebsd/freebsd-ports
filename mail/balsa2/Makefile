# New ports collection makefile for:	balsa
# Version required:			0.4.9
# Date created:				02 December 1998
# Whom:					Glenn Johnson <gljohns@bellsouth.net>
#
# $Id: Makefile,v 1.3 1999/02/03 08:09:51 asami Exp $
#

DISTNAME=	balsa-0.4.9
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME} \
		http://www.balsa.net/dist/
MASTER_SITE_SUBDIR=	balsa

MAINTAINER=	gljohns@bellsouth.net

RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
LIB_DEPENDS=	gnome.1:${PORTSDIR}/x11/gnomelibs \
		PropList.1:${PORTSDIR}/devel/libPropList

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11d-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

MAN1=		balsa.1

post-install:
		${INSTALL_MAN} ${WRKSRC}/balsa.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
