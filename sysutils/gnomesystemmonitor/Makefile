# New ports collection makefile for:	gtop
# Version required:			0.99.2
# Date created:				28 September 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.6 1999/01/27 08:31:52 fenner Exp $
#

DISTNAME=	gtop-0.99.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME} \
		ftp://ftp.home-of-linux.org/pub/gtop/0.99.2/
MASTER_SITE_SUBDIR=	gtop

MAINTAINER=	nacai@iname.com

RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
LIB_DEPENDS=	gtop.1:${PORTSDIR}/devel/libgtop

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11d-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

post-install:
		chown root.kmem ${PREFIX}/bin/gtop
		chmod 2555 ${PREFIX}/bin/gtop

.include <bsd.port.mk>
