# New ports collection makefile for:	xsysinfo
# Version required:	1.4
# Date created:		4 April 1996
# Whom:			jdli
#
# $Id: Makefile,v 1.6 1997/01/08 01:22:22 asami Exp $
#

DISTNAME=	xsysinfo-1.4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://freebsd.csie.nctu.edu.tw/pub/jdli/source/

MAINTAINER=	jdli@csie.nctu.edu.tw

USE_IMAKE=	yes
MANCOMPRESSED=	yes
MAN1=		xsysinfo.1

pre-configure:
	if [ -e /usr/lib/libdevstat.a ]; then \
		cd ${WRKSRC} ; \
		${MV} Imakefile Imakefile.in ; \
		${SED} -e "s:DEFINES =:DEFINES = -DHAVE_DEVSTAT:" Imakefile.in > Imakefile.i1 ; \
		${SED} -e "s:-lkvm:-lkvm -ldevstat:" Imakefile.i1 > Imakefile ; \
	fi

.include <bsd.port.mk>
