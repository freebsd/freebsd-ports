# New ports collection makefile for:	wmitime
# Version required:	0.3
# Date created:		14 March 1999
# Whom:			Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	wmitime-0.3
CATEGORIES=	x11-clocks windowmaker afterstep
MASTER_SITES=	http://www.neotokyo.org/illusion/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/wmitime/wmitime

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmitime ${PREFIX}/bin

.include <bsd.port.mk>
