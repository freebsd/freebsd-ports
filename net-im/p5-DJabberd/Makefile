# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	DJabberd
PORTVERSION=	0.85
PORTREVISION=	1
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MART
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Scalable, extensible Jabber/XMPP server framework

BUILD_DEPENDS=	p5-Danga-Socket>=0:${PORTSDIR}/devel/p5-Danga-Socket \
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-SSLeay>=0:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-Unicode-Stringprep>=0:${PORTSDIR}/converters/p5-Unicode-Stringprep
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1

USES=		perl5
USE_PERL5=	configure

MAN3=	DJabberd.3\
	DJabberd::Agent.3\
	DJabberd::Agent::Node.3\
	DJabberd::Component.3\
	DJabberd::Component::Example.3\
	DJabberd::Component::External.3\
	DJabberd::Component::Node.3\
	DJabberd::Config.3\
	DJabberd::Connection::ComponentIn.3\
	DJabberd::Connection::ComponentOut.3\
	DJabberd::Delivery::ComponentConnection.3\
	DJabberd::Delivery::LocalVHosts.3\
	DJabberd::SASL.3\
	DJabberd::SASL::AuthenSASL.3\
	DJabberd::SASL::Connection.3\
	DJabberd::SASL::DumbPlain.3\
	DJabberd::SASL::ManagerBase.3

.include <bsd.port.mk>
