PORTNAME=	Net-BitTorrent
PORTVERSION=	0.052
PORTREVISION=	5
CATEGORIES=	net-p2p perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SANKO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	BitTorrent peer-to-peer protocol class
WWW=		https://metacpan.org/release/Net-BitTorrent

LICENSE=	ART20

DEPRECATED=	Deprecated, no active development in more than a decade so any "new" functionality is missing and interoperability with recent software is very limited if not completely broken
EXPIRATION_DATE=2025-04-30

PORTSCOUT=	limit:^[0-9\.]*$$

CONFIGURE_ARGS=	</dev/null

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	yes

.include <bsd.port.mk>
