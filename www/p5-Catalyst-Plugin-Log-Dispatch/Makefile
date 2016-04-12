# Created by: Oleg Mamontov <oleg@mamontov.net>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Log-Dispatch
PORTVERSION=	0.121
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Log module of Catalyst that uses Log::Dispatch

BUILD_DEPENDS=	p5-Log-Dispatch>=2.13:devel/p5-Log-Dispatch		\
		p5-Log-Dispatch-Config>=0:devel/p5-Log-Dispatch-Config	\
		p5-Catalyst-Runtime>=5.65:www/p5-Catalyst-Runtime	\
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
