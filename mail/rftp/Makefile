# New ports collection makefile for:	rftp
# Version required:     	1.2
# Date created:			13 Dec, 1997
# Whom:				kline
#
# $FreeBSD$
#

DISTNAME=	rftp-1.2
CATEGORIES=	mail
MASTER_SITES=	ftp://toxic.magnesium.net/pub/FreeBSD/rftp/

MAINTAINER=	kline@thought.org

MAN1=		rftp.1 uucat.1

#	rftp's `make install' stinks, do it properly here
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rftp ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/uucat ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rftp.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/uucat.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
