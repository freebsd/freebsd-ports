# $FreeBSD$

PORTNAME=	WWW-Mechanize-PhantomJS
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Automate interaction with javascript websites

LICENSE=	ARTPERL10

BUILD_DEPENDS=	${LOCALBASE}/bin/phantomjs:${PORTSDIR}/lang/phantomjs \
		p5-WWW-Mechanize>=1.73:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-Object-Import>=1.004:${PORTSDIR}/devel/p5-Object-Import \
		p5-Selenium-Remote-Driver>=0.2202:${PORTSDIR}/www/p5-Selenium-Remote-Driver \
		p5-HTML-Selector-XPath>=0.14:${PORTSDIR}/www/p5-HTML-Selector-XPath
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-HTTP-Daemon>=6.0:${PORTSDIR}/www/p5-HTTP-Daemon \
		p5-libwww>=5.829:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
