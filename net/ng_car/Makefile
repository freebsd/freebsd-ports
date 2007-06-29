# New ports collection makefile for:	ng_car
# Date Created:				Sep 26, 2005
# Whom:					Nuno Antunes <nuno.antunes@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ng_car
PORTVERSION=	0.4
CATEGORIES=	net kld
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	mpd

MAINTAINER=	mav@alkar.net
COMMENT=	Netgraph committed access rate node

NO_PACKAGE=	Should be in sync with the kernel to work correctly

PLIST_SUB=	KMODDIR=${KMODDIR}

MAN4=		ng_car.4
MANCOMPRESSED=	yes

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=	This port requires kernel sources
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700041
IGNORE=	"Already exists in base system"
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
