# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch-model
PORTVERSION=	0.1.9
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	019

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	ActiveModel/Record integrations for Elasticsearch

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-activesupport52>=3:devel/rubygem-activesupport52 \
		rubygem-elasticsearch503>=0.4:textproc/rubygem-elasticsearch503 \
		rubygem-hashie>=0:devel/rubygem-hashie

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.1\.9

.include <bsd.port.mk>
