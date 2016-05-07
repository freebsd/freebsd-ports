# $FreeBSD$

PORTNAME=	AnyEvent-MPRPC
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple TCP-based MPRPC client/server

RUN_DEPENDS=	\
	p5-Any-Moose>=0.13:devel/p5-Any-Moose \
	p5-AnyEvent>=5.261:devel/p5-AnyEvent \
	p5-Data-MessagePack>=0.34:devel/p5-Data-MessagePack \
	p5-Data-MessagePack-Stream>=0.05:devel/p5-Data-MessagePack-Stream \
	p5-AnyEvent-MessagePack>=0.19:devel/p5-AnyEvent-MessagePack
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-TCP>=0:devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
