# $FreeBSD$

PORTNAME=	puppet_forge
PORTVERSION=	2.3.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby client for the Puppet Forge API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday>=0.9.0:www/rubygem-faraday \
		rubygem-faraday_middleware>=0.9.0<0.13.0:www/rubygem-faraday_middleware \
		rubygem-gettext-setup>=0.11<1:devel/rubygem-gettext-setup \
		rubygem-minitar>=0:archivers/rubygem-minitar \
		rubygem-semantic_puppet>=1.0<2:devel/rubygem-semantic_puppet

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
