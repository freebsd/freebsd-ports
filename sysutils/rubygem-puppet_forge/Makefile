# $FreeBSD$

PORTNAME=	puppet_forge
PORTVERSION=	2.3.4
PORTREVISION=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby client for the Puppet Forge API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday0>=0.9.0<0.18.0:www/rubygem-faraday0 \
		rubygem-faraday_middleware0>=0.9.0<0.15.0:www/rubygem-faraday_middleware0 \
		rubygem-gettext-setup>=0.11<1:devel/rubygem-gettext-setup \
		rubygem-minitar>=0:archivers/rubygem-minitar \
		rubygem-semantic_puppet>=1.0<2:devel/rubygem-semantic_puppet

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
