# New ports collection makefile for:	dtd-catalogs
# Date created:		23 January 1999
# Whom:			shige
#
# $FreeBSD$
#

PORTNAME=	dtd-catalogs
PORTVERSION=	1.2
CATEGORIES=	textproc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SGML DTDs catalogs

RUN_DEPENDS=	${ISO8879_CAT}:${PORTSDIR}/textproc/iso8879 \
		${ISO12083_CAT}:${PORTSDIR}/textproc/iso12083 \
		${HTML_CAT}:${PORTSDIR}/textproc/html \
		${DOCBOOK_CAT}:${PORTSDIR}/textproc/docbook \
		${LINUXDOC_CAT}:${PORTSDIR}/textproc/linuxdoc

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

# The following catalogs are listed in catalog-list-file actually.
ISO8879_CAT=	${LOCALBASE}/share/sgml/iso8879/catalog
ISO12083_CAT=	${LOCALBASE}/share/sgml/iso12083/catalog
HTML_CAT=	${LOCALBASE}/share/sgml/html/catalog
DOCBOOK_CAT=	${LOCALBASE}/share/sgml/docbook/catalog
LINUXDOC_CAT=	${LOCALBASE}/share/sgml/linuxdoc/catalog

do-install:	#empty

.include <bsd.port.mk>
