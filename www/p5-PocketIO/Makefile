# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PocketIO
PORTVERSION=	0.17000
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VTI
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/000$//}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Socket.IO Plack application

LICENSE=	ART20

BUILD_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-JSON>=2.53:converters/p5-JSON \
		p5-Protocol-SocketIO>=0.04:www/p5-Protocol-SocketIO \
		p5-Protocol-WebSocket>=0.00906:www/p5-Protocol-WebSocket \
		p5-Test-TCP>=0:devel/p5-Test-TCP
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Plack>=0:www/p5-Plack \
		p5-Twiggy>=0:www/p5-Twiggy

NO_ARCH=	yes
USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
