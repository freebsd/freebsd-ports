# Created by: Espen Tagestad <espen@tagestad.no>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-ValidateRM
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Help validate forms with the CGI::Application framework

BUILD_DEPENDS=	p5-HTML-FillInForm>=0:${PORTSDIR}/www/p5-HTML-FillInForm \
		p5-Data-FormValidator>=0:${PORTSDIR}/textproc/p5-Data-FormValidator \
		p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
