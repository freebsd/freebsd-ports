# New ports collection makefile for:	gtkstep
# Version required:			1.10
# Date Created:				7 nov 98
# Whom:				 	Gilad Rom
#
# $FreeBSD$
#

DISTNAME=	gtkstep-1.10
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ulli.linuxbox.com/gtkstep/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
