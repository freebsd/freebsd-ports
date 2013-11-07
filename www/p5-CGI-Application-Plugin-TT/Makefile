# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-TT
PORTVERSION=	1.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Add Template Toolkit support to CGI::Application

BUILD_DEPENDS=	p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Class-ISA>=0:${PORTSDIR}/devel/p5-Class-ISA \
		p5-CGI-Application-Plugin-DevPopup>=0:${PORTSDIR}/www/p5-CGI-Application-Plugin-DevPopup
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
