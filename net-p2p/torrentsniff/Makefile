# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	torrentsniff
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	net-p2p perl5
MASTER_SITES=	http://www.highprogrammer.com/alan/perl/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Commandline tool for getting status of torrent

RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1

NO_BUILD=	yes
USES=		shebangfix perl5
SHEBANG_FILES=	torrentsniff

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/torrentsniff ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/BitTorrent
	${INSTALL_DATA} ${WRKSRC}/BitTorrent/BDecode.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/BitTorrent

.include <bsd.port.mk>
