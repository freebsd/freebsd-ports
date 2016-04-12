# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	CGI-Application-Server
PORTVERSION=	0.063
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Simple HTTP server for developing with CGI::Application

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI-Application>4.21:www/p5-CGI-Application \
		p5-CGI-Application-Plugin-Redirect>0:www/p5-CGI-Application-Plugin-Redirect \
		p5-HTTP-Message>0:www/p5-HTTP-Message \
		p5-HTTP-Server-Simple>=0.18:www/p5-HTTP-Server-Simple \
		p5-HTTP-Server-Simple-Static>=0.02:www/p5-HTTP-Server-Simple-Static
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-CGI-Application>0:www/p5-CGI-Application \
		p5-CGI-Application-Dispatch>0:www/p5-CGI-Application-Dispatch \
		p5-CGI-Application-Plugin-Redirect>0:www/p5-CGI-Application-Plugin-Redirect \
		p5-Test-Exception>0:devel/p5-Test-Exception \
		p5-Test-HTTP-Server-Simple>0:www/p5-Test-HTTP-Server-Simple \
		p5-Test-WWW-Mechanize>0:devel/p5-Test-WWW-Mechanize

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
