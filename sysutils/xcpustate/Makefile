# New ports collection makefile for:	xcpustate
# Version required:	2.1
# Date created:		31-Dec-1995
# Whom:                 David O'Brien <obrien@cs.ucdavis.edu>
#
# $Id$
#

DISTNAME=	xcpustate-2.1
CATEGORIES+=	sysutils
MASTER_SITES=	ftp://ftp.cdf.toronto.edu/pub/xcpustate/  \
		ftp://ftp.x.org/contrib/utilities/xcpustate/
EXTRACT_SUFX=	.shar.gz

MAINTAINER=     obrien@cs.ucdavis.edu

EXTRACT_CMD=	zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
USE_IMAKE=	yes
NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
