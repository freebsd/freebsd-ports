# New ports collection makefile for:	dclock
# Version required:	pl4
# Date created:		15 Aug 1996
# Whom:			David Leonard <leonard@dstc.edu.au>
#
# $Id: Makefile,v 1.3 1998/05/03 17:54:39 steve Exp $
#

DISTNAME=	dclock
PKGNAME=	dclock-pl4
CATEGORIES=	x11-clock
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	ports@FreeBSD.ORG

EXTRACT_CMD=		${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	|sh -
NO_WRKSUBDIR=		yes
ALL_TARGET=		dclock

.include <bsd.port.mk>
