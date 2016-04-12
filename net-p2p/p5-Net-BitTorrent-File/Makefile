# Created by: Oleg R. Muhutdinov <mor@WhiteLuna.com>
# $FreeBSD$

PORTNAME=	Net-BitTorrent-File
PORTVERSION=	1.02
DISTVERSIONSUFFIX=	-fix
PORTREVISION=	1
CATEGORIES=	net-p2p perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for handles loading and saving of .torrent file

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Convert-Bencode>=0:converters/p5-Convert-Bencode \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
