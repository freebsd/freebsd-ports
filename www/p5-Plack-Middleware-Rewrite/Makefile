PORTNAME=	Plack-Middleware-Rewrite
PORTVERSION=	2.102
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ARISTOTLE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	mod_rewrite for Plack
WWW=		https://metacpan.org/dist/Plack-Middleware-Rewrite

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Plack>=0.9942:www/p5-Plack
TEST_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
