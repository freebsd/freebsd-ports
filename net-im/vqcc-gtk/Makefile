# New ports collection makefile for:	vqcc-gtk
# Date created:			07 Sep 2004
# Whom:				Saulius Menkevicius <bob@nulis.lt>
# $FreeBSD$
#

PORTNAME=	vqcc-gtk
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES?=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER?=	bob@nulis.lt
COMMENT=	LAN chat client compatible with quickChat and Vypress Chat (TM)

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomeprefix
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}" \
		PTHREAD_LIB="${PTHREAD_LIBS}"

.include <bsd.port.mk>
