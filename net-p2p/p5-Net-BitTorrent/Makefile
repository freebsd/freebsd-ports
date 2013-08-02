# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-BitTorrent
PORTVERSION=	0.052
PORTREVISION=	2
CATEGORIES=	net-p2p perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SANKO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	BitTorrent peer-to-peer protocol class

RUN_DEPENDS=	p5-Math-BigInt>=1.78:${PORTSDIR}/math/p5-Math-BigInt

CONFIGURE_ARGS=	</dev/null
PORTSCOUT=	skipv:0.074000_012	

USES=		perl5
USE_PERL5=	modbuild

MAN1=		net-bittorrent.pl.1
MAN3=		Net::BitTorrent.3 \
		Net::BitTorrent::Notes.3 \
		Net::BitTorrent::ConfigData.3 \
		Net::BitTorrent::DHT.3 \
		Net::BitTorrent::Peer.3 \
		Net::BitTorrent::Protocol.3 \
		Net::BitTorrent::Torrent.3 \
		Net::BitTorrent::Torrent::File.3 \
		Net::BitTorrent::Torrent::Tracker.3 \
		Net::BitTorrent::Torrent::Tracker::HTTP.3 \
		Net::BitTorrent::Torrent::Tracker::UDP.3 \
		Net::BitTorrent::Util.3 \
		Net::BitTorrent::Version.3

.include <bsd.port.mk>

