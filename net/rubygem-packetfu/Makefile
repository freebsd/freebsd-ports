# $FreeBSD$

PORTNAME=	packetfu
PORTVERSION=	1.1.11
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Mid-level packet manipulation library for Ruby

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-network_interface>=0:net/rubygem-network_interface \
		rubygem-pcaprub>=0.12:net/rubygem-pcaprub

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	test/func_lldp.rb

.include <bsd.port.mk>
