PORTNAME=	WWW-Mechanize
PORTVERSION=	2.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Handy web browsing in a Perl object

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTML-Form>=1.00:www/p5-HTML-Form \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTML-Tree>=5:www/p5-HTML-Tree \
		p5-HTTP-Cookies>=0:www/p5-HTTP-Cookies \
		p5-HTTP-Message>=1.30:www/p5-HTTP-Message \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	p5-HTTP-Daemon>=6.12:www/p5-HTTP-Daemon \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Memory-Cycle>=1.06:devel/p5-Test-Memory-Cycle \
		p5-Test-NoWarnings>=1.04:devel/p5-Test-NoWarnings \
		p5-Test-Output>=0:devel/p5-Test-Output \
		p5-Test-Taint>=1.08:devel/p5-Test-Taint \
		p5-Test-Warn>=0:devel/p5-Test-Warn \
		p5-Test-Warnings>=0:devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
