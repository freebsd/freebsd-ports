# Created by: Michael Reifenberger
# $FreeBSD$

PORTNAME=	gstopd
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mr

MAINTAINER=	mr@FreeBSD.org
COMMENT=	GEOM stop daemon

MAN8=		gstopd.8
PLIST_FILES=	sbin/gstopd

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gstopd ${LOCALBASE}/sbin
	${INSTALL_MAN} ${WRKSRC}/gstopd.8 ${LOCALBASE}/man/man8

.include <bsd.port.mk>
