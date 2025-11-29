PORTNAME=	chef-licensing
PORTVERSION=	1.3.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Support CLI tools that use Progress Chef license storage, generation, and entitlement
WWW=		https://github.com/chef/chef-licensing

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-chef-config>=15:sysutils/rubygem-chef-config \
		rubygem-faraday>=1<3:www/rubygem-faraday \
		rubygem-faraday-http-cache>=0:www/rubygem-faraday-http-cache \
		rubygem-faraday_middleware>=1.0<2:www/rubygem-faraday_middleware \
		rubygem-mixlib-log>=3.0<4:devel/rubygem-mixlib-log \
		rubygem-ostruct>=0.1.0<1:devel/rubygem-ostruct \
		rubygem-pstore>=0.1.1<1:devel/rubygem-pstore \
		rubygem-tty-prompt>=0.23<1:devel/rubygem-tty-prompt \
		rubygem-tty-spinner>=0.9.3<0.10:devel/rubygem-tty-spinner

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
