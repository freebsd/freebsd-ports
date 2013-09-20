# Created by: mm
# $FreeBSD$

PORTNAME=	cciss_vol_status
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/cciss/${PORTNAME}

MAINTAINER=	fw@moov.de
COMMENT=	Reports status of logical drives on ciss(4) controllers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

MAN8=		cciss_vol_status.8
PLIST_FILES=	bin/cciss_vol_status etc/periodic/daily/cciss_vol_status
PLIST_DIRS=	etc/periodic/daily etc/periodic
SUB_FILES=	cciss_vol_status

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/dev/ciss/cissio.h)
IGNORE=		cciss_vol_status requires kernel sources of the ciss driver
.endif

post-install:
	${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/cciss_vol_status ${PREFIX}/etc/periodic/daily/cciss_vol_status

.include <bsd.port.post.mk>
