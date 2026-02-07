PORTNAME=	Plack-Middleware-Precompressed
PORTVERSION=	1.104
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ARISTOTLE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to serve pre-gzipped content to capable clients
WWW=		https://metacpan.org/release/Plack-Middleware-Precompressed

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Array-RefElem>=0:misc/p5-Array-RefElem \
		p5-Plack>=0.9942:www/p5-Plack
TEST_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
