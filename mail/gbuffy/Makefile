# New ports collection makefile for:	gbuffy
# Date created:		2 October 1999
# Whom:			kaj@Raditex.se
#
# $FreeBSD$
#

PORTNAME=	gbuffy
PORTVERSION= 	0.2.2
CATEGORIES=	mail
MASTER_SITES=	http://www.fiction.net/blong/programs/gbuffy/

MAINTAINER=	kaj@Raditex.se

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		PropList.2:${PORTSDIR}/devel/libPropList \
		compface.1:${PORTSDIR}/mail/faces

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
