# New ports collection makefile for:	xmms
# Version required:		0.9.1
# Date created:			3 July 1999
# Whom:				Espen Skoglund <espensk@stud.cs.uit.no>
#
# $FreeBSD$
#

DISTNAME=	xmms-0.9.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.xmms.org/xmms/0.9/

MAINTAINER=	espensk@stud.cs.uit.no

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		glib12.2:${PORTSDIR}/devel/glib12

USE_LIBTOOL=	yes
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk12-config \
 		GLIB_CONFIG=${LOCALBASE}/bin/glib12-config

.include <bsd.port.mk>
