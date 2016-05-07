# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	POE-Component-Server-SOAP
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Publish POE event handlers via SOAP over HTTP

BUILD_DEPENDS=	p5-SOAP-Lite>=0.55:net/p5-SOAP-Lite \
		p5-POE-Component-Server-SimpleHTTP>=1.54:www/p5-POE-Component-Server-SimpleHTTP \
		p5-POE>=0:devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
