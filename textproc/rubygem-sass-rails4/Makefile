# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	sass-rails
PORTVERSION=	4.0.5
PORTREVISION=	3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX?=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sass adapter for the Rails asset pipeline

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS?=	rubygem-railties4>=4.0.0:www/rubygem-railties4 \
		rubygem-sass>=3.2.2:textproc/rubygem-sass \
		rubygem-sprockets>=2.8:devel/rubygem-sprockets \
		rubygem-sprockets-rails>=2.0:devel/rubygem-sprockets-rails

PORTSCOUT=	limit:^4\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
