# ex:ts=8
# New ports collection makefile for:	xcpustate
# Version required:	2.1
# Date created:		31-Dec-1995
# Whom:                 David O'Brien <obrien@cs.ucdavis.edu>
#
# $Id: Makefile,v 1.10 1998/02/01 22:49:26 fenner Exp $
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

.include <bsd.port.mk>
