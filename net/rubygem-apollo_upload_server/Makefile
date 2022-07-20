PORTNAME=	apollo_upload_server
PORTVERSION=	2.1.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Apollo-upload-server middleware for rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-actionpack61>=4.2:www/rubygem-actionpack61 \
		rubygem-graphql>=1.8:devel/rubygem-graphql

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
