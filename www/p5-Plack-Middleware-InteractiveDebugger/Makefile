# $FreeBSD$

PORTNAME=	Plack-Middleware-InteractiveDebugger
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Awesome Interactive Debugger ala Werkzeug

RUN_DEPENDS=	\
	p5-Data-Dump-Streamer>0:devel/p5-Data-Dump-Streamer \
	p5-Devel-StackTrace-WithLexicals>=0.08:devel/p5-Devel-StackTrace-WithLexicals \
	p5-Eval-WithLexicals>0:devel/p5-Eval-WithLexicals \
	p5-File-ShareDir>0:devel/p5-File-ShareDir \
	p5-Plack>=0.9977:www/p5-Plack \
	p5-Try-Tiny>0:lang/p5-Try-Tiny
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
