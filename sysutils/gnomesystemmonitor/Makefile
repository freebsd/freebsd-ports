# New ports collection makefile for:   gtop
# Version required:    0.28.1
# Date created:        28 September 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.1.1.1 1998/10/10 13:44:01 vanilla Exp $
#

DISTNAME=	gtop-0.28.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.home-of-linux.org/pub/gtop/0.28.1/

MAINTAINER=	Nakai@technologist.com

LIB_DEPENDS=	gnome.0:${PORTSDIR}/x11/gnomelibs \
		gtop.0:${PORTSDIR}/devel/libgtop

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include \
		-I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

post-install:
		chown root.kmem ${PREFIX}/bin/gtop
		chmod 2555 ${PREFIX}/bin/gtop

.include <bsd.port.mk>
