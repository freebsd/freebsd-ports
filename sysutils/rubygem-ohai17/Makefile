PORTNAME=	ohai
PORTVERSION=	17.9.1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	17

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ohai profiles your system and emits JSON
WWW=		https://github.com/chef/ohai

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-chef-config17>=14.12<18:sysutils/rubygem-chef-config17 \
		rubygem-chef-utils17>=16.0<18:sysutils/rubygem-chef-utils17 \
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

PORTSCOUT=	limit:^17\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/ohai

.include <bsd.port.mk>
