# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rails-dom-testing
PORTVERSION=	2.0.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Analyse and compare DOMs using Nokogiri

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport5>0:devel/rubygem-activesupport5 \
		rubygem-nokogiri>=1.6:textproc/rubygem-nokogiri \
		rubygem-rails-deprecated_sanitizer-rails5>=1.0.1:devel/rubygem-rails-deprecated_sanitizer-rails5

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
