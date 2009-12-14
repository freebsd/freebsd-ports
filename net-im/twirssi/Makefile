# New ports collection makefile for:	twirssi
# Date created:		2009-11-06
# Whom:			garga
#
# $FreeBSD$
#

PORTNAME=	twirssi
PORTVERSION=	2.3.3
CATEGORIES=	net-im
MASTER_SITES=	http://twirssi.com/
EXTRACT_SUFX=	.pl
EXTRACT_ONLY=

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Twitter script to irssi

RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi \
		${SITE_PERL}/Net/Twitter.pm:${PORTSDIR}/net/p5-Net-Twitter \
		${SITE_PERL}/WWW/Shorten.pm:${PORTSDIR}/www/p5-WWW-Shorten

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
