# New ports collection makefile for:	gtk-gnutella
# Date created:				19 May, 2000
# Whom:					rbt@zort.on.ca
#
# $FreeBSD$
#

PORTNAME=	gtk-gnutella
PORTVERSION=	0.12
CATEGORIES=	net
MASTER_SITES=	http://gtk-gnutella.sourceforge.net/download/ \
		ftp://gtk-gnutella.sourceforge.net/pub/gtk-gnutella/

MAINTAINER=	rbt@zort.on.ca

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
