# Created by: Dan Langille <dan@langille.org>
# $FreeBSD$

PORTNAME=	bacula
PORTVERSION=	5.2.12
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMESUFFIX=	5-docs
DISTFILES=	${PORTNAME}-docs-${PORTVERSION}.tar.bz2

CONFLICTS=	bacula-*

MAINTAINER=	dan@langille.org
COMMENT=	Bacula document set

NO_BUILD=	yes

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

PORTDOCS=	*.pdf

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:DOCS)
IGNORE=		consists of only documentation, please enable DOCS and try again
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${FIND} ${WRKDIR}/${PORTNAME}-docs-${PORTVERSION}/manuals/en \
		-name "*.pdf" -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/ \;

.include <bsd.port.mk>
