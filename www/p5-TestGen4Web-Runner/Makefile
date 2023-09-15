PORTNAME=	TestGen4Web-Runner
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN/WWW/MACKERS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to replay files recorded with TestGen4Web
WWW=		https://metacpan.org/release/TestGen4Web-Runner

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-URI>=0:net/p5-URI \
		p5-XML-Simple>=0:textproc/p5-XML-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
