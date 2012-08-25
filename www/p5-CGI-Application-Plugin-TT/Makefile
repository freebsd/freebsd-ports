# New ports collection makefile for:	www/p5-CGI-Application-Plugin-TT
# Date created:				15 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-TT
PORTVERSION=	1.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	Add Template Toolkit support to CGI::Application

BUILD_DEPENDS=	p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Class-ISA>=0:${PORTSDIR}/devel/p5-Class-ISA \
		p5-CGI-Application-Plugin-DevPopup>=0:${PORTSDIR}/www/p5-CGI-Application-Plugin-DevPopup
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	CGI::Application::Plugin::TT.3

.include <bsd.port.mk>
