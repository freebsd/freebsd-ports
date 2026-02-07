PORTNAME=	chewy
PORTVERSION=	7.6.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ODM and wrapper for Elasticsearch client
WWW=		https://github.com/toptal/chewy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport60>=4.0:devel/rubygem-activesupport60 \
		rubygem-elasticsearch7>=7.14.0<8:textproc/rubygem-elasticsearch7 \
		rubygem-elasticsearch-dsl>=0:textproc/rubygem-elasticsearch-dsl

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
