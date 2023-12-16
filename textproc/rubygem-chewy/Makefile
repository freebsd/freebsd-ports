PORTNAME=	chewy
PORTVERSION=	7.4.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ODM and wrapper for Elasticsearch client
WWW=		https://github.com/toptal/chewy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport60>=4.0:devel/rubygem-activesupport60 \
		rubygem-elasticsearch713>=7.12.0<7.14.0:textproc/rubygem-elasticsearch713 \
		rubygem-elasticsearch-dsl>=0:textproc/rubygem-elasticsearch-dsl

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
