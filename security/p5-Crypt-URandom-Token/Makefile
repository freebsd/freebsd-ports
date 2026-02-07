PORTNAME=	Crypt-URandom-Token
PORTVERSION=	0.005
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=CPAN:STIGTSP
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Generate secure strings for passwords, secrets and similar
WWW=		https://metacpan.org/dist/Crypt-URandom-Token

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Crypt-URandom>=0.40:security/p5-Crypt-URandom
TEST_DEPENDS=	p5-Test-Exception>=0.43:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PLIST_FILES=	${SITE_PERL}/Crypt/URandom/Token.pm \
		${SITE_MAN3_REL}/Crypt::URandom::Token.3.gz

.include <bsd.port.mk>
