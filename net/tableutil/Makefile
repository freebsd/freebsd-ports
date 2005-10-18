# New ports collection makefile for:	tableutil
# Date created:				19 September 2005
# Whom:					jameskamlyn@gmail.com
#
# $FreeBSD$
#

PORTNAME=	tableutil
PORTVERSION=	0.6
CATEGORIES=	net
MASTER_SITES=	http://expiretable.fnord.se/

MAINTAINER=	jameskamlyn@gmail.com
COMMENT=	Utility for converting and aggregating lists of IP addresses

PLIST_FILES=	bin/tableutil
MAN1=		tableutil.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1/

.include <bsd.port.mk>
