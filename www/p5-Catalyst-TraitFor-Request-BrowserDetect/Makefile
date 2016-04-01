# $FreeBSD$

PORTNAME=	Catalyst-TraitFor-Request-BrowserDetect
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Browser detection for Catalyst::Requests

BUILD_DEPENDS=	p5-Catalyst-Runtime>=0:www/p5-Catalyst-Runtime \
		p5-CatalystX-RoleApplicator>=0:www/p5-CatalystX-RoleApplicator \
		p5-HTTP-BrowserDetect>=0:www/p5-HTTP-BrowserDetect
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
