# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-Authorization
PORTVERSION=	0.07
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Support for authorization of requests in CGI::Application

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI-Application>=0:www/p5-CGI-Application \
		p5-Class-ISA>=0:devel/p5-Class-ISA \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require \
		p5-CGI-Application-Plugin-Authentication>=0:www/p5-CGI-Application-Plugin-Authentication \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Warn>=0:devel/p5-Test-Warn
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
