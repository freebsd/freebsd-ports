# New ports collection makefile for:	xcpustate
# Version required:	2.1
# Date created:		31-Dec-1995
# Whom:                 David O'Brien <obrien@cs.ucdavis.edu>
#
# $Id: Makefile,v 1.4 1996/12/08 06:16:15 obrien Exp $
#

DISTNAME=	xcpustate-2.2beta
PKGNAME=	xcpustate-2.2b
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.cdf.toronto.edu/pub/xcpustate/  \
		ftp://ftp.vector.co.za/pub/FAQS/FAQs/mirrors/ftp.cdf.toronto.edu/xcpustate/  \
		ftp://ftp.csie.nctu.edu.tw/Vendors/sun/sun-faq/FAQs/mirrors/ftp.cdf.toronto.edu/xcpustate/  \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities/xcpustate
EXTRACT_SUFX=	.shar.gz

MAINTAINER=     obrien@cs.ucdavis.edu

EXTRACT_CMD=	zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
USE_IMAKE=	yes
NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
