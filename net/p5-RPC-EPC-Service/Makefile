# $FreeBSD$

PORTNAME=	RPC-EPC-Service
PORTVERSION=	0.0.7
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for asynchronous remote procedure stack

RUN_DEPENDS=	\
	p5-AnyEvent>=6.1:${PORTSDIR}/devel/p5-AnyEvent \
	p5-Data-SExpression>=0.41:${PORTSDIR}/devel/p5-Data-SExpression
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
