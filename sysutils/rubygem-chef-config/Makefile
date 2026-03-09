PORTNAME=	chef-config
PORTVERSION=	19.1.164
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Default configuration and config loading library for Chef
WWW=		https://github.com/chef/chef/tree/main/chef-config

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=0:www/rubygem-addressable \
		rubygem-chef-utils>=${PORTVERSION}<${PORTVERSION}_99:sysutils/rubygem-chef-utils \
		rubygem-fuzzyurl>=0:www/rubygem-fuzzyurl \
		rubygem-mixlib-config>=2.2.12<4.0:devel/rubygem-mixlib-config \
		rubygem-mixlib-shellout>=2.0<4.0:devel/rubygem-mixlib-shellout \
		rubygem-racc>=0:devel/rubygem-racc \
		rubygem-tomlrb>=1.2<3:textproc/rubygem-tomlrb

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
