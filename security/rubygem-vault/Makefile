PORTNAME=	vault
PORTVERSION=	0.19.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby API client for interacting with a Vault server
WWW=		https://github.com/hashicorp/vault-ruby

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-aws-sigv4>=0:devel/rubygem-aws-sigv4 \
		rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-connection_pool>=2.4<3:net/rubygem-connection_pool \
		rubygem-net-http-persistent>=4.0.2<5:www/rubygem-net-http-persistent

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
