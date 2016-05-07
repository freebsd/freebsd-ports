# Created by: shige
# $FreeBSD$

PORTNAME=	dtd-catalogs
PORTVERSION=	1.2
CATEGORIES=	textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SGML DTDs catalogs

RUN_DEPENDS=	${ISO8879_CAT}:textproc/iso8879 \
		${ISO12083_CAT}:textproc/iso12083 \
		${HTML_CAT}:textproc/html \
		${LINUXDOC_CAT}:textproc/linuxdoc

USES=		metaport

# The following catalogs are listed in catalog-list-file actually.
ISO8879_CAT=	${LOCALBASE}/share/sgml/iso8879/catalog
ISO12083_CAT=	${LOCALBASE}/share/sgml/iso12083/catalog
HTML_CAT=	${LOCALBASE}/share/sgml/html/catalog
LINUXDOC_CAT=	${LOCALBASE}/share/sgml/linuxdoc/catalog

.include <bsd.port.mk>
