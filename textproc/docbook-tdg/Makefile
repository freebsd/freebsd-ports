# New ports collection makefile for:	docbook-tdg
# Date created:		24 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	docbook-tdg
PORTVERSION=	2.0.3
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/tdg/en/
DISTNAME=	tdg-en-html-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/tdg/en
CPIO=		cpio --quiet -pdum -R

do-install:
	@ ${MKDIR} ${DOCSDIR}
	@ cd ${WRKSRC} && find * \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@ cd ${DOCSDIR}/html/figures && ${LN} -s . 100dpi
	@ ${INSTALL_DATA} ${FILESDIR}/index.html ${DOCSDIR}

.include <bsd.port.mk>
