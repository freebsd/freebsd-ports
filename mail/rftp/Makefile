# Created by: kline
# $FreeBSD$

PORTNAME=	rftp
PORTVERSION=	1.2
CATEGORIES=	mail
MASTER_SITES=	http://muuz.deadbbs.com/FreeBSD/rftp/

MAINTAINER=	kline@thought.org
COMMENT=	Automatically reconstruct ftpmail- or bitftp-retrieved files

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rftp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/uucat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rftp.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/uucat.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
