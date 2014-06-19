# Created by: Sebastien Santoro <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	valspeak
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://dereckson.devio.us/software/${PORTNAME}/

MAINTAINER=	dereckson@gmail.com
COMMENT=	Filter that converts English text to valspeak

CONFLICTS=	filters-2* talkfilters-2*

RESTRICTED=     1986 software shared on the net.sources newsgroup \
		with the intent to redistribute it, but without any \
		license or author information clearly available.

PLIST_FILES=	bin/valspeak
ALL_TARGET=	valspeak
MAKE_ARGS+=	CFLAGS=${CFLAGS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/valspeak ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
