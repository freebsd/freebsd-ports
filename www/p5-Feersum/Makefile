# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Feersum
PORTVERSION=	1.403
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AUDREYT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PSGI engine for Perl based on EV/libev

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-EV>=4.0:devel/p5-EV \
		p5-Plack>=0.9950:www/p5-Plack
RUN_DEPENDS=	p5-EV>=4.0:devel/p5-EV \
		p5-Plack>=0.9950:www/p5-Plack
TEST_DEPENDS=	p5-AnyEvent>=5.26.1:devel/p5-AnyEvent \
		p5-Guard>=1.012:devel/p5-Guard \
		p5-JSON-XS>=2:converters/p5-JSON-XS \
		p5-Test-Fatal>=0.003:devel/p5-Test-Fatal \
		p5-Test-LeakTrace>=0.13:devel/p5-Test-LeakTrace \
		p5-Test-TCP>=1.12:devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Feersum/Feersum.so

.include <bsd.port.mk>
