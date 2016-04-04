# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Squatting
PORTVERSION=	0.82
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BEPPU
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Camping-inspired Web Microframework for Perl

COMMON_DEPENDS=	p5-Continuity>=0.991:www/p5-Continuity \
		p5-Class-C3-Componentised>0:devel/p5-Class-C3-Componentised \
		p5-Clone>=0:devel/p5-Clone \
		p5-Data-Dump>0:devel/p5-Data-Dump \
		p5-IO-All>=0:devel/p5-IO-All \
		p5-Shell-Perl>0:shells/p5-Shell-Perl \
		p5-JSON-XS>0:converters/p5-JSON-XS \
		p5-libwww>0:www/p5-libwww \
		p5-HTTP-Daemon>0:www/p5-HTTP-Daemon \
		p5-HTTP-Message>0:www/p5-HTTP-Message
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
