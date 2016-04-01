# $FreeBSD$

PORTNAME=	Plack-Middleware-JSConcat
PORTVERSION=	0.29
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to concatenate JavaScripts

RUN_DEPENDS=	\
	p5-IPC-Run3>0:devel/p5-IPC-Run3 \
	p5-Plack>0:www/p5-Plack
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
