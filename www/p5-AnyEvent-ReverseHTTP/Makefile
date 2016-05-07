# $FreeBSD$

PORTNAME=	AnyEvent-ReverseHTTP
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of reversehttp for AnyEvent

RUN_DEPENDS=	\
	p5-Any-Moose>0:devel/p5-Any-Moose \
	p5-AnyEvent>0:devel/p5-AnyEvent \
	p5-AnyEvent-HTTP>0:www/p5-AnyEvent-HTTP \
	p5-libwww>0:www/p5-libwww \
	p5-URI>0:net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
