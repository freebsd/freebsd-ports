PORTNAME=	Test-Regexp
PORTVERSION=	2017040101
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Test your regular expressions

LICENSE=	MIT

TEST_DEPENDS=	p5-Test-Pod>=1.51:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.10:devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PLIST_FILES=	${SITE_PERL_REL}/Test/Regexp.pm \
	       	${SITE_MAN3_REL}/Test::Regexp.3.gz

.include <bsd.port.mk>
