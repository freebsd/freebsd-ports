# New ports collection makefile for:	wmwave
# Date created:		27 December 2001
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmwave
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display 802.11 status in the WindowMaker Dock

MAKEFILE=	${FILESDIR}/Makefile
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_XPM=	yes
MAKE_ENV=	MANPREFIX=${MANPREFIX}

MAN1=		wmwave.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/wmwave

# configure is a no-op for this port.
do-configure:

.include <bsd.port.mk>
