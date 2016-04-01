# $FreeBSD$

PORTNAME=	Amon2-Lite
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Sinatra-ish framework on Amon2!

RUN_DEPENDS=	\
	p5-Amon2>=3.25:www/p5-Amon2 \
	p5-Data-Section-Simple>=0.03:devel/p5-Data-Section-Simple \
	p5-Router-Simple>=0.13:www/p5-Router-Simple \
	p5-Text-Xslate-Bridge-TT2Like>=0.00010:textproc/p5-Text-Xslate-Bridge-TT2Like
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Requires>0:devel/p5-Test-Requires \
	p5-JSON>0:converters/p5-JSON \
	p5-Text-MicroTemplate>0:textproc/p5-Text-MicroTemplate \
	p5-Test-WWW-Mechanize-PSGI>0:devel/p5-Test-WWW-Mechanize-PSGI \
	p5-Tiffany>0:textproc/p5-Tiffany \
	p5-Plack-Middleware-ReverseProxy>0:www/p5-Plack-Middleware-ReverseProxy

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
