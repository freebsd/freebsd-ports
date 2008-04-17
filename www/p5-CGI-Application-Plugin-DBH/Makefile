# New ports collection makefile for:	CGI::Application::Plugin::DBH
# Date created:				02 December 2005
# Whom:					Espen Tagestad <espen@tagestad.no>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-DBH
PORTVERSION=	4.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	espen@tagestad.no
COMMENT=	Easy DBI access from CGI::Application

BUILD_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/CGI/Carp.pm:${PORTSDIR}/www/p5-CGI-modules \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/DBD/Mock.pm:${PORTSDIR}/databases/p5-DBD-Mock
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PERL_MODBUILD=	5.8.6+

MAN3=		CGI::Application::Plugin::DBH.3

.include <bsd.port.mk>
