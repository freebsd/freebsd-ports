PORTNAME=	FCGI-Client
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for fastcgi protocol client library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/README.md

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moo>0:devel/p5-Moo \
		p5-Try-Tiny>0:lang/p5-Try-Tiny \
		p5-Type-Tiny>0:devel/p5-Type-Tiny

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
