# ex:ts=8
# New ports collection makefile for:	bidwatcher
# Date created:		24 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=		bidwatcher
PORTVERSION=		1.3.15
PORTREVISION?=		1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		mph@FreeBSD.org
COMMENT=		Bid monitor for eBay

PLIST_FILES=		bin/bidwatcher
USE_GNOME=		gtk12
GNU_CONFIGURE=		YES

MAN1=			bidwatcher.1

CFLAGS+=		-UHAVE_GMTIME -DHAVE_TM_ZONE

.include <bsd.port.mk>
