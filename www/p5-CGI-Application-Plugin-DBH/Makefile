# Created by: Espen Tagestad <espen@tagestad.no>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-DBH
PORTVERSION=	4.01
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Easy DBI access from CGI::Application

BUILD_DEPENDS=	p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Test-MockObject>=1.20120301:${PORTSDIR}/devel/p5-Test-MockObject
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
