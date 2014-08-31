# $FreeBSD$

PORTNAME=	net-scp
PORTVERSION=	1.1.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	11

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Non-interactive SCP processing

LICENSE=	MIT

RUN_DEPENDS=	rubygem-net-ssh27=2.7.0,2:${PORTSDIR}/security/rubygem-net-ssh27

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PORTSCOUT=	limit:^1\.1

.include <bsd.port.mk>
