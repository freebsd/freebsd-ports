PORTNAME=	chef-config
PORTVERSION=	17.10.68
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	17

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Default configuration and config loading library for Chef
WWW=		https://github.com/chef/chef/tree/main/chef-config

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=0:www/rubygem-addressable \
		rubygem-chef-utils17>=${PORTVERSION}<${PORTVERSION}_99:sysutils/rubygem-chef-utils17 \
		rubygem-fuzzyurl>=0:www/rubygem-fuzzyurl \
		rubygem-mixlib-config>=2.2.12<4.0:devel/rubygem-mixlib-config \
		rubygem-mixlib-shellout>=2.0<4.0:devel/rubygem-mixlib-shellout \
		rubygem-tomlrb1>=1.2<2:textproc/rubygem-tomlrb1

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^17\.

.include <bsd.port.mk>
