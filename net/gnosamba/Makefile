# New ports collection makefile for:	gtksamba
# Version required:			0.3.1
# Date created:				4 November 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.5 1999/01/17 20:03:29 vanilla Exp $
#

DISTNAME=	gtksamba-0.3.2pl1
CATEGORIES=	net
MASTER_SITES=	http://www.open-systems.com/gtksamba/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	gnomeui.1:${PORTSDIR}/x11/gnomelibs

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"

.include <bsd.port.mk>
