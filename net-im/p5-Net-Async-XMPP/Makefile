# New ports collection makefile for:	p5-Net-Async-XMPP
# Date created:		2011-03-07
# Whom:			<ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=	Net-Async-XMPP
PORTVERSION=	0.002
PORTREVISION=	1
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TEAM
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Asynchronous XMPP client and server

RUN_DEPENDS=	p5-IO-Async>=0.37:${PORTSDIR}/devel/p5-IO-Async \
		p5-IO-Async-SSL>=0.04:${PORTSDIR}/security/p5-IO-Async-SSL \
		p5-Protocol-XMPP>=0.002:${PORTSDIR}/net-im/p5-Protocol-XMPP

PERL_CONFIGURE=	yes

MAN3=		Net::Async::XMPP.3 \
		Net::Async::XMPP::Client.3 \
		Net::Async::XMPP::Protocol.3 \
		Net::Async::XMPP::Server.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
.endif

.include <bsd.port.post.mk>
