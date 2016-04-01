# $FreeBSD$

PORTNAME=	HTTP-Headers-Fast
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for faster implementation of HTTP::Headers

RUN_DEPENDS=	p5-HTTP-Date>0:www/p5-HTTP-Date
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Requires>0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
