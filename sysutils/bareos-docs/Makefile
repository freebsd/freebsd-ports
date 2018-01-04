# Created by: Alonso CArdenas <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bareos
PORTVERSION=	16.2.7
CATEGORIES=	sysutils
MASTER_SITES=	http://doc.bareos.org/master/
PKGNAMESUFFIX=	-docs
DISTFILES=	${PORTNAME}-manual-main-reference.pdf

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Bareos document set (PDF)

NO_BUILD=	yes

PORTDOCS=	*.pdf

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${PORTNAME}-manual-main-reference.pdf ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-manual-main-reference.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
