# $FreeBSD$

PORTNAME=	Selenium-Remote-Driver
PORTVERSION=	0.2203
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GEMPESAW
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Perl Interface for Selenium Remote Driver

LICENSE=	APACHE20

BUILD_DEPENDS=	p5-Archive-Extract>=0.74:${PORTSDIR}/archivers/p5-Archive-Extract \
		p5-Archive-Zip>=1.39:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-HTTP-Message>=6.06:${PORTSDIR}/www/p5-HTTP-Message \
		p5-JSON>=2.90:${PORTSDIR}/converters/p5-JSON \
		p5-libwww>=5.829:${PORTSDIR}/www/p5-libwww \
		p5-Moo>=1:${PORTSDIR}/devel/p5-Moo \
		p5-Sub-Install>=0.928:${PORTSDIR}/devel/p5-Sub-Install \
		p5-Test-LongString>=0.17:${PORTSDIR}/devel/p5-Test-LongString \
		p5-Try-Tiny>=0.18:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-namespace-clean>=0.25:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
