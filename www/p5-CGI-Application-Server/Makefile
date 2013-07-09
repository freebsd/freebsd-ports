# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	CGI-Application-Server
PORTVERSION=	0.063
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Simple HTTP server for developing with CGI::Application

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI-Application>4.21:${PORTSDIR}/www/p5-CGI-Application \
		p5-CGI-Application-Plugin-Redirect>0:${PORTSDIR}/www/p5-CGI-Application-Plugin-Redirect \
		p5-HTTP-Message>0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-HTTP-Server-Simple>=0.18:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-HTTP-Server-Simple-Static>=0.02:${PORTSDIR}/www/p5-HTTP-Server-Simple-Static
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-CGI-Application>0:${PORTSDIR}/www/p5-CGI-Application \
		p5-CGI-Application-Dispatch>0:${PORTSDIR}/www/p5-CGI-Application-Dispatch \
		p5-CGI-Application-Plugin-Redirect>0:${PORTSDIR}/www/p5-CGI-Application-Plugin-Redirect \
		p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-HTTP-Server-Simple>0:${PORTSDIR}/www/p5-Test-HTTP-Server-Simple \
		p5-Test-WWW-Mechanize>0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize

PERL_CONFIGURE=	yes

MAN3=	CGI::Application::Server.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
