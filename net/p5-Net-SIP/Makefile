# New ports collection makefile for:	p5-Net-SIP
# Date created:		2007-03-01
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-SIP
PORTVERSION=	0.23
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Framework SIP (Voice Over IP, RFC3261)

RUN_DEPENDS=	p5-Net-DNS>=0.56:${PORTSDIR}/dns/p5-Net-DNS

PERL_CONFIGURE=	yes

MAN3=		Net::SIP.3 Net::SIP::Debug.3 \
		Net::SIP::Dispatcher.3 Net::SIP::Dispatcher::Eventloop.3 \
		Net::SIP::Endpoint.3 Net::SIP::Endpoint::Context.3 \
		Net::SIP::Leg.3 Net::SIP::NATHelper::Base.3 \
		Net::SIP::NATHelper::Client.3 Net::SIP::NATHelper::Local.3 \
		Net::SIP::NATHelper::Server.3 Net::SIP::Packet.3 \
		Net::SIP::Registrar.3 Net::SIP::Request.3 \
		Net::SIP::Response.3 Net::SIP::SDP.3 \
		Net::SIP::Simple.3 Net::SIP::Simple::Call.3 \
		Net::SIP::Simple::RTP.3 Net::SIP::StatelessProxy.3 \
		Net::SIP::Util.3

.include <bsd.port.mk>
