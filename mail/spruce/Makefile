# New ports collection makefile for:	spruce
# Date created:		05 June 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spruce
PORTVERSION= 	0.6.5
CATEGORIES=	mail
MASTER_SITES=	http://www.xtorshun.org/spruce/v0.6/ \
		http://fundy.linuxberg.com/files/x11/network/

MAINTAINER=	erich@tacni.net

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG=	${LOCALBASE}/bin/glib12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${GTK_CONFIG} GLIB_CONFIG=${GLIB_CONFIG} \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"
USE_GMAKE=	yes

MAN1=		spruce.1

.include <bsd.port.mk>
