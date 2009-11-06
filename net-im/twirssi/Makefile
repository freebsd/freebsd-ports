# New ports collection makefile for:	twirssi
# Date created:		2009-11-06
# Whom:			garga
#
# $FreeBSD$
#

PORTNAME=	twirssi
PORTVERSION=	2.3.0
CATEGORIES=	net-im
MASTER_SITES=	http://twirssi.com/
EXTRACT_SUFX=	.pl
EXTRACT_ONLY=

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Twitter script to irssi

RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi \
		${SITE_PERL}Net/Twitter.pm:${PORTSDIR}/net/p5-Net-Twitter \
		${SITE_PERL}WWW/Shorten.pm:${PORTSDIR}/www/p5-WWW-Shorten

NO_BUILD=	yes
PLIST_FILES=	%%DATADIR%%/${PORTNAME}.pl
PLIST_DIRS=	%%DATADIR%%

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_SCRIPT} -v ${DISTDIR}/${PORTNAME}-${PORTVERSION}.pl \
		${DATADIR}/${PORTNAME}.pl

.include <bsd.port.mk>
