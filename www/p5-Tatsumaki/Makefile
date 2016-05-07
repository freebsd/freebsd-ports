# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Tatsumaki
PORTVERSION=	0.1013
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Non-blocking web framework based on Plack and AnyEvent

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Any-Moose>=0:devel/p5-Any-Moose \
		p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-AnyEvent-HTTP>=0:www/p5-AnyEvent-HTTP \
		p5-JSON>=0:converters/p5-JSON \
		p5-Mouse>=0:devel/p5-Mouse \
		p5-Plack>=0:www/p5-Plack \
		p5-Text-MicroTemplate>=0:textproc/p5-Text-MicroTemplate \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-Twiggy>=0:www/p5-Twiggy
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-TCP>=0:devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
