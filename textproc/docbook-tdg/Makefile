# New ports collection makefile for:	docbook-tdg
# Date created:		24 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	docbook-tdg
PORTVERSION=	2.0.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/tdg/en/
DISTNAME=	tdg-en-html-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

USE_REINPLACE=	yes
USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/tdg/en
CPIO=		cpio --quiet -pdum -R

post-patch:
	@ ${REINPLACE_CMD} -E -e \
	   's#file:/share/projects/sourceforge/docbook/defguide/(glyphs/100dpi/)#../\1#g' \
	  ${WRKSRC}/html/*.html
# XXX - hack due to REINPLACE_CMD
	@ ${RM} -f ${WRKSRC}/html/*.html.bak

do-install:
	@ ${MKDIR} ${DOCSDIR}
	@ cd ${WRKSRC} && find * \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@ ${INSTALL_DATA} ${FILESDIR}/index.html ${DOCSDIR}

.include <bsd.port.mk>
