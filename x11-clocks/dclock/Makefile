# New ports collection makefile for:	dclock
# Version required:	pl4
# Date created:		15 Aug 1996
# Whom:			David Leonard <leonard@dstc.edu.au>
#
# $Id: Makefile,v 1.2 1996/11/18 11:42:53 asami Exp $
#

DISTNAME=	dclock
PKGNAME=	dclock-pl4
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	ports@FreeBSD.ORG

EXTRACT_CMD=		${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	|sh -
NO_WRKSUBDIR=		yes
ALL_TARGET=		dclock

.include <bsd.port.mk>
