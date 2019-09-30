# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch-transport
PORTVERSION=	5.0.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	503

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby client for Elasticsearch

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday>=0:www/rubygem-faraday \
		rubygem-multi_json>=0:devel/rubygem-multi_json

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
