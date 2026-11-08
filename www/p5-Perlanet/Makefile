PORTNAME=	Perlanet
PORTVERSION=	3.3.5
DISTVERSIONPREFIX=	v
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAVECROSS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Program for creating programs that aggregate web feeds
WWW=		https://metacpan.org/release/Perlanet

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CHI>=0:devel/p5-CHI \
		p5-DateTime-Format-Strptime>=0:devel/p5-DateTime-Format-Strptime \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-HTML-Scrubber>=0:www/p5-HTML-Scrubber \
		p5-HTML-T5>=0:textproc/p5-HTML-T5 \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-ConfigFromFile>=0:devel/p5-MooseX-ConfigFromFile \
		p5-MooseX-Traits>=0:devel/p5-MooseX-Traits \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-URI>=0:net/p5-URI \
		p5-XML-Feed>=0.22:textproc/p5-XML-Feed \
		p5-YAML>=0:textproc/p5-YAML
TEST_DEPENDS=	p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage \
		p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Warnings>=0:devel/p5-Test-Warnings \
		p5-URI-Fetch>=0:www/p5-URI-Fetch \
		p5-XML-OPML-SimpleGen>=0:textproc/p5-XML-OPML-SimpleGen \
		p5-XML-OPML>=0:textproc/p5-XML-OPML

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
