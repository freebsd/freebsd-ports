# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	ohai
PORTVERSION=	7.0.2
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	Ohai profiles your system and emits JSON

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-ipaddress>=0:${PORTSDIR}/net/rubygem-ipaddress \
		rubygem-mime-types>=1.16:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-mixlib-cli>=0:${PORTSDIR}/devel/rubygem-mixlib-cli \
		rubygem-mixlib-config>=0:${PORTSDIR}/devel/rubygem-mixlib-config \
		rubygem-mixlib-log>=0:${PORTSDIR}/devel/rubygem-mixlib-log \
		rubygem-mixlib-shellout>=0:${PORTSDIR}/devel/rubygem-mixlib-shellout \
		rubygem-systemu>=2.5.2:${PORTSDIR}/devel/rubygem-systemu \
		rubygem-yajl-ruby>=0:${PORTSDIR}/devel/rubygem-yajl-ruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/ohai

.include <bsd.port.mk>
