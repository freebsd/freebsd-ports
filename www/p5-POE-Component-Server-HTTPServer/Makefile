# New ports collection makefile for:	POE-Component-Server-HTTPServer
# Date created:		23 Feb 2005
# Whom:			Zach Thompson <lin-chi@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Server-HTTPServer
PORTVERSION=	0.9.2
CATEGORIES=	www devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	lin-chi@lastamericanempire.com
COMMENT=	POE Component to server HTTP requests

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/HTTP/Message.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/HTTP/Status.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/HTML/Template/HashWrapper.pm:${PORTSDIR}/www/p5-HTML-Template-HashWrapper \
		${SITE_PERL}/MIME/Types.pm:${PORTSDIR}/mail/p5-MIME-Types
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		POE::Component::Server::HTTPServer.3 \
		POE::Component::Server::HTTPServer::BasicAuthenHandler.3 \
		POE::Component::Server::HTTPServer::Examples.3 \
		POE::Component::Server::HTTPServer::Handler.3 \
		POE::Component::Server::HTTPServer::NotFoundHandler.3 \
		POE::Component::Server::HTTPServer::ParameterParseHandler.3 \
		POE::Component::Server::HTTPServer::StaticHandler.3 \
		POE::Component::Server::HTTPServer::TemplateHandler.3

.include <bsd.port.mk>
