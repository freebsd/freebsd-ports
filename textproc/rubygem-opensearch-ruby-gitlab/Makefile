PORTNAME=	opensearch-ruby
PORTVERSION=	3.4.0
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby client for OpenSearch
WWW=		https://github.com/opensearch-project/opensearch-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday-gitlab>=1.0<3:www/rubygem-faraday-gitlab \
		rubygem-multi_json-gitlab>=1.0:devel/rubygem-multi_json-gitlab

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/opensearch_ruby_console

.include <bsd.port.mk>
