# New ports collection makefile for:	wmitime
# Version required:	0.2
# Date created:		14 March 1999
# Whom:			Jim Mock <jim@phrantic.phear.net>
#
# $Id$
#

DISTNAME=	wmitime-0.2
CATEGORIES=	x11-clocks windowmaker afterstep
MASTER_SITES=	http://www.neotokyo.org/illusion/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/wmitime.app/wmitime

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmitime ${PREFIX}/bin

.include <bsd.port.mk>
