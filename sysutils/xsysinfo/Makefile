# New ports collection makefile for:	xsysinfo
# Date created:		4 April 1996
# Whom:			jdli
#
# $FreeBSD$
#

PORTNAME=	xsysinfo
PORTVERSION=	1.4a
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://freebsd.csie.nctu.edu.tw/pub/jdli/source/

MAINTAINER=	jdli@csie.nctu.edu.tw
COMMENT=	A system information display tool

USE_IMAKE=	yes
MANCOMPRESSED=	yes
MAN1=		xsysinfo.1
PLIST_FILES=	bin/xsysinfo

pre-configure:
	if [ -e /usr/lib/libdevstat.a -o -e /usr/lib/aout/libdevstat.a ]; then \
		cd ${WRKSRC} ; \
		${MV} Imakefile Imakefile.in ; \
		${SED} -e "s:DEFINES =:DEFINES = -DHAVE_DEVSTAT:" Imakefile.in > Imakefile.i1 ; \
		${SED} -e "s:-lkvm:-lkvm -ldevstat:" Imakefile.i1 > Imakefile ; \
	fi

.include <bsd.port.mk>
