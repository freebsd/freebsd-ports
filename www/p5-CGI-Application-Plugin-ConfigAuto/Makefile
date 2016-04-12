# Created by: Alex Kapranoff <alex@kapranoff.ru>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-ConfigAuto
PORTVERSION=	1.33
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Plugin that adds Config::Auto support to CGI::Application

RUN_DEPENDS=	p5-CGI-Application>=0:www/p5-CGI-Application \
		p5-Config-Auto>=0:devel/p5-Config-Auto
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
