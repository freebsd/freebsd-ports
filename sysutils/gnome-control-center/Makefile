# New ports collection makefile for:	control-center
# Version required:			1.0.5
# Date created:				29 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.9 1999/04/08 18:08:37 steve Exp $
#

DISTNAME=	control-center-1.0.5
PKGNAME=	gnomecontrolcenter-1.0.5
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/control-center

MAINTAINER=	vanilla@FreeBSD.ORG

BUILD_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore

USE_LIBTOOL=	yes
LIBTOOL=	${LOCALBASE}/bin/libtool
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk12-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
