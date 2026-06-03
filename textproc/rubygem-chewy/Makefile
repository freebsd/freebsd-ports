PORTNAME=	chewy
PORTVERSION=	8.0.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ODM and wrapper for Elasticsearch client
WWW=		https://github.com/toptal/chewy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport81>=7.2:devel/rubygem-activesupport81 \
		rubygem-elasticsearch8>=8.14<9.0:textproc/rubygem-elasticsearch8 \
		rubygem-elasticsearch-dsl>=0:textproc/rubygem-elasticsearch-dsl

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
