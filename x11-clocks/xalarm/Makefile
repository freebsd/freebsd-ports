# New ports collection makefile for:	xalarm
# Version required:	3.06
# Date created:		4 December 1996
# Whom:			desmo@bandwidth.org
#
# $Id: Makefile,v 1.1.1.1 1997/02/17 09:30:15 tg Exp $
#

DISTNAME=	xalarm-3.06
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities

MAINTAINER=	desmo@bandwidth.org

USE_IMAKE=	yes
IS_INTERACTIVE=	yes

pre-install:	
	(cd ${WRKSRC} ; ${CP} XAlarm.ad XAlarm-color.ad)

.include <bsd.port.mk>

