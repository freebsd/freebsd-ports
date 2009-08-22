# New ports collection makefile for:    cciss_vol_status
# Date created:         7 Sep 2007
# Whom:			mm
#
# $FreeBSD$
#

PORTNAME=	cciss_vol_status
PORTVERSION=	1.03
CATEGORIES=	sysutils
MASTER_SITES=	SF/cciss/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Reports status of logical drives on ciss(4) controllers

GNU_CONFIGURE=	yes

MAN8=		cciss_vol_status.8
PLIST_FILES=	bin/cciss_vol_status

.if !exists(${SRC_BASE}/sys/dev/ciss/cissio.h)
IGNORE=		cciss_vol_status requires kernel sources of the ciss driver
.endif

.include <bsd.port.mk>
