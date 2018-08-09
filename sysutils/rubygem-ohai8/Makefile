# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	ohai
PORTVERSION=	8.26.1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	8

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ohai profiles your system and emits JSON

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-chef-config12<14.0:sysutils/rubygem-chef-config12 \
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

CONFLICTS_INSTALL=	rubygem-ohai

PLIST_FILES=	bin/ohai

.include <bsd.port.mk>
