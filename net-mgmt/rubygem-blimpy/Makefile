# New ports collection makefile for:	rubygem-blimpy
# Date created:		2012-08-05
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	blimpy
PORTVERSION=	0.4.3
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tool for managing a fleet of machines in the cloud

RUN_DEPENDS=	rubygem-fog>=0:${PORTSDIR}/devel/rubygem-fog \
		rubygem-minitar>=0:${PORTSDIR}/archivers/rubygem-minitar \
		rubygem-thor>=0:${PORTSDIR}/devel/rubygem-thor

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/blimpy

.include <bsd.port.mk>
