# New ports collection makefile for:	gnumeric
# Version required:			0.5
# Date created:				08 October 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.3 1998/11/18 12:09:05 asami Exp $
#

DISTNAME=	gnumeric-0.5
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/

MAINTAINER=	Nakai@technologist.com

LIB_DEPENDS=	xml.0:${PORTSDIR}/textproc/libxml
LIB_DEPENDS+=	gnome.0:${PORTSDIR}/x11/gnomelibs

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include \
		-I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11d-config" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
