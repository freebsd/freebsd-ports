# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	CGI-Application-Dispatch
PORTVERSION=	3.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN/CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	Dispatch requests to CGI::Application based objects

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI-Application>=4.50:${PORTSDIR}/www/p5-CGI-Application \
		p5-CGI-PSGI>=0:${PORTSDIR}/www/p5-CGI-PSGI \
		p5-Exception-Class>=1.20:${PORTSDIR}/devel/p5-Exception-Class \
		p5-HTTP-Exception>=0:${PORTSDIR}/www/p5-HTTP-Exception \
		p5-Plack>=0.9956:${PORTSDIR}/www/p5-Plack \
		p5-Test-LongString>=0:${PORTSDIR}/devel/p5-Test-LongString \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		CGI::Application::Dispatch.3 \
		CGI::Application::Dispatch::PSGI.3 \
		CGI::Application::Dispatch::Regexp.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-version>=0.82:${PORTSDIR}/devel/p5-version
RUN_DEPENDS+=	p5-version>=0.82:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
