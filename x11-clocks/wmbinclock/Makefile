# New ports collection makefile for:	wmBinClock
# Date created:			16 Mar 2003
# Whom:				Harold Gutch <logix@foobar.franken.de
#
# $FreeBSD$
#

PORTNAME=	wmbinclock
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.inxsoft.net/wmbinclock/

MAINTAINER=	logix@foobar.franken.de
COMMENT=	A binary clock in a windowmaker applet

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/wmBinClock

post-patch:
	@${REINPLACE_CMD} -e 's|#include <values.h>||' ${WRKSRC}/wmBinClock.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmBinClock ${PREFIX}/bin

.include <bsd.port.mk>
