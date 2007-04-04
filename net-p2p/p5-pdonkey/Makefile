# ex:ts=8
# Ports collection makefile for:	pdonkey
# Date Created:			Feb 25, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pdonkey
PORTVERSION=	0.05
CATEGORIES=	net-p2p perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:sf/} \
		${MASTER_SITE_PERL_CPAN:S/$/:cpan/}
MASTER_SITE_SUBDIR=	${PORTNAME}/:sf \
		../by-authors/K/KL/KLIMKIN/:cpan
PKGNAMEPREFIX=	p5-
DISTNAME=	P2P-pDonkey-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sf \
		${DISTNAME}${EXTRACT_SUFX}:cpan

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl tools for eDonkey network

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD4.pm:${PORTSDIR}/security/p5-Digest-MD4 \
		${SITE_PERL}/Data/Hexdumper.pm:${PORTSDIR}/devel/p5-Data-Hexdumper \
		${SITE_PERL}/Tie/IxHash.pm:${PORTSDIR}/devel/p5-Tie-IxHash \
		${SITE_PERL}/Video/Info.pm:${PORTSDIR}/multimedia/p5-Video-Info

PERL_CONFIGURE=	yes

MAN3=	P2P::pDonkey::Met.3 \
	P2P::pDonkey::Packet.3 \
	P2P::pDonkey::Util.3 \
	P2P::pDonkey::Meta.3

.include <bsd.port.mk>
