# New ports collection makefile for:	webcrawl
# Date created:		31 January 1999
# Whom:			Dima Sivachenko
#
# $FreeBSD$
#

PORTNAME=	webcrawl
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/mirroring
EXTRACT_SUFX=	.tgz

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Download web sites without user interaction by following links

ALL_TARGET=

MAN1=		webcrawl.1
PLIST_FILES=	bin/webcrawl

do-install:
		@ ${INSTALL_PROGRAM} ${WRKSRC}/webcrawl ${PREFIX}/bin/
		@ ${INSTALL_MAN} ${WRKSRC}/webcrawl.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
