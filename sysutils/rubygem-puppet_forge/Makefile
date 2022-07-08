PORTNAME=	puppet_forge
PORTVERSION=	3.2.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby client for the Puppet Forge API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday1>=1.3:www/rubygem-faraday1 \
		rubygem-faraday_middleware>=1.0:www/rubygem-faraday_middleware \
		rubygem-minitar>=0:archivers/rubygem-minitar \
		rubygem-semantic_puppet>=1.0<2:devel/rubygem-semantic_puppet

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
