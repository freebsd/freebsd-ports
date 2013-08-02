# Created by: Kelly Cochran <kcochran@trolans.net>
# $FreeBSD$

PORTNAME=	Net-OSCAR
PORTVERSION=	1.928
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for the AOL Instant Messenger OSCAR protocol

BUILD_DEPENDS=	p5-SOCKS>=0:${PORTSDIR}/net/p5-Socks \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Net::OSCAR.3 \
	Net::OSCAR::Buddylist.3 \
	Net::OSCAR::Callbacks.3 \
	Net::OSCAR::Common.3 \
	Net::OSCAR::Connection.3 \
	Net::OSCAR::Connection::Chat.3 \
	Net::OSCAR::Connection::Direct.3 \
	Net::OSCAR::Connection::Server.3 \
	Net::OSCAR::Constants.3 \
	Net::OSCAR::MethodInfo.3 \
	Net::OSCAR::Screenname.3 \
	Net::OSCAR::ServerCallbacks.3 \
	Net::OSCAR::TLV.3 \
	Net::OSCAR::Utility.3 \
	Net::OSCAR::XML.3 \
	Net::OSCAR::_BLInternal.3

.include <bsd.port.mk>
