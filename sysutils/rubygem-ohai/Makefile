# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	ohai
PORTVERSION=	7.2.4
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	Ohai profiles your system and emits JSON

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-ffi>=1.9.0:${PORTSDIR}/devel/rubygem-ffi \
		rubygem-ffi-yajl>=1.0.1:${PORTSDIR}/devel/rubygem-ffi-yajl \
		rubygem-ipaddress>=0:${PORTSDIR}/net/rubygem-ipaddress \
		rubygem-mime-types1>=1.16:${PORTSDIR}/misc/rubygem-mime-types1 \
		rubygem-mixlib-cli>=0:${PORTSDIR}/devel/rubygem-mixlib-cli \
		rubygem-mixlib-config>=0:${PORTSDIR}/devel/rubygem-mixlib-config \
		rubygem-mixlib-log>=0:${PORTSDIR}/devel/rubygem-mixlib-log \
		rubygem-mixlib-shellout>=0:${PORTSDIR}/devel/rubygem-mixlib-shellout \
		rubygem-systemu>=2.6.4:${PORTSDIR}/devel/rubygem-systemu \
		rubygem-wmi-lite>=1.0.0:${PORTSDIR}/devel/rubygem-wmi-lite

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/ohai

.include <bsd.port.mk>
