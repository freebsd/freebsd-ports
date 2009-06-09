# New ports collection makefile for:    xbattbar
# Date created:		Fri Feb 18 10:05:12 JST 2000
# Whom:                 sumikawa
#
# $FreeBSD$
#

PORTNAME=	xbattbar
PORTVERSION=	1.4.2
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://iplab.aist-nara.ac.jp/member/suguru/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Simple battery meter

USE_IMAKE=	yes
USE_XORG=	x11 xext
WRKSRC=		${WRKDIR}/xbattbar-${PORTVERSION}
MAN1=		xbattbar.1
PLIST_FILES=	bin/xbattbar

.include <bsd.port.mk>
