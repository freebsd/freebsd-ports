# New ports collection makefile for:	net/appkonference
# Date created:				19 October 2010
# Whom:					Alex Deiter <Alex.Deiter@Gmail.COM>
#
# $FreeBSD$
#

PORTNAME=	appkonference
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	alex.deiter@gmail.com
COMMENT=	High-performance Asterisk voice/video conferencing plugin

BUILD_DEPENDS=  asterisk:${PORTSDIR}/net/asterisk16
RUN_DEPENDS=    asterisk:${PORTSDIR}/net/asterisk16

USE_GMAKE=	yes
MAKE_ENV=	LOCALBASE=${LOCALBASE}
WRKSRC=		${WRKDIR}/${PORTNAME}/konference

PLIST_FILES=	lib/asterisk/modules/app_konference.so

.include <bsd.port.mk>
