# New ports collection makefile for:	xosview
# Version required:	1.7.1
# Date created:		19 Nov 1997
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $Id: Makefile,v 1.14 1999/03/14 18:12:25 billf Exp $
#

DISTNAME=	xosview-1.7.1
CATEGORIES=	sysutils
MASTER_SITES=	http://lore.ece.utexas.edu/~bgrayson/xosview/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/status/xstatus

MAINTAINER=	ports@freebsd.org

FETCH_BEFORE_ARGS=	-b
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
MAN1=		xosview.1

# BROKEN=	SwapMeter broken for 4.0+

.include <bsd.port.mk>
