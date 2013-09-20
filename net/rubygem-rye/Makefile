# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rye
PORTVERSION=	0.9.8
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Safely run SSH commands on a bunch of machines at the same time

RUN_DEPENDS=	rubygem-annoy>=0:${PORTSDIR}/devel/rubygem-annoy \
		rubygem-highline>=1.5.1:${PORTSDIR}/devel/rubygem-highline \
		rubygem-net-scp>=1.0.2:${PORTSDIR}/security/rubygem-net-scp \
		rubygem-net-ssh>=2.0.13:${PORTSDIR}/security/rubygem-net-ssh \
		rubygem-docile>=1.0.1:${PORTSDIR}/devel/rubygem-docile \
		rubygem-sysinfo>=0.7.3:${PORTSDIR}/devel/rubygem-sysinfo

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
