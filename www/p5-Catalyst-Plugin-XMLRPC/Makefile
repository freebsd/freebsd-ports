# New ports collection makefile for:	www/p5-Catalyst-Plugin-XMLRPC
# Date created:				2 Dec 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-XMLRPC
PORTVERSION=	2.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dispatch XMLRPC methods with Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-RPC-XML>=0:${PORTSDIR}/net/p5-RPC-XML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Catalyst::Plugin::XMLRPC.3 \
		Catalyst::Plugin::XMLRPC::DispatchType::XMLRPC.3 \
		Catalyst::Action::XMLRPC.3

.include <bsd.port.mk>
