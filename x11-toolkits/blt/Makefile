# New ports collection makefile for:	blt
# Version required:	2.1
# Date created:		3 August 1996
# Whom:			lukin <lukin@okbmei.msk.su>
#
# $Id: Makefile,v 1.8 1996/08/06 04:59:00 asami Exp $
#

DISTNAME=	blt-2.1
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/NEW/
DISTFILES=	BLT2.1.tar.gz

MAINTAINER=	lukin@okbmei.msk.su

LIB_DEPENDS=	tk41\\.:${PORTSDIR}/x11/tk41

WRKSRC=		${WRKDIR}/blt2.1
GNU_CONFIGURE=	yes

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib
.if !defined(NOMANCOMPRESS)
.for man in BLT barchart bgexec bitmap bltdebug busy dragdrop graph \
	htext spline table tile vector watch winop
	gzip -9nf ${PREFIX}/man/mann/${man}.n
.endfor
.endif

.include <bsd.port.mk>
