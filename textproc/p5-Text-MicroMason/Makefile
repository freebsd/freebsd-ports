PORTNAME=	Text-MicroMason
PORTVERSION=	2.23
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for simple and extensible templating
WWW=		https://metacpan.org/release/Text-MicroMason

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Class-MixinFactory>=0.9:devel/p5-Class-MixinFactory
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
