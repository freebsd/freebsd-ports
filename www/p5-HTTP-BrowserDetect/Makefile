# Created by: Sergey Skvortsov <skv@protey.ru>

PORTNAME=	HTTP-BrowserDetect
PORTVERSION=	3.33
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Determine the Web browser, version, OS from an HTTP user agent string

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Hash-Merge>=0:textproc/p5-Hash-Merge \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-FailWarnings>=0:devel/p5-Test-FailWarnings \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 503102
TEST_DEPENDS+=	p5-JSON-PP>=4.04:converters/p5-JSON-PP
.endif

.include <bsd.port.post.mk>
