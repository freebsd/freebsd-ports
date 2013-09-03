# New ports collection makefile for:	p5-Protocol-WebSocket
# Date created:				20 March 2010
# Whom:					Stefan `Sec` Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	Protocol-WebSocket
PORTVERSION=	0.00906
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VTI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sec@42.org
COMMENT=	Client/server WebSocket message and frame parser/constructor

BUILD_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1

USES=		perl5
USE_PERL5=	configure

MAN3=		Protocol::WebSocket.3 \
		Protocol::WebSocket::Cookie.3 \
		Protocol::WebSocket::Cookie::Request.3 \
		Protocol::WebSocket::Cookie::Response.3 \
		Protocol::WebSocket::Frame.3 \
		Protocol::WebSocket::Handshake.3 \
		Protocol::WebSocket::Handshake::Client.3 \
		Protocol::WebSocket::Handshake::Server.3 \
		Protocol::WebSocket::Message.3 \
		Protocol::WebSocket::Request.3 \
		Protocol::WebSocket::Response.3 \
		Protocol::WebSocket::Stateful.3 \
		Protocol::WebSocket::URL.3

.include <bsd.port.mk>
