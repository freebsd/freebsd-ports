# New ports collection makefile for:	p5-PocketIO
# Date created:		2011-10-01
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PocketIO
PORTVERSION=	0.13000
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VTI
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/000$//}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Socket.IO Plack application

LICENSE=	ART20

BUILD_DEPENDS=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Protocol-SocketIO>=0.04:${PORTSDIR}/www/p5-Protocol-SocketIO \
		p5-Protocol-WebSocket>=0.00906:${PORTSDIR}/www/p5-Protocol-WebSocket
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Plack>=0:${PORTSDIR}/www/p5-Plack \
		p5-Test-TCP>=0:${PORTSDIR}/devel/p5-Test-TCP \
		p5-Twiggy>=0:${PORTSDIR}/www/p5-Twiggy

PERL_CONFIGURE=	yes

MAN3=		PocketIO.3 \
		PocketIO::Broadcast.3 \
		PocketIO::Connection.3 \
		PocketIO::Handle.3 \
		PocketIO::Message.3 \
		PocketIO::Pool.3 \
		PocketIO::Pool::Redis.3 \
		PocketIO::Resource.3 \
		PocketIO::Socket.3 \
		PocketIO::Sockets.3 \
		PocketIO::Test.3 \
		PocketIO::Transport::Base.3 \
		PocketIO::Transport::BasePolling.3 \
		PocketIO::Transport::Htmlfile.3 \
		PocketIO::Transport::JSONPPolling.3 \
		PocketIO::Transport::WebSocket.3 \
		PocketIO::Transport::XHRMultipart.3 \
		PocketIO::Transport::XHRPolling.3

.include <bsd.port.mk>
