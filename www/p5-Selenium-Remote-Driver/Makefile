# $FreeBSD$

PORTNAME=	Selenium-Remote-Driver
PORTVERSION=	1.30
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TEODESIAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Perl Interface for Selenium Remote Driver

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		p5-Clone>=0:devel/p5-Clone \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-JSON>=0:converters/p5-JSON \
		p5-libwww>=0:www/p5-libwww \
		p5-Moo>=1.005:devel/p5-Moo \
		p5-Sub-Install>=0:devel/p5-Sub-Install \
		p5-Test-LongString>=0:devel/p5-Test-LongString \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-namespace-clean>=0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-LWP-UserAgent>=0:www/p5-Test-LWP-UserAgent \
		p5-Test-Time>=0:devel/p5-Test-Time \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5 shebangfix
SHEBANG_FILES=	driver-example.pl
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
