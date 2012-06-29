# New ports collection makefile for:	twirssi
# Date created:		2009-11-06
# Whom:			garga
#
# $FreeBSD$
#

PORTNAME=	twirssi
PORTVERSION=	2.5.1
CATEGORIES=	net-im
MASTER_SITES=	http://twirssi.com/
EXTRACT_SUFX=	.pl
EXTRACT_ONLY=

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Twitter script to irssi

RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi \
		p5-Net-Twitter>=0:${PORTSDIR}/net/p5-Net-Twitter \
		p5-WWW-Shorten>=0:${PORTSDIR}/www/p5-WWW-Shorten \
		p5-WWW-Shorten-Bitly>=0:${PORTSDIR}/www/p5-WWW-Shorten-Bitly

SUB_FILES=	pkg-message

NO_BUILD=	yes
PLIST_FILES=	%%DATADIR%%/${PORTNAME}.pl
PLIST_DIRS=	%%DATADIR%%

post-extract:
	@${MKDIR} ${WRKSRC}
	@${INSTALL_SCRIPT} ${DISTDIR}/${PORTNAME}-${PORTVERSION}.pl \
		${WRKSRC}/${PORTNAME}.pl

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_SCRIPT} -v ${WRKSRC}/${PORTNAME}.pl ${DATADIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
