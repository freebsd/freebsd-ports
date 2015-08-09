# Created by: Alonso CArdenas <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bareos
PORTVERSION=	15.2
CATEGORIES=	sysutils
MASTER_SITES=	http://doc.bareos.org/master/
PKGNAMESUFFIX=	-docs
DISTFILES=	${PORTNAME}-manual-main-reference.pdf

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Bareos document set (PDF)

NO_BUILD=	yes

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

PORTDOCS=	*.pdf

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOCS)
IGNORE=		consists of only documentation, please enable DOCS and try again
.endif

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${PORTNAME}-manual-main-reference.pdf ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-manual-main-reference.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
