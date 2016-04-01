# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Session-Store-FastMmap
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	FastMmap session storage backend

BUILD_DEPENDS=	p5-Cache-FastMmap>=1.29:devel/p5-Cache-FastMmap \
		p5-Catalyst-Plugin-Session>=0.27:www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Runtime>=5.80000:www/p5-Catalyst-Runtime \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat \
		p5-MooseX-Emulate-Class-Accessor-Fast>=0:devel/p5-MooseX-Emulate-Class-Accessor-Fast \
		p5-Path-Class>=0:devel/p5-Path-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
