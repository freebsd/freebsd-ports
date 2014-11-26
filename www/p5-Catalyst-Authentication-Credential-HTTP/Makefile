# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	Catalyst-Authentication-Credential-HTTP
PORTVERSION=	1.016
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	HTTP plain and digest authentication plugin for Catalyst

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Plugin-Authentication>=0.10005:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication \
		p5-Catalyst-Runtime>0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Data-UUID>=0.11:${PORTSDIR}/devel/p5-Data-UUID \
		p5-String-Escape>0:${PORTSDIR}/textproc/p5-String-Escape \
		p5-URI>0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
