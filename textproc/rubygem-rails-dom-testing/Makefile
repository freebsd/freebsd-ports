# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rails-dom-testing
PORTVERSION=	1.0.6
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Analyse and compare DOMs using Nokogiri

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport4>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-nokogiri>1.6:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-rails-deprecated_sanitizer>1.0:${PORTSDIR}/devel/rubygem-rails-deprecated_sanitizer

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
