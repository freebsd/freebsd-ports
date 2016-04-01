# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Session-Store-Memcached
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Memcached storage backend for session data

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Cache-Memcached-Managed>=0:databases/p5-Cache-Memcached-Managed \
		p5-Catalyst-Plugin-Session>=0.26:www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Runtime>=0:www/p5-Catalyst-Runtime \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Emulate-Class-Accessor-Fast>=0:devel/p5-MooseX-Emulate-Class-Accessor-Fast \
		p5-namespace-clean>=0:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
