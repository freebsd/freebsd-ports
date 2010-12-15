# Ports collection makefile for:	rubygem-sys-admin
# Date created:				30 July 2010
# Whom:					Eric Freeman <freebsdports@chillibear.com>
#
# $FreeBSD$
#

PORTNAME=	sys-admin
PORTVERSION=	1.5.4
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	freebsdports@chillibear.com
COMMENT=	Unified, cross platform replacement for the Etc module

RUN_DEPENDS=	rubygem-test-unit>=2.0.3:${PORTSDIR}/devel/rubygem-test-unit

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=	umpt.h has been removed
.endif

.include <bsd.port.post.mk>
