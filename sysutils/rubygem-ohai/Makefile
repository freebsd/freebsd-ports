# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	ohai
PORTVERSION=	13.8.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ohai profiles your system and emits JSON

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-chef-config>=12.5.0:sysutils/rubygem-chef-config \
		rubygem-ffi>=1.9:devel/rubygem-ffi \
		rubygem-ffi-yajl>=2.2:devel/rubygem-ffi-yajl \
		rubygem-ipaddress>=0:net/rubygem-ipaddress \
		rubygem-mixlib-cli>=0:devel/rubygem-mixlib-cli \
		rubygem-mixlib-config>=2.0:devel/rubygem-mixlib-config \
		rubygem-mixlib-log>=1.7.1:devel/rubygem-mixlib-log \
		rubygem-mixlib-shellout>=2.0:devel/rubygem-mixlib-shellout \
		rubygem-plist>=3.1:devel/rubygem-plist \
		rubygem-systemu>=2.6.4:devel/rubygem-systemu \
		rubygem-wmi-lite>=1.0:devel/rubygem-wmi-lite

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/ohai

.include <bsd.port.mk>
