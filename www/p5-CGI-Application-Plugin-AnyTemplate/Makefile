# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-AnyTemplate
PORTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Use any templating system in CGI::Application

BUILD_DEPENDS=	p5-CGI-Application-Plugin-Forward>=0:${PORTSDIR}/www/p5-CGI-Application-Plugin-Forward \
		p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application \
		p5-Clone>=0.23:${PORTSDIR}/devel/p5-Clone
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
