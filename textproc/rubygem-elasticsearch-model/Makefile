# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	elasticsearch-model
PORTVERSION=	7.2.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ActiveModel/Record integrations for Elasticsearch

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport5>=3:devel/rubygem-activesupport5 \
		rubygem-elasticsearch>=7<8:textproc/rubygem-elasticsearch \
		rubygem-hashie>=0:devel/rubygem-hashie

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
