# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rails-dom-testing
PORTVERSION=	2.0.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Analyse and compare DOMs using Nokogiri

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport50>0:devel/rubygem-activesupport50 \
		rubygem-nokogiri>=1.6:textproc/rubygem-nokogiri \
		rubygem-rails-deprecated_sanitizer-rails50>=1.0.1:devel/rubygem-rails-deprecated_sanitizer-rails50

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
