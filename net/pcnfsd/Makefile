# New ports collection makefile for:	pcnfsd
# Version required:	93.02.16
# Date created:		Oct 6, 1994
# Whom:			pst
#
# $FreeBSD$
#

DISTNAME=	pcnfsd.93.02.16
PKGNAME=	pcnfsd-93.02.16
CATEGORIES=	net
MASTER_SITES=	ftp://bcm.tmc.edu/pcnfs/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

MAN8=		pcnfsd.8
MANCOMPRESSED=	maybe

NO_WRKSUBDIR=

post-extract:
	${CP} ${FILESDIR}/Makefile.inc ${WRKSRC}

.include <bsd.port.mk>
