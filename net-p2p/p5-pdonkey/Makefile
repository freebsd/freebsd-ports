# Created by: ijliao
# $FreeBSD$

PORTNAME=	pdonkey
PORTVERSION=	0.05
CATEGORIES=	net-p2p perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KLIMKIN
PKGNAMEPREFIX=	p5-
DISTNAME=	P2P-pDonkey-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl tools for eDonkey network

DEPRECATED=	Depends on expired multimedia/p5-Video-Info
EXPIRATION_DATE=2013-07-03

BUILD_DEPENDS=	p5-Digest-MD4>=0:${PORTSDIR}/security/p5-Digest-MD4 \
		p5-Data-Hexdumper>=0:${PORTSDIR}/devel/p5-Data-Hexdumper \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-Video-Info>=0:${PORTSDIR}/multimedia/p5-Video-Info

PERL_CONFIGURE=	yes

MAN3=	P2P::pDonkey::Met.3 \
	P2P::pDonkey::Packet.3 \
	P2P::pDonkey::Util.3 \
	P2P::pDonkey::Meta.3

.include <bsd.port.mk>
