# Created by: Ryan Steinmetz <zi@FreeBSD.org>

PORTNAME=	elasticsearch-transport
PORTVERSION=	7.13.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	713

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby client for Elasticsearch

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-faraday>=1<2:www/rubygem-faraday \
		rubygem-multi_json>=0:devel/rubygem-multi_json

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.13\.

.include <bsd.port.mk>
