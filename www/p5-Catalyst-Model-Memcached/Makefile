# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	Catalyst-Model-Memcached
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	catone@cpan.org
COMMENT=	Wrapper for memcached imitating Catalyst models

RUN_DEPENDS=	p5-Cache-Memcached-Fast>=0.17:${PORTSDIR}/databases/p5-Cache-Memcached-Fast \
		p5-Catalyst-Runtime>=5.8:${PORTSDIR}/www/p5-Catalyst-Runtime
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
