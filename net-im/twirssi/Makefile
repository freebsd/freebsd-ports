# $FreeBSD$

PORTNAME=	twirssi
PORTVERSION=	2.6.3
CATEGORIES=	net-im
MASTER_SITES=	http://twirssi.com/
EXTRACT_SUFX=	.pl
EXTRACT_ONLY=

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Twitter script to irssi

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Net-Twitter>=0:net/p5-Net-Twitter \
		p5-WWW-Shorten>=0:www/p5-WWW-Shorten \
		p5-WWW-Shorten-Bitly>=0:www/p5-WWW-Shorten-Bitly \
		irssi:irc/irssi

SUB_FILES=	pkg-message

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	%%DATADIR%%/${PORTNAME}.pl

post-extract:
	@${MKDIR} ${WRKSRC}
	${INSTALL_SCRIPT} ${DISTDIR}/${PORTNAME}-${PORTVERSION}.pl \
		${WRKSRC}/${PORTNAME}.pl

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} -v ${WRKSRC}/${PORTNAME}.pl ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
