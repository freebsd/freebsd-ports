# New ports collection makefile for:	glacier
# Date created:		30 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	glacier
PORTVERSION= 	0.0.2
CATEGORIES=	mail gnome
MASTER_SITES=	http://glacier.linuxave.net/

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	gnomeui.3:${PORTSDIR}/x11/gnomelibs

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG=${GTK_CONFIG}
CONFIGURE_ARGS+=--datadir=${PREFIX}/share
USE_GMAKE=	yes

.include <bsd.port.mk>
