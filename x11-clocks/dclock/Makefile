# New ports collection makefile for:	dclock
# Version required:	pl4
# Date created:		15 Aug 1996
# Whom:			David Leonard <leonard@dstc.edu.au>
#
# $Id$
#

DISTNAME=	dclock
PKGNAME=	dclock-pl4
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.ucs.ubc.ca/pub/old/X11/contrib/ \
		ftp://pdq.coe.montana.edu/pub/mirrors/X11-contrib/ \
		ftp://ftp.pasteur.fr/pub/computing/unix/X11/R5contrib/
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	ports@FreeBSD.ORG

EXTRACT_CMD=		gzip 
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	|sh -
NO_WRKSUBDIR=		yes
ALL_TARGET=		dclock

.include <bsd.port.mk>
