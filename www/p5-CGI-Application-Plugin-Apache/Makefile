# Created by: Kurt Lidl <kurt.lidl@cello.com>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-Apache
PORTVERSION=	1.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides easy access to Apache::* modules for CGI::Application

BUILD_DEPENDS=	p5-CGI-Application>=3.22:${PORTSDIR}/www/p5-CGI-Application \
		p5-HTML-GenerateUtil>=0:${PORTSDIR}/www/p5-HTML-GenerateUtil \
		p5-libapreq2>=0:${PORTSDIR}/www/p5-libapreq2
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE_COMB=	dual
LICENSE=	ART10 GPLv1

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
