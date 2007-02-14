# New ports collection makefile for:	bacula
# Date created:				4 January 2006
# Whom:					Dan Langille <dan@langille.org>
#
# $FreeBSD$
#

PORTNAME=	bacula
PORTVERSION=	2.0.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bacula
PKGNAMESUFFIX=	-docs
DISTFILES=	${PORTNAME}-docs-${PORTVERSION}.tar.gz ${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	dan@langille.org
COMMENT=	The Bacula document set

NO_BUILD=	YES

CONFLICTS=	bacula-server-devel[0-9]* bacula-client-devel[0-9]* bacula-docs-devel-[0-9]*

UNIQUENAME=${PORTNAME}${PKGNAMESUFFIX}

PORTDOCS=	ReleaseNotes bacula.pdf developers.pdf kernstodo manual bacula-web

do-install:
# Documentation is only installed in -client port
	for na in manual bacula-web; do \
		${MKDIR} ${DOCSDIR}/$$na ;\
		cd ${WRKDIR}/${PORTNAME}-docs-${PORTVERSION} && ${FIND} $$na | \
			${CPIO} -pdm -L -R root:wheel ${DOCSDIR}; \
	done
	@${CP} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/ReleaseNotes ${DOCSDIR}
	@${CP} ${WRKDIR}/${PORTNAME}-docs-${PORTVERSION}/manual/bacula.pdf ${DOCSDIR}
	@${CP} ${WRKDIR}/${PORTNAME}-docs-${PORTVERSION}/developers/developers.pdf ${DOCSDIR}
	@${CP} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/kernstodo ${DOCSDIR}

.include <bsd.port.mk>
