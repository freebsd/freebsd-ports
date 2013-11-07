# Created by: andrey@kostenko.name
# $FreeBSD$

PORTNAME=	Catalyst-Controller-RateLimit
PORTVERSION=	0.28
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Protect your site from robots

BUILD_DEPENDS=	p5-Algorithm-FloodControl>=1.91:${PORTSDIR}/devel/p5-Algorithm-FloodControl \
		p5-Catalyst-Plugin-Cache-FastMmap>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Cache-FastMmap \
		p5-Catalyst-Plugin-ConfigLoader>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-ConfigLoader \
		p5-Catalyst-Runtime>=5.7002:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-WWW-Mechanize-Catalyst>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize-Catalyst \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
