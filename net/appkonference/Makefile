# New ports collection makefile for:	net/appkonference
# Date created:				19 October 2010
# Whom:					Alex Deiter <Alex.Deiter@Gmail.COM>
#
# $FreeBSD$
#

PORTNAME=	appkonference
PORTVERSION=	2.1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	alex.deiter@gmail.com
COMMENT=	High-performance Asterisk voice/video conferencing plugin

BUILD_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk
RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk

USE_CSTD=	gnu89
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/konference

PLIST_FILES=	lib/asterisk/modules/app_konference.so

ONLY_FOR_ARCHS=		amd64 arm i386 ia64
ONLY_FOR_ARCHS_REASON=	not yet ported to this architecture

.include <bsd.port.mk>
