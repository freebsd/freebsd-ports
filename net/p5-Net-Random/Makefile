# Created by: clsung
# $FreeBSD$

PORTNAME=	Net-Random
PORTVERSION=	2.31
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to get random data from online sources

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON>=0:converters/p5-JSON \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockObject>=0:devel/p5-Test-MockObject

PORTSCOUT=	skipv:2.21,2.22

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
