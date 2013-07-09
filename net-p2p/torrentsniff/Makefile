# New ports collection makefile for:	torrentsniff
# Date created:				06 July 2003
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	torrentsniff
PORTVERSION=	0.3.0
CATEGORIES=	net-p2p perl5
MASTER_SITES=	http://www.highprogrammer.com/alan/perl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commandline tool for getting status of torrent

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1

USE_PERL5=	yes
NO_BUILD=	yes

post-patch:
	${PERL} -pi -e "s#/usr/local/bin/perl#${PERL5}#" ${WRKSRC}/torrentsniff

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/torrentsniff ${LOCALBASE}/bin
	${MKDIR} ${SITE_PERL}/BitTorrent
	${INSTALL_DATA} ${WRKSRC}/BitTorrent/BDecode.pm ${SITE_PERL}/BitTorrent

.include <bsd.port.mk>
