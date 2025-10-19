PORTNAME=	puppet_forge
PORTVERSION=	6.0.0
PORTREVISION=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby client for the Puppet Forge API
WWW=		https://github.com/puppetlabs/forge-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday>=2.0<3:www/rubygem-faraday \
		rubygem-faraday-follow_redirects>=0.3.0<1:www/rubygem-faraday-follow_redirects \
		rubygem-minitar>=1.0.2<2:archivers/rubygem-minitar \
		rubygem-semantic_puppet>=1.0<2:devel/rubygem-semantic_puppet

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
