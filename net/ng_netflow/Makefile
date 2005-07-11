# New ports collection makefile for:	ng_netflow
# Date Created:				Feb 17, 2003
# Whom:					Gleb Smirnoff <glebius@cell.sick.ru>
#
# $FreeBSD$
#

PORTNAME=	ng_netflow
PORTVERSION=	0.2.5
CATEGORIES=	net
MASTER_SITES=	http://cell.sick.ru/~glebius/ng_netflow/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ng-netflow

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Netgraph node implementing Cisco (c) netflow

NO_PACKAGE=	Should be in sync with the kernel to work correctly

PLIST_SUB=	KMODDIR=${KMODDIR}

MAN4=		ng_netflow.4
MAN8=		flowctl.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 503101
IGNORE=		"already exists in base system"
.endif

pre-fetch:

.if !exists(${SRC_BASE}/sys/Makefile)
	IGNORE=		"This port requires kernel sources"
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
