# New ports collection makefile for:	Net-EPP-Frame
# Date created:				18 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-EPP-Frame
PORTVERSION=	0.07
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	An EPP XML frame system built on top of XML::LibXML

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS+=	${BUILD_DEPENDS}

MAN3=	Net::EPP::Frame.3 \
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
	Net::EPP::Frame::Response.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl5.6
.endif

.include <bsd.port.post.mk>
