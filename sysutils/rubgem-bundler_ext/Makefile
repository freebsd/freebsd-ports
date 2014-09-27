# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bundler_ext
PORTVERSION=	0.4.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Loads gems installed on the system using Bundler Gemfile DSL

LICENSE=	MIT

RUN_DEPENDS=	rubygem-bundler>=1.7:${PORTSDIR}/sysutils/rubygem-bundler
BUILD_DEPENDS=	rubygem-rspec>=3:${PORTSDIR}/devel/rubygem-rspec

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
