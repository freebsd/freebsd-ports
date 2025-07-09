PORTNAME=	Plack-Middleware-Session
PORTVERSION=	0.35
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for session management middleware for Plack
WWW=		https://metacpan.org/release/Plack-Middleware-Session

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Cookie-Baker>=0.12:www/p5-Cookie-Baker \
		p5-Crypt-SysRandom>=0:security/p5-Crypt-SysRandom \
		p5-Digest-HMAC>=1.03:security/p5-Digest-HMAC \
		p5-Plack>=0.9910:www/p5-Plack
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-DBI>=0:databases/p5-DBI \
		p5-HTTP-Cookies>=0:www/p5-HTTP-Cookies \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-libwww>=0:www/p5-libwww \
		p5-Test-Fatal>=0.006:devel/p5-Test-Fatal \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-TCP>=0:devel/p5-Test-TCP \
		p5-YAML>=0:textproc/p5-YAML

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
