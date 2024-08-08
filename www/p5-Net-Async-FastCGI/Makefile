PORTNAME=	Net-Async-FastCGI
PORTVERSION=	0.26
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to use FastCGI with IO::Async
WWW=		https://metacpan.org/release/Net-Async-FastCGI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-Async>=0.350:devel/p5-IO-Async \
		p5-Net-FastCGI>=0.10:www/p5-Net-FastCGI
TEST_DEPENDS=	p5-Test2-Suite>=0.000149:devel/p5-Test2-Suite

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
