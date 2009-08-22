# New ports collection makefile for:	ng_car
# Date Created:				Sep 26, 2005
# Whom:					Nuno Antunes <nuno.antunes@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ng_car
PORTVERSION=	0.6
CATEGORIES=	net kld
MASTER_SITES=	SF/mpd/misc/${PORTNAME}-${PORTVERSION}

MAINTAINER=	mav@FreeBSD.org
COMMENT=	Netgraph committed access rate node

NO_PACKAGE=	Should be in sync with the kernel to work correctly

KMODDIR?=	/boot/modules
PLIST_SUB=	KMODDIR=${KMODDIR}
MAKE_ENV+=	KMODDIR="${KMODDIR}"

MAN4=		ng_car.4
MANCOMPRESSED=	yes

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=	this port requires kernel sources
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700041
IGNORE=	already exists in base system
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
