PORTNAME=	HTML-Template-Pluggable
PORTVERSION=	0.22
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extends HTML::Template with plugin support

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CGI>=3.06:www/p5-CGI \
		p5-Class-Trigger>=0:devel/p5-Class-Trigger \
		p5-HTML-Template>=2.7:www/p5-HTML-Template \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common
TEST_DEPENDS=	p5-Test-MockObject>=1:devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
