# New ports collection makefile for:	xsysinfo
# Version required:	1.3
# Date created:		4 April 1996
# Whom:			jdli
#
# $Id: Makefile,v 1.3 1996/10/30 14:05:20 jfitz Exp $
#

DISTNAME=	xsysinfo-1.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://freebsd.csie.nctu.edu.tw/pub/jdli/source/

MAINTAINER=	jdli@csie.nctu.edu.tw

USE_IMAKE=	yes

post-install:
.if defined(NOMANCOMPRESS)
		gunzip ${PREFIX}/man/man1/xsysinfo.1.gz
.endif

.include <bsd.port.mk>
