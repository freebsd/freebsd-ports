# ex:ts=8
# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Frontier-RPC
PORTVERSION=	0.07.b4
CATEGORIES=	net perl5
MASTER_SITES=	CPAN \
		http://bitsko.slc.ut.us/~ken/xml-rpc/
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.07b4

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Frontier::RPC implements UserLand Software's XML RPC

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

MAN3=	Apache::XMLRPC.3 \
	Frontier::Client.3 \
	Frontier::Daemon.3 \
	Frontier::RPC2.3 \
	Frontier::Responder.3

.include <bsd.port.mk>
