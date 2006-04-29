# New ports collection makefile for:  scand
# Date created:        13 May 2003
# Whom:                sand
#
# $FreeBSD$
#

PORTNAME=	scand
PORTVERSION=	0.14
CATEGORIES=	net
MASTER_SITES=	http://free.babolo.ru/src/ \
		http://www.a.pike.ru/src/

MAINTAINER=	sand@links.ru
COMMENT=	Flood scan detection and blocking daemon

USE_RC_SUBR=	scand

MAN8=		scand.8 scandctl.8
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -E -e "s|(install:.*)installscript(.*)|\1\2|" \
		${WRKSRC}/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
