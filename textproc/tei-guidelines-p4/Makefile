# New ports collection makefile for:	tei-guidelines
# Date created:				29 April 2002
# Whom:	      				Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	tei
PORTVERSION=	p4
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Guidelines2/
PKGNAMESUFFIX=	-guidelines
DISTNAME=	p4html

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TEI's Guidelines for Electronic Text Encoding and Interchange

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/TEI_P4
LATEST_LINK=	tei-guidelines-p4
DOCSDIR=	${PREFIX}/share/doc/tei/p4

do-install:
	cd ${WRKSRC} && \
		${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	cd ${WRKSRC} && \
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;

.include <bsd.port.mk>
