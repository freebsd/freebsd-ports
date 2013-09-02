# New ports collection makefile for:	Plack::Middleware::SocketIO
# Date created:		05 Jul 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Middleware-SocketIO
PORTVERSION=	0.00904
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Socket.IO Plack middleware

RUN_DEPENDS=	\
	p5-AnyEvent>0:${PORTSDIR}/devel/p5-AnyEvent \
	p5-JSON>0:${PORTSDIR}/converters/p5-JSON1 \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-Protocol-WebSocket>=0.00901:${PORTSDIR}/www/p5-Protocol-WebSocket \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Plack::Middleware::SocketIO.3 \
	Plack::Middleware::SocketIO::Base.3 \
	Plack::Middleware::SocketIO::Connection.3 \
	Plack::Middleware::SocketIO::Handle.3 \
	Plack::Middleware::SocketIO::Htmlfile.3 \
	Plack::Middleware::SocketIO::JSONPPolling.3 \
	Plack::Middleware::SocketIO::Resource.3 \
	Plack::Middleware::SocketIO::WebSocket.3 \
	Plack::Middleware::SocketIO::XHRMultipart.3 \
	Plack::Middleware::SocketIO::XHRPolling.3

.include <bsd.port.mk>
