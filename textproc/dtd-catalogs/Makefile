# New ports collection makefile for:	dtd-catalogs
# Version required:	1.0
# Date created:		23 January 1999
# Whom:			shige
#
# $Id$
#

DISTNAME=	dtd-catalogs-1.0
CATEGORIES=	textproc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	shige@kuis.kyoto-u.ac.jp

RUN_DEPENDS=	${ISO8879_CAT}:${PORTSDIR}/textproc/iso8879 \
		${ISO12083_CAT}:${PORTSDIR}/textproc/iso12083 \
		${HTML_CAT}:${PORTSDIR}/textproc/html \
		${DOCBOOK3_CAT}:${PORTSDIR}/textproc/docbook \
		${LINUXDOC_CAT}:${PORTSDIR}/textproc/linuxdoc

ISO8879_CAT=	${LOCALBASE}/share/sgml/iso8879/catalog
ISO12083_CAT=	${LOCALBASE}/share/sgml/iso12083/catalog
HTML_CAT=	${LOCALBASE}/share/sgml/html/catalog
DOCBOOK2_CAT=	${LOCALBASE}/share/sgml/docbook/2.4.1/catalog
DOCBOOK3_CAT=	${LOCALBASE}/share/sgml/docbook/3.0/catalog
LINUXDOC_CAT=	${LOCALBASE}/share/sgml/linuxdoc/catalog

ALL_CATALOGS=	${ISO8879_CAT} ${ISO12083_CAT} ${HTML_CAT} \
		${DOCBOOK2_CAT} ${DOCBOOK3_CAT} ${LINUXDOC_CAT}

CATALOG=	${LOCALBASE}/share/sgml/catalog

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

do-install:	# empty
	@([ -f ${CATALOG} ] && ${MV} ${CATALOG} ${CATALOG}.orig; \
	  ${TOUCH} ${CATALOG}; \
	  for i in ${ALL_CATALOGS}; do \
	  	${ECHO} "CATALOG \"$${i}\"" >> ${CATALOG}; \
	  done)

.include <bsd.port.mk>
