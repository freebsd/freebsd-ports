# New ports collection makefile for:	wmweather+-2.4
# Date created:				11 April 2003
# Whom:				Harald Wille <harald.wille@students.jku.at>
#
# $FreeBSD$

PORTNAME=	wmweather+
PORTVERSION=	2.4
CATEGORIES=	misc windowmaker
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wmweatherplus

MAINTAINER=	harald.wille@students.jku.at
COMMENT=	Think wmweather with forecasts, weather map, and a sky cond. display

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

MAN1=		wmweather+.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmweather+ ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmweather+.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
