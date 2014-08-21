# Created by: Dan Langille <dan@langille.org>
# $FreeBSD$

PORTNAME=	bacula
PORTVERSION=	7.0.3
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMESUFFIX=	-docs
DISTFILES=	${PORTNAME}-docs-${PORTVERSION}.tar.bz2

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Bacula document set

NO_BUILD=	yes

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

PORTDOCS=	*.pdf

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOCS)
IGNORE=		consists of only documentation, please enable DOCS and try again
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}

	${FIND} ${WRKDIR}/${PORTNAME}-docs-${PORTVERSION}/manuals/en \
		-name "*.pdf" -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/ \;

.include <bsd.port.mk>
