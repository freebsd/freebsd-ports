# $FreeBSD$

PORTNAME=	WWW-Mechanize-PhantomJS
PORTVERSION=	0.22
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Automate interaction with javascript websites

LICENSE=	ARTPERL10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	phantomjs:lang/phantomjs \
		p5-WWW-Mechanize>=1.73:www/p5-WWW-Mechanize \
		p5-Object-Import>=1.004:devel/p5-Object-Import \
		p5-Selenium-Remote-Driver>=0.2202:www/p5-Selenium-Remote-Driver \
		p5-HTML-Selector-XPath>=0.14:www/p5-HTML-Selector-XPath
TEST_DEPENDS=	p5-HTTP-Daemon>=6.0:www/p5-HTTP-Daemon \
		p5-libwww>=5.829:www/p5-libwww

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
