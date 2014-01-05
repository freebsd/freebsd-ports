# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Cache-Memcached-Fast
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Catalyst Plugin for Cache::Memcached::Fast

BUILD_DEPENDS=	p5-Cache-Memcached-Fast>=0:${PORTSDIR}/databases/p5-Cache-Memcached-Fast \
		p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
