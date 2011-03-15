# New ports collection makefile for:	SS
# Date created:				5 January 1997
# Whom:					Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	ss
PORTVERSION=	1.3.3
CATEGORIES=	math
MASTER_SITES=	http://www.netsw.org/office/ \
		http://ftp.de.cw.net/pub/netsw/office/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A curses-based SpreadSheet program

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/ss_133
MAN1=		ss.1 pss.1

PLIST_FILES=	bin/ss bin/pss

do-configure:
	@${CP} ${WRKSRC}/config.bsd  ${WRKSRC}/config.h

.include <bsd.port.mk>
