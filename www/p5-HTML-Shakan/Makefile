PORTNAME=	HTML-Shakan
PORTVERSION=	2.10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SONGMU
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension of form html generator/validator

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Email-Valid-Loose>=0.05:mail/p5-Email-Valid-Loose \
		p5-FormValidator-Lite>=0.24:textproc/p5-FormValidator-Lite \
		p5-HTML-Escape>=0:www/p5-HTML-Escape \
		p5-Hash-MultiValue>=0:devel/p5-Hash-MultiValue \
		p5-List-MoreUtils>=0.220:lang/p5-List-MoreUtils \
		p5-Mouse>=0:devel/p5-Mouse
TEST_DEPENDS=	p5-CGI>=0:www/p5-CGI \
		p5-Test-Requires>=0.06:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
