# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch
PORTVERSION=	6.8.1
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	6

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby integrations for Elasticsearch

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# Fix this again if 6.8.2 is released this should be an = restriction
RUN_DEPENDS=	rubygem-elasticsearch-api6>=${PORTVERSION}<6.8.2:textproc/rubygem-elasticsearch-api6 \
		rubygem-elasticsearch-transport6>=${PORTVERSION}<6.8.2:textproc/rubygem-elasticsearch-transport6

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
