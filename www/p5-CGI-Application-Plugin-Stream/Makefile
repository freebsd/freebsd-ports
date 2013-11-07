# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-Stream
PORTVERSION=	2.10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin that adds file streaming support to CGI::Application

BUILD_DEPENDS=	p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application \
		p5-CGI-Application-Plugin-AutoRunmode>=0:${PORTSDIR}/www/p5-CGI-Application-Plugin-AutoRunmode \
		p5-File-MMagic>=0:${PORTSDIR}/devel/p5-File-MMagic
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
