# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AnyEvent-WebSocket-Client
PORTVERSION=	0.44
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PLICEASE
PKGNAMEPREFIX=	p5-

MAINTAINER=	feld@FreeBSD.org
COMMENT=	WebSocket client for AnyEvent

LICENSE=	ART10

BUILD_DEPENDS=	p5-AnyEvent>0:devel/p5-AnyEvent
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-Moo>0:devel/p5-Moo \
		p5-PerlX-Maybe>0:devel/p5-PerlX-Maybe \
		p5-Protocol-WebSocket>0:www/p5-Protocol-WebSocket \
		p5-URI>0:net/p5-URI \
		p5-URI-ws>0:net/p5-URI-ws

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
