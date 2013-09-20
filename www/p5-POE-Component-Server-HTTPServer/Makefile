# Created by: Zach Thompson <lin-chi@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	POE-Component-Server-HTTPServer
PORTVERSION=	0.9.2
CATEGORIES=	www devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lin-chi@lastamericanempire.com
COMMENT=	POE Component to server HTTP requests

BUILD_DEPENDS=	p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-HTML-Template-HashWrapper>=0:${PORTSDIR}/www/p5-HTML-Template-HashWrapper \
		p5-MIME-Types>=0:${PORTSDIR}/mail/p5-MIME-Types
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		POE::Component::Server::HTTPServer.3 \
		POE::Component::Server::HTTPServer::BasicAuthenHandler.3 \
		POE::Component::Server::HTTPServer::Examples.3 \
		POE::Component::Server::HTTPServer::Handler.3 \
		POE::Component::Server::HTTPServer::NotFoundHandler.3 \
		POE::Component::Server::HTTPServer::ParameterParseHandler.3 \
		POE::Component::Server::HTTPServer::StaticHandler.3 \
		POE::Component::Server::HTTPServer::TemplateHandler.3

NO_STAGE=	yes
.include <bsd.port.mk>
