# New ports collection makefile for:	torrentsniff
# Date created:				06 July 2003
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	torrentsniff
PORTVERSION=	0.3.0
CATEGORIES=	net perl5
MASTER_SITES=	http://www.highprogrammer.com/alan/perl/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Commandline tool for getting status of torrent

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1

USE_PERL5=	yes
NO_BUILD=	yes

post-patch:
	${PERL} -pi -e "s#/usr/local/bin/perl#${PERL5}#" ${WRKSRC}/torrentsniff

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/torrentsniff ${LOCALBASE}/bin
	${MKDIR} ${SITE_PERL}/BitTorrent
	${INSTALL_DATA} ${WRKSRC}/BitTorrent/BDecode.pm ${SITE_PERL}/BitTorrent

.include <bsd.port.mk>
