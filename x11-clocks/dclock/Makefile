# New ports collection makefile for:	dclock
# Version required:	pl4
# Date created:		15 Aug 1996
# Whom:			David Leonard <leonard@dstc.edu.au>
#
# $FreeBSD$
#

DISTNAME=	dclock
PKGNAME=	dclock-pl4
CATEGORIES=	x11-clocks
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
MAN1=		dclock.1
MANCOMPRESSED=	yes

EXTRACT_CMD=		${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	|sh -
NO_WRKSUBDIR=		yes
ALL_TARGET=		dclock

.include <bsd.port.mk>
