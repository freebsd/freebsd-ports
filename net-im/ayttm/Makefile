# New ports collection makefile for:	everybuddy
# Version required:		0.1.1
# Date created:			1 Mar 2000
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	everybuddy-0.1.1
CATEGORIES=	net
MASTER_SITES=	http://www.everybuddy.com/files/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		esd.2:${PORTSDIR}/audio/esound

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"

MAN1=		everybuddy.1

.include <bsd.port.mk>
