# ex:ts=8
# New ports collection makefile for:	xcpustate
# Version required:	2.1
# Date created:		31-Dec-1995
# Whom:                 David O'Brien <obrien@cs.ucdavis.edu>
#
# $Id: Makefile,v 1.11 1998/03/06 01:58:14 obrien Exp $
#

DISTNAME=	xcpustate-2.5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/jdd/xcpustate/  \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities
EXTRACT_SUFX=	.shar

MAINTAINER=     obrien@FreeBSD.org

EXTRACT_CMD=	cat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
USE_IMAKE=	yes
NO_WRKSUBDIR=	yes

MAN1=		xcpustate.1

.include <bsd.port.mk>
