# Ports collection makefile for: p5-Catalyst-Plugin-ConfigLoader-Environment
# Date created:			 Apr 6, 2007
# Whom:				 lbr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-ConfigLoader-Environment
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Configure your application with environment variables

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-JSON-Any>=0:${PORTSDIR}/converters/p5-JSON-Any

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Plugin::ConfigLoader::Environment.3

.include <bsd.port.mk>
