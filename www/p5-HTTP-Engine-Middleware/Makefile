# $FreeBSD$

PORTNAME=	HTTP-Engine-Middleware
PORTVERSION=	0.22
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for official distribution of HTTP::Engine

BUILD_DEPENDS:=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-Any-Moose>=0.09:devel/p5-Any-Moose \
	p5-Mouse>=0.23:devel/p5-Mouse \
	p5-Filter>0:devel/p5-Filter \
	p5-HTTP-Engine>=0.03004:www/p5-HTTP-Engine \
	p5-libwww>0:www/p5-libwww \
	p5-DateTime>0:devel/p5-DateTime

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
