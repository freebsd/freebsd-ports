PORTNAME=	ohai
PORTVERSION=	18.2.6
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ohai profiles your system and emits JSON
WWW=		https://github.com/chef/ohai

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-chef-config>=14.12<19:sysutils/rubygem-chef-config \
		rubygem-chef-utils>=16.0<19:sysutils/rubygem-chef-utils \
		rubygem-ffi>=1.9<2:devel/rubygem-ffi \
		rubygem-ffi-yajl>=2.2<3:devel/rubygem-ffi-yajl \
		rubygem-ipaddress>=0:net/rubygem-ipaddress \
		rubygem-mixlib-cli>=1.7.0:devel/rubygem-mixlib-cli \
		rubygem-mixlib-config>=2.0<4.0:devel/rubygem-mixlib-config \
		rubygem-mixlib-log>=2.0.1<4.0:devel/rubygem-mixlib-log \
		rubygem-mixlib-shellout>=3.2.5<4:devel/rubygem-mixlib-shellout \
		rubygem-plist>=3.1<4:devel/rubygem-plist \
		rubygem-train-core>=0:net/rubygem-train-core \
		rubygem-wmi-lite>=1.0<2:devel/rubygem-wmi-lite

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/ohai

.include <bsd.port.mk>
