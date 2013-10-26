# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blimpy
PORTVERSION=	0.6.7
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tool for managing a fleet of machines in the cloud

LICENSE=	MIT

RUN_DEPENDS=	rubygem-fog>=0:${PORTSDIR}/devel/rubygem-fog \
		rubygem-minitar>=0:${PORTSDIR}/archivers/rubygem-minitar \
		rubygem-thor>=0:${PORTSDIR}/devel/rubygem-thor

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/blimpy

.include <bsd.port.mk>
