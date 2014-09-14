# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	activeresource
PORTVERSION=	4.0.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Coherent wrapper object-relational mapping for REST web services

RUN_DEPENDS=	rubygem-activemodel4>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activemodel4 \
		rubygem-activesupport4>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-rails-observers>=0.1.1:${PORTSDIR}/devel/rubygem-rails-observers

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
