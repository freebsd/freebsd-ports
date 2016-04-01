# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-LinkIntegrity
PORTVERSION=	0.06
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Make tamper-resistent links in CGI::Application

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI-Application>=0:www/p5-CGI-Application \
		p5-URI>=0:net/p5-URI \
		p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-CGI-Application-Plugin-AutoRunmode>=0:www/p5-CGI-Application-Plugin-AutoRunmode
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
