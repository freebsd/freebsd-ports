PORTNAME=	chef-licensing
PORTVERSION=	1.1.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Support CLI tools that use Progress Chef license storage, generation, and entitlement
WWW=		https://github.com/chef/chef-licensing

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-activesupport72>=7.2.2.1<8:devel/rubygem-activesupport72 \
		rubygem-chef-config>=15:sysutils/rubygem-chef-config \
		rubygem-faraday>=1<3:www/rubygem-faraday \
		rubygem-faraday-http-cache>=0:www/rubygem-faraday-http-cache \
		rubygem-ostruct>=0.1.0<1:devel/rubygem-ostruct \
		rubygem-tty-prompt>=0.23<1:devel/rubygem-tty-prompt \
		rubygem-tty-spinner>=0.9.3<0.10:devel/rubygem-tty-spinner

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
