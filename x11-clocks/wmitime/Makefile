# New ports collection makefile for:	wmitime
# Date created:		14 March 1999
# Whom:			Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmitime
PORTVERSION= 	0.3
CATEGORIES=	x11-clocks windowmaker afterstep
MASTER_SITES=	http://www.neotokyo.org/illusion/downloads/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/wmitime/wmitime

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmitime ${PREFIX}/bin

.include <bsd.port.mk>
