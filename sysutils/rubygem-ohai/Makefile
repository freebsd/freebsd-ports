# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	ohai
PORTVERSION=	15.9.1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ohai profiles your system and emits JSON

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-chef-config>=12.8<16:sysutils/rubygem-chef-config \
		rubygem-ffi>=1.9<2:devel/rubygem-ffi \
		rubygem-ffi-yajl>=2.2<3:devel/rubygem-ffi-yajl \
		rubygem-ipaddress>=0:net/rubygem-ipaddress \
		rubygem-mixlib-cli>=1.7.0:devel/rubygem-mixlib-cli \
		rubygem-mixlib-config>=2.0<4:devel/rubygem-mixlib-config \
		rubygem-mixlib-log>=2.0.1<4:devel/rubygem-mixlib-log \
		rubygem-mixlib-shellout>=2.0.1<4:devel/rubygem-mixlib-shellout \
		rubygem-plist>=3.1<4:devel/rubygem-plist \
		rubygem-systemu>=2.6.4<2.7:devel/rubygem-systemu \
		rubygem-wmi-lite>=1.0<2:devel/rubygem-wmi-lite

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/ohai

.include <bsd.port.mk>
