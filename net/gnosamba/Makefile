# New ports collection makefile for:	gtksamba
# Version required:			0.3.1
# Date created:				4 November 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.4 1998/12/08 16:14:58 vanilla Exp $
#

DISTNAME=	gtksamba-0.3.1
CATEGORIES=	net
MASTER_SITES=	http://www.open-systems.com/gtksamba/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	gnomeui.1:${PORTSDIR}/x11/gnomelibs

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk11d-config"

.include <bsd.port.mk>
