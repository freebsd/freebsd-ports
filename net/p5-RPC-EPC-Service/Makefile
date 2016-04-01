# $FreeBSD$

PORTNAME=	RPC-EPC-Service
PORTVERSION=	0.0.11
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for asynchronous remote procedure stack

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-AnyEvent>=6.1:devel/p5-AnyEvent \
	p5-Data-SExpression>=0.41:devel/p5-Data-SExpression
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
