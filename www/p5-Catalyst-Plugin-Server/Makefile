# New ports collection makefile for:	Catalyst-Plugin-Server
# Date created:	   05 August 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Server
PORTVERSION=	0.28
CATEGORIES=	www devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Catalyst Server Plugin: Base & XMLRPC

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Clone-Fast>=0:${PORTSDIR}/devel/p5-Clone-Fast \
		${SITE_PERL}/RPC/XML.pm:${PORTSDIR}/net/p5-RPC-XML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Plugin::Server.3 Catalyst::Plugin::Server::XMLRPC.3 \
		Catalyst::Plugin::Server::XMLRPC::DispatchType::XMLRPCPath.3 \
		Catalyst::Plugin::Server::XMLRPC::DispatchType::XMLRPCRegex.3 \
		Catalyst::Plugin::Server::XMLRPC::Tutorial.3

.include <bsd.port.mk>
