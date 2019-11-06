# Created by: Matt Jibson <dolmant@dolmant.net>
# $FreeBSD$

PORTNAME=	relaydb
PORTVERSION=	1.8
CATEGORIES=	mail
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Spam relay database

BROKEN=		unfetchable

PLIST_FILES=	bin/relaydb \
		man/man8/relaydb.8.gz

post-patch:
	${REINPLACE_CMD} 's|-Werror|-Wno-error|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/relaydb ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/relaydb.8.gz ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
