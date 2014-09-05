# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	HTTP-BrowserDetect
PORTVERSION=	1.75
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:OALDERS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Determine the Web browser, version, OS from an HTTP user agent string

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Path-Tiny>0:${PORTSDIR}/devel/p5-Path-Tiny \
		p5-Test-FailWarnings>=0:${PORTSDIR}/devel/p5-Test-FailWarnings \
		p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
