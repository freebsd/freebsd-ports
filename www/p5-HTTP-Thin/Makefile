# $FreeBSD$

PORTNAME=	HTTP-Thin
PORTVERSION=	0.006
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	amontalban@gmail.com
COMMENT=	Thin Wrapper around HTTP::Tiny to play nice with HTTP::Message

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Class-Method-Modifiers>0:devel/p5-Class-Method-Modifiers \
		p5-HTTP-Tiny>=0.056:www/p5-HTTP-Tiny \
		p5-HTTP-Message>0:www/p5-HTTP-Message \
		p5-Hash-MultiValue>0:devel/p5-Hash-MultiValue \
		p5-Safe-Isa>0:devel/p5-Safe-Isa
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
