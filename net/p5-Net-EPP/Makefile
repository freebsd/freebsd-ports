# New ports collection makefile for:	Net-EPP-Client
# Date created:				18 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-EPP
PORTVERSION=	0.15
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Client library for the TCP transport for EPP

BUILD_DEPENDS=	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-Digest-SHA1>=2.12:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS+=	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-Digest-SHA1>=2.12:${PORTSDIR}/security/p5-Digest-SHA1

MAN3=	Net::EPP::Client.3 \
	Net::EPP::Frame.3 \
	Net::EPP::Frame::Command::Create::Domain.3 \
	Net::EPP::Protocol.3 \
	Net::EPP::ResponseCodes.3 \
	Net::EPP::Simple.3 \
	Net::EPP::Frame::Command.3 \
	Net::EPP::Frame::Command::Check.3 \
	Net::EPP::Frame::Command::Check::Contact.3 \
	Net::EPP::Frame::Command::Check::Domain.3 \
	Net::EPP::Frame::Command::Check::Host.3 \
	Net::EPP::Frame::Command::Create.3 \
	Net::EPP::Frame::Command::Create::Contact.3 \
	Net::EPP::Frame::Command::Delete.3 \
	Net::EPP::Frame::Command::Delete::Contact.3 \
	Net::EPP::Frame::Command::Delete::Domain.3 \
	Net::EPP::Frame::Command::Delete::Host.3 \
	Net::EPP::Frame::Command::Info.3 \
	Net::EPP::Frame::Command::Info::Contact.3 \
	Net::EPP::Frame::Command::Info::Domain.3 \
	Net::EPP::Frame::Command::Info::Host.3 \
	Net::EPP::Frame::Command::Login.3 \
	Net::EPP::Frame::Command::Logout.3 \
	Net::EPP::Frame::Command::Poll.3 \
	Net::EPP::Frame::Command::Renew.3 \
	Net::EPP::Frame::Command::Transfer.3 \
	Net::EPP::Frame::Command::Update.3 \
	Net::EPP::Frame::Command::Update::Contact.3 \
	Net::EPP::Frame::Command::Update::Domain.3 \
	Net::EPP::Frame::Command::Update::Host.3 \
	Net::EPP::Frame::Greeting.3 \
	Net::EPP::Frame::Hello.3 \
	Net::EPP::Frame::ObjectSpec.3 \
	Net::EPP::Frame::Response.3 \
	Net::EPP::Frame::Command::Poll::Req.3 \
	Net::EPP::Frame::Command::Transfer::Domain.3 \
	Net::EPP::Frame::Command::Transfer::Contact.3 \
	Net::EPP::Frame::Command::Poll::Ack.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
