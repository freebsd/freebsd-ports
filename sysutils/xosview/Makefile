# New ports collection makefile for:	xosview
# Version required:	1.7.0
# Date created:		19 Nov 1997
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $Id: Makefile,v 1.13 1999/01/18 03:00:39 steve Exp $
#

DISTNAME=	xosview-1.7.1
CATEGORIES=	sysutils
MASTER_SITES=	http://lore.ece.utexas.edu/~bgrayson/xosview/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/status/xstatus

MAINTAINER=	handy@physics.montana.edu

FETCH_BEFORE_ARGS=	-b
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
MAN1=		xosview.1

# BROKEN=	SwapMeter broken for 4.0+

.include <bsd.port.mk>
