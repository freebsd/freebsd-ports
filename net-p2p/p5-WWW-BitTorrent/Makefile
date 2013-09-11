# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>
# $FreeBSD$

PORTNAME=	WWW-BitTorrent
PORTVERSION=	0.01
CATEGORIES=	net-p2p perl5 www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Search and Download .torrent(s) files from BitTorrents boards

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		WWW::BitTorrent.3

.include <bsd.port.mk>
