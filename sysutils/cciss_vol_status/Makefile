# Created by: mm
# $FreeBSD$

PORTNAME=	cciss_vol_status
PORTVERSION=	1.12
CATEGORIES=	sysutils
MASTER_SITES=	SF/cciss/${PORTNAME}

MAINTAINER=	fw@moov.de
COMMENT=	Reports status of logical drives on ciss(4) controllers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/cciss_vol_status etc/periodic/daily/cciss_vol_status man/man8/cciss_vol_status.8.gz
SUB_FILES=	cciss_vol_status

.if !exists(${SRC_BASE}/sys/dev/ciss/cissio.h)
IGNORE=		cciss_vol_status requires kernel sources of the ciss driver
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/cciss_vol_status ${STAGEDIR}${PREFIX}/etc/periodic/daily/cciss_vol_status

.include <bsd.port.mk>
