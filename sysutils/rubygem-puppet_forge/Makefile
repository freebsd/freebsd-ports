# $FreeBSD$

PORTNAME=	puppet_forge
PORTVERSION=	2.1.4
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby client for the Puppet Forge API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday>=0.9.0:www/rubygem-faraday \
		rubygem-faraday_middleware>=0.9.0:www/rubygem-faraday_middleware \
		rubygem-minitar>=0:archivers/rubygem-minitar \
		rubygem-semantic_puppet>=0.1.0:devel/rubygem-semantic_puppet

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
