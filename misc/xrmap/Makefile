# New ports collection makefile for:	xrmap
# Date created:				25 Dec 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	xrmap
PORTVERSION=	2.29
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/data/ \
		ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/
DISTFILES=	${XRMAPFILE} ${DISTFILE} \
		pdfmaps-1.1.tar.gz ${CIAFILE}
EXTRACT_ONLY=	${XRMAPFILE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Map portions of the earth from a given longitude/latitude

USE_BZIP2=	yes
USE_IMAKE=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
XMKMF=		xmkmf

MAN1=		xrmap.1

CIAFILE=	CIA_WDB2.jpd.gz
XRMAPFILE=	xrmap-${PORTVERSION}.tar.bz2
DISTFILE=	anthems-1.1.tar.bz2 \
		factbook_text_2002.tar.bz2 factbook_html_2002.tar.bz2 \
		flags-1.1.tar.bz2 hymns-1.2.tar.bz2

post-extract:
	for f in ${DISTFILE}; do \
	${TAR} -jxf ${DISTDIR}/$${f} -C ${WRKSRC}; \
	done
	${TAR} -zxf ${DISTDIR}/pdfmaps-1.1.tar.gz -C ${WRKSRC}
	${GUNZIP_CMD} -c ${DISTDIR}/${CIAFILE} >${WRKSRC}/CIA_WDB2.jpd

do-configure:
	cd ${WRKSRC}; ${XMKMF}; cd ${WRKSRC}/editkit; ${XMKMF}

post-configure:
	${REINPLACE_CMD} -e 's,/usr/X11R6,${X11BASE},g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,/usr/X11R6,${X11BASE},g' ${WRKSRC}/editkit/Makefile

.include <bsd.port.mk>
