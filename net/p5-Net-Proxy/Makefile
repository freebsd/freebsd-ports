# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	Net-Proxy
PORTVERSION=	0.12
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Framework for proxying network connections in many ways

USES=		perl5
USE_PERL5=	configure

MAN3=	Net::Proxy.3 \
	Net::Proxy::Connector.3 \
	Net::Proxy::Connector::connect.3 \
	Net::Proxy::Connector::connect_ssl.3 \
	Net::Proxy::Connector::dual.3 \
	Net::Proxy::Connector::dummy.3 \
	Net::Proxy::Connector::ssl.3 \
	Net::Proxy::Connector::tcp.3 \
	Net::Proxy::Tutorial.3

MAN1=	connect-tunnel.1 \
	sslh.1

NO_STAGE=	yes
.include <bsd.port.mk>
