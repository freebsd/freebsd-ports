# New ports collection makefile for:   bchunk
# Version required:    		1.0.0
# Date created:                	9 Jan 1999
# Whom:                        	bsdx
#
# $Id:$
#

DISTNAME=	bchunk-1.0.0
CATEGORIES=	sysutils
MASTER_SITES=	http://hes.iki.fi/bchunk/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= utils/disk-management/

MAINTAINER=	ports@FreeBSD.ORG

ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bchunk ${PREFIX}/bin

.include <bsd.port.mk>
