# New ports collection makefile for:   GTK+ Object Builder
# Date created:        25 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gob
PORTVERSION= 	0.93.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ftp.5z.com/pub/gob/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=    gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gob.1

.include <bsd.port.mk>
