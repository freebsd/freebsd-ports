# New ports collection makefile for:	vqcc-gtk
# Date created:			07 Sep 2004
# Whom:				Saulius Menkevicius <bob@nulis.lt>
#
# $FreeBSD$
#

PORTNAME=	vqcc-gtk
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES?=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	LAN chat client compatible with quickChat and Vypress Chat (TM)

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification

USE_GNOME=	gnomehack gnomeprefix gnometarget gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
