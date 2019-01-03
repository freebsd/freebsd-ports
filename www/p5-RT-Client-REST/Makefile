# $FreeBSD$

PORTNAME=	RT-Client-REST
PORTVERSION=	0.55
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl modules designed to talk to RT installation using REST protocol

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-Error>=0:lang/p5-Error \
		p5-Exception-Class>=0:devel/p5-Exception-Class \
		p5-DateTime>0:devel/p5-DateTime \
		p5-DateTime-Format-DateParse>0:devel/p5-DateTime-Format-DateParse \
		p5-HTTP-Cookies>0:www/p5-HTTP-Cookies \
		p5-Module-Build>=0.28:devel/p5-Module-Build \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-URI>0:net/p5-URI
TEST_DEPENDS=	p5-HTTP-Server-Simple>=0:www/p5-HTTP-Server-Simple \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
