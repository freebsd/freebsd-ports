# $FreeBSD$

PORTNAME=	Selenium-Remote-Driver
PORTVERSION=	1.20
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GEMPESAW
PKGNAMEPREFIX=	p5-
#DISTFILES=	${PORTNAME}-0.23${EXTRACT_SUFX}
#WRKSRC=		${WRKDIR}/${PORTNAME}-0.23

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Perl Interface for Selenium Remote Driver

LICENSE=	APACHE20

TEST_DEPENDS=	p5-Test-Time>=0:devel/p5-Test-Time \
		p5-Test-Warn>=0:devel/p5-Test-Warn
BUILD_DEPENDS=	p5-Archive-Extract>=0.74:archivers/p5-Archive-Extract \
		p5-Archive-Zip>=1.39:archivers/p5-Archive-Zip \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-HTTP-Message>=6.06:www/p5-HTTP-Message \
		p5-JSON>=2.90:converters/p5-JSON \
		p5-libwww>=5.829:www/p5-libwww \
		p5-Moo>=1:devel/p5-Moo \
		p5-Sub-Install>=0.928:devel/p5-Sub-Install \
		p5-Test-LongString>=0.17:devel/p5-Test-LongString \
		p5-Try-Tiny>=0.18:lang/p5-Try-Tiny \
		p5-namespace-clean>=0.25:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	driver-example.pl
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
