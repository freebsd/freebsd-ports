# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rye
PORTVERSION=	0.9.13
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Safely run SSH commands on a bunch of machines at the same time

LICENSE=	MIT

RUN_DEPENDS=	rubygem-annoy>=0:${PORTSDIR}/devel/rubygem-annoy \
		rubygem-docile>=1.0.1:${PORTSDIR}/devel/rubygem-docile \
		rubygem-highline>=1.5.1:${PORTSDIR}/devel/rubygem-highline \
		rubygem-net-scp>=1.0.2:${PORTSDIR}/security/rubygem-net-scp \
		rubygem-net-ssh>=2.0.13:${PORTSDIR}/security/rubygem-net-ssh \
		rubygem-sysinfo>=0.8.1:${PORTSDIR}/devel/rubygem-sysinfo

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
