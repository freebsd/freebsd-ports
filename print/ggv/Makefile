# New ports collection makefile for:	ggv
# Version required:			0.26
# Date created:				21 August 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.2 1999/01/12 16:50:28 vanilla Exp $
#

DISTNAME=	ggv-0.26
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/latest/ \
		ftp://ftp.geo.net/pub/gnome/sources/latest/ \
		ftp://gnomeftp.wgn.net/pub/gnome/sources/latest/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/latest/

MAINTAINER=	nacai@iname.com

RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
LIB_DEPENDS=	gnomeui.1:${PORTSDIR}/x11/gnomelibs

BROKEN=		"gnome 0.99.3"

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include \
		-I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11d-config" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

.include <bsd.port.mk>
