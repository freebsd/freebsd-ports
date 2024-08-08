PORTNAME=	CGI-Application-Plugin-Authentication
DISTVERSION=	0.25
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Support for authenticating requests in CGI::Application
WWW=		https://metacpan.org/release/CGI-Application-Plugin-Authentication

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Apache-Htpasswd>=0:security/p5-Apache-Htpasswd \
		p5-CGI-Application>=4:www/p5-CGI-Application \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require \
		p5-Color-Calc>=1.073:graphics/p5-Color-Calc
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Warn>=0.11:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
