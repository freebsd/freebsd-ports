# New ports collection makefile for:	p5-Net-BitTorrent-File
# Date created:				February 06th 2006
# Whom:	      				Oleg R. Muhutdinov <mor@WhiteLuna.com>
#
# $FreeBSD$
#

PORTNAME=	Net-BitTorrent-File
PORTVERSION=	1.02
CATEGORIES=	net-p2p perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}-fix

MAINTAINER=	mor@WhiteLuna.com
COMMENT=	Perl5 module for handles loading and saving of .torrent file

RUN_DEPENDS=	p5-Convert-Bencode>=0:${PORTSDIR}/converters/p5-Convert-Bencode \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple

WRKSRC=		${WRKDIR}/${DISTNAME:S/-fix//}

PERL_CONFIGURE=	yes

MAN3=		Net::BitTorrent::File.3

.include <bsd.port.mk>
