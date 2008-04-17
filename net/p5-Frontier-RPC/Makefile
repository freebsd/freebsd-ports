# ex:ts=8
# New ports collection makefile for:	p5-Frontier-RPC
# Date created:			Mar 8, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Frontier-RPC
PORTVERSION=	0.07.b4
CATEGORIES=	net perl5
MASTER_SITES=	CPAN \
		http://bitsko.slc.ut.us/~ken/xml-rpc/
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.07b4

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Frontier::RPC implements UserLand Software's XML RPC

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=	Apache::XMLRPC.3 \
	Frontier::Client.3 \
	Frontier::Daemon.3 \
	Frontier::RPC2.3 \
	Frontier::Responder.3

.include <bsd.port.mk>
