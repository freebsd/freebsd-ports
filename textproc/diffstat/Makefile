# New ports collection makefile for:	diffstat
# Date created:		Oct 23, 1999
# Whom:			Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	diffstat
PORTVERSION=	1.33
CATEGORIES=	textproc devel
MASTER_SITES=	ftp://dickey.his.com/diffstat/
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Makes a histogram summarizing "diff" output

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
GNU_CONFIGURE=	yes

MAN1=		diffstat.1
PLIST_FILES=	bin/diffstat

.include <bsd.port.mk>
