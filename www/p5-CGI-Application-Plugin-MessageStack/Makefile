# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-MessageStack
PORTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Message stack for your CGI::Application

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI-Application>=0:www/p5-CGI-Application \
		p5-CGI-Application-Plugin-Session>=0:www/p5-CGI-Application-Plugin-Session \
		p5-CGI-Application-Plugin-TT>=0:www/p5-CGI-Application-Plugin-TT
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
