# $FreeBSD$

PORTNAME=	twirssi
PORTVERSION=	2.8.0
CATEGORIES=	net-im

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Twitter script to irssi

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Twitter-API>=0:net/p5-Twitter-API \
		p5-WWW-Shorten>=0:www/p5-WWW-Shorten \
		p5-WWW-Shorten-Bitly>=0:www/p5-WWW-Shorten-Bitly \
		irssi:irc/irssi

SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	gedge
GH_TAGNAME=	2579820

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	${DATADIR}/${PORTNAME}.pl

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} -v ${WRKSRC}/${PORTNAME}.pl ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
