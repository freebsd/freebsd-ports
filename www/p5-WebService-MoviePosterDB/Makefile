PORTNAME=	WebService-MoviePosterDB
DISTVERSION=	0.18
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl interface to MoviePosterDB
WWW=		https://metacpan.org/release/WebService-MoviePosterDB

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

DEPRECATED=	Based on MoviePosterDB legacy API which has been turned offline
RATION_DATE=	2026-12-23

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Cache-Cache>=0:devel/p5-Cache-Cache \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-JSON>=0:converters/p5-JSON \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
