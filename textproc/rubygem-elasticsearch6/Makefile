# Created by: Ryan Steinmetz <zi@FreeBSD.org>

PORTNAME=	elasticsearch
PORTVERSION=	6.8.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	6

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby integrations for Elasticsearch

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-elasticsearch-api6>=${PORTVERSION}<${PORTVERSION}_99:textproc/rubygem-elasticsearch-api6 \
		rubygem-elasticsearch-transport6>=${PORTVERSION}<${PORTVERSION}_99:textproc/rubygem-elasticsearch-transport6

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
