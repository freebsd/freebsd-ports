# New ports collection makefile for:	mtx
# Date created:			26. November 2001
# Whom:				Martin Blapp <mb@imp.ch>
#
# $FreeBSD$
#

PORTNAME=	mtx
PORTVERSION=	1.2.17rel
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mtx

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	Control SCSI media changer devices

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		loaderinfo.1 mtx.1 tapeinfo.1 scsitape.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64" || ${ARCH} == "amd64"
BROKEN=		"Does not compile on ia64, sparc64 and amd64"
.endif

.include <bsd.port.post.mk>
