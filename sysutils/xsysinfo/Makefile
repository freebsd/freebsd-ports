# New ports collection makefile for:	xsysinfo
# Version required:	1.3
# Date created:		4 April 1996
# Whom:			jdli
#
# $Id: Makefile,v 1.2 1996/05/27 02:21:12 asami Exp $
#

DISTNAME=	xsysinfo-1.3
CATEGORIES+=	sysutils
MASTER_SITES=	ftp://freebsd.csie.nctu.edu.tw/pub/jdli/source/

MAINTAINER=	jdli@csie.nctu.edu.tw

USE_IMAKE=	yes

post-install:
.if defined(NOMANCOMPRESS)
		gunzip ${PREFIX}/man/man1/xsysinfo.1.gz
.endif

.include <bsd.port.mk>
