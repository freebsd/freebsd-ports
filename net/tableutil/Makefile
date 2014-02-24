# Created by: jameskamlyn@gmail.com
# $FreeBSD$

PORTNAME=	tableutil
PORTVERSION=	0.6
CATEGORIES=	net
MASTER_SITES=	http://expiretable.fnord.se/

MAINTAINER=	jameskamlyn@gmail.com
COMMENT=	Utility for converting and aggregating lists of IP addresses

PLIST_FILES=	bin/tableutil man/man1/tableutil.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
