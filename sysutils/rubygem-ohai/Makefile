# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	ohai
PORTVERSION=	7.2.4
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	Ohai profiles your system and emits JSON

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-ffi>=1.9:devel/rubygem-ffi \
		rubygem-ffi-yajl>=1.0:devel/rubygem-ffi-yajl \
		rubygem-ipaddress>=0:net/rubygem-ipaddress \
		rubygem-mime-types1>=1.16:misc/rubygem-mime-types1 \
		rubygem-mixlib-cli>=0:devel/rubygem-mixlib-cli \
		rubygem-mixlib-config>=2.0:devel/rubygem-mixlib-config \
		rubygem-mixlib-log>=0:devel/rubygem-mixlib-log \
		rubygem-mixlib-shellout>=1.2:devel/rubygem-mixlib-shellout \
		rubygem-systemu>=2.6.4:devel/rubygem-systemu \
		rubygem-wmi-lite>=1.0:devel/rubygem-wmi-lite

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/ohai

.include <bsd.port.mk>
