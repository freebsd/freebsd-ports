# New ports collection makefile for:	SS
# Date created:				5 January 1997
# Whom:					Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	ss
PORTVERSION=	1.3.3
CATEGORIES=	math
MASTER_SITES=	http://www.irus.rri.on.ca/~amulder/ss/ \
		ftp://ftp.u-aizu.ac.jp/pub/misc/tools/spreadsheet/ualberta/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/ss_133
MAN1=		ss.1 pss.1

do-configure:
	@${CP} ${WRKSRC}/config.bsd  ${WRKSRC}/config.h

.include <bsd.port.mk>
