# New ports collection makefile for:	dtd-catalogs
# Date created:		23 January 1999
# Whom:			shige
#
# $FreeBSD$
#

PORTNAME=	dtd-catalogs
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	shige@FreeBSD.org

RUN_DEPENDS=	${ISO8879_CAT}:${PORTSDIR}/textproc/iso8879 \
		${ISO12083_CAT}:${PORTSDIR}/textproc/iso12083 \
		${HTML_CAT}:${PORTSDIR}/textproc/html \
		${DOCBOOK_CAT}:${PORTSDIR}/textproc/docbook \
		${LINUXDOC_CAT}:${PORTSDIR}/textproc/linuxdoc

# DOCBOOK_CAT catalog is only for dependency.
DOCBOOK_CAT=	${LOCALBASE}/share/sgml/docbook/catalog

# The following catalogs are listed in catalog-list-file actually.
ISO8879_CAT=	${LOCALBASE}/share/sgml/iso8879/catalog
ISO12083_CAT=	${LOCALBASE}/share/sgml/iso12083/catalog
HTML_CAT=	${LOCALBASE}/share/sgml/html/catalog
DOCBOOK241_CAT=	${LOCALBASE}/share/sgml/docbook/2.4.1/catalog
DOCBOOK300_CAT=	${LOCALBASE}/share/sgml/docbook/3.0/catalog
DOCBOOK310_CAT=	${LOCALBASE}/share/sgml/docbook/3.1/catalog
DOCBOOK400_CAT=	${LOCALBASE}/share/sgml/docbook/4.0/catalog
DOCBOOK410_CAT=	${LOCALBASE}/share/sgml/docbook/4.1/catalog
LINUXDOC_CAT=	${LOCALBASE}/share/sgml/linuxdoc/catalog
JADE_CAT=	${LOCALBASE}/share/sgml/jade/catalog

ALL_CATALOGS=	${ISO8879_CAT} ${ISO12083_CAT} ${HTML_CAT} \
		${DOCBOOK241_CAT} ${DOCBOOK300_CAT} ${DOCBOOK310_CAT} \
		${DOCBOOK400_CAT} ${DOCBOOK410_CAT} ${LINUXDOC_CAT}

CATALOG=	${LOCALBASE}/share/sgml/catalog

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install:	# empty
	@[ -f ${CATALOG} ] && ${MV} ${CATALOG} ${CATALOG}.orig || ${TRUE}
	@${TOUCH} ${CATALOG};
	@for i in ${ALL_CATALOGS}; do \
		${ECHO} "CATALOG \"$${i}\"" >> ${CATALOG}; \
	  done;
	@[ -f ${JADE_CAT} ] && ${ECHO} "CATALOG \"${JADE_CAT}\"" >> \
		${CATALOG} || ${TRUE}

.include <bsd.port.mk>
