# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-XMLRPC
PORTVERSION=	2.01
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dispatch XMLRPC methods with Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-RPC-XML>=0:${PORTSDIR}/net/p5-RPC-XML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Catalyst::Plugin::XMLRPC.3 \
		Catalyst::Plugin::XMLRPC::DispatchType::XMLRPC.3 \
		Catalyst::Action::XMLRPC.3

.include <bsd.port.mk>
