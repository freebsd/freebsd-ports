PORTNAME=	Net-Whois-RIPE
PORTVERSION=	2.008001
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AASSAD
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Implementation of RIPE Whois
WWW=		https://metacpan.org/release/Net-Whois-RIPE

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Iterator-Util>=0:devel/p5-Iterator-Util
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
