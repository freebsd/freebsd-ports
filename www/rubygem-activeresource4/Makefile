# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	activeresource
PORTVERSION=	4.1.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Coherent wrapper object-relational mapping for REST web services

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activemodel4>=4.0<5:databases/rubygem-activemodel4 \
		rubygem-activesupport4>=4.0<5:devel/rubygem-activesupport4 \
		rubygem-rails-observers>=0.1.2<0.2:devel/rubygem-rails-observers

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^4\.

.include <bsd.port.mk>
