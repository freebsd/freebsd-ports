# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	HTTP-BrowserDetect
PORTVERSION=	3.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Determine the Web browser, version, OS from an HTTP user agent string

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Test-FailWarnings>=0:devel/p5-Test-FailWarnings \
		p5-Test-Most>=0:devel/p5-Test-Most \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
