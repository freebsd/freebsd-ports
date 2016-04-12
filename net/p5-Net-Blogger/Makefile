# Created by: ijliao
# $FreeBSD$

PORTNAME=	Net-Blogger
PORTVERSION=	1.02
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OOP-ish interface for accessing a weblog via the XML-RPC API

BUILD_DEPENDS=	p5-Error>=0:lang/p5-Error \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww \
		p5-SOAP-Lite>0.55:net/p5-SOAP-Lite
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Term-ReadKey>=0:devel/p5-Term-ReadKey

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
