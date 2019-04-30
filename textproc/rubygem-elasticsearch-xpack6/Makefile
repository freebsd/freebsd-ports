# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch-xpack
PORTVERSION=	6.3.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	6

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby integrations for the X-Pack extensions for Elasticsearch

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-elasticsearch-api6>=${PORTVERSION:R:R}:textproc/rubygem-elasticsearch-api6

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.

.include <bsd.port.mk>
