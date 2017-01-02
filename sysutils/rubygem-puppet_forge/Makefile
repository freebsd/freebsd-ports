# $FreeBSD$

PORTNAME=	puppet_forge
PORTVERSION=	2.2.2
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby client for the Puppet Forge API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday>=0.9.0:www/rubygem-faraday \
		rubygem-faraday_middleware>=0.9.0:www/rubygem-faraday_middleware \
		rubygem-gettext-setup>=0.3:devel/rubygem-gettext-setup \
		rubygem-minitar>=0:archivers/rubygem-minitar \
		rubygem-semantic_puppet>=0.1.0:devel/rubygem-semantic_puppet

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
