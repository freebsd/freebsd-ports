# ex:ts=8
# New ports collection makefile for:	sloccount
# Date created:			May 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sloccount
PORTVERSION=	1.8
CATEGORIES=	misc
MASTER_SITES=	http://www.dwheeler.com/sloccount/

MAINTAINER=	ports@FreeBSD.org

MAKEFILE=	makefile

MANCOMPRESSED=	yes
MAN1=	sloccount.1

pre-install:
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}

.include <bsd.port.mk>
