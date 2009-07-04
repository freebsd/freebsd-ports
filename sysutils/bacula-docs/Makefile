# New ports collection makefile for:	bacula
# Date created:				4 January 2006
# Whom:					Dan Langille <dan@langille.org>
#
# $FreeBSD$
#

PORTNAME=	bacula
PORTVERSION=	3.0.1
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMESUFFIX=	-docs
DISTFILES=	${PORTNAME}-docs-${PORTVERSION}.tar.bz2 ${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	dan@langille.org
COMMENT=	The Bacula document set

NO_BUILD=	YES

CONFLICTS=	bacula-server-devel[0-9]* bacula-client-devel[0-9]* bacula-docs-devel-[0-9]*

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

PORTDOCS=	*

.ifdef NOPORTDOCS
IGNORE=		consists of only documentation, please undef NOPORTDOCS and try again
.endif

do-install:
	${MKDIR} ${DOCSDIR}

	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/ReleaseNotes \
		${WRKDIR}/${PORTNAME}-${PORTVERSION}/kernstodo \
		${DOCSDIR}/

	${FIND} ${WRKDIR}/${PORTNAME}-docs-${PORTVERSION}/manuals/en \
		-name "*.pdf" -exec ${INSTALL_DATA} {} ${DOCSDIR}/ \;

.include <bsd.port.mk>
